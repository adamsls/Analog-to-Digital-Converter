/******************************************************************
Filename      :sketch_mar06a
Author        :Fergal Brennan
Course        :FLASHE Project
Description   :This is the main file for the FLAHSE project
******************************************************************/

/******************************************************************
CONSTANT DEFINITNIONS
******************************************************************/
const int TSIG1 =  13;      //TSIG1 is located on pin 13
const int PWMX  =   8;      //PWMX is located on pin 2
const int PWMY  =   7;      //PWMX is located on pin 7
const int PWMZ  =   2;      //PWMX is located on pin 8
float calibrated_x_0;
float calibrated_x_270;
float calibrated_x_90;
float calibrated_y_0_a;
float calibrated_y_0_b;
float calibrated_y_180;
float calibrated_z_0_a;
float calibrated_z_0_b;
float calibrated_z_180;
float x_g_force = 0;
float y_g_force = 0;
float z_g_force = 0;


//flag for continuous serial values
boolean cont_flag = false;

/******************************************************************
MEASUREMENT TYPE DEFINITNIONS
******************************************************************/
#define   THI       1         //State for THI measurement
#define   TLO       0         //State for TLO measurement
#define   TPWM      2         //State for PWM period measurement
#define   VPWM      3         //State for Channel input voltage
#define   GF        5         //State for G-force
#define   SHOW      4         //State for displaying the results
#define   DONE      9         //End of measurements state

/******************************************************************
PROJECT BOARD VALUES
******************************************************************/
#define   TRAMP     1422      //Period of ramp in usec. Specific to each board
#define   TCLK      5.55      //Period of board clk in usec. Specific to each board
#define   VCC       5.00      //Board 5V level. Specific to each board

/******************************************************************
VARIABLE DEFINITNIONS
******************************************************************/
byte i_valid_char           =0;    
char kbd_data               ='0';
byte b_tsig1_state          =LOW;   //Holds the state of TSIG1, i.e. high or low. We startup as low

byte pwm_x_measurement      =THI;   //Each ch has a t-low, t-high measurement, start at t-high
byte ok_to_measure_pwmx     =0;     //Flag that is asserted when we want to measure PWMX

byte pwm_y_measurement      =THI;   //Each ch has a t-low, t-high measuremen                                                                                                         t, start at t-high
byte ok_to_measure_pwmy     =0;     //Flag that is asserted when we want to measure PWMX

byte pwm_z_measurement      =THI;   //Each ch has a t-low, t-high measurement, start at t-high
byte ok_to_measure_pwmz     =0;     //Flag that is asserted when we want to measure PWMX



/******************************************************************
PWM X measurement variables - initialise to 0
******************************************************************/
unsigned long   pwm_x_thi     =0;
unsigned long   pwm_x_tlo     =0;
unsigned long   pwm_x_tpwm    =0;
double          pwm_x_vin     =0;
double          pwm_x_g       =0;

unsigned long   pwm_y_thi     =0;
unsigned long   pwm_y_tlo     =0;
unsigned long   pwm_y_tpwm    =0;
double          pwm_y_vin     =0;
double          pwm_y_g       =0;

unsigned long   pwm_z_thi     =0;
unsigned long   pwm_z_tlo     =0;
unsigned long   pwm_z_tpwm    =0;
double          pwm_z_vin     =0;
double          pwm_z_g       =0;

/*
All projects will have a setup part. This part of the code is where
you define what pins will be inputs, what pins will be outputs and 
how the Arduino will operate
*/
void setup() {
//Setup the serial port for this project
  Serial.begin(9600);

//Print a message to the screen
  SendWelcomeMessage();
  
//Setup pins that are outputs for this project  
//For this example we will set pin 13 as an output
  pinMode(TSIG1, OUTPUT); 
  pinMode(PWMX, INPUT);
  pinMode(PWMY, INPUT);
  pinMode(PWMZ, INPUT);
}


/*
All projects have a loop. The loop is the part of the code the operates 
indefinately. It is inside the loop where your project happens
*/
void loop() {
  
//Check to see if there is new data from the serial port
  kbd_data = GetChar();  
  
//If the valid character flag is asserted then new data has been read into the
//serial port. We then run the menu to find out what command it is. The valid
//flag is used so we only execute each command once.
  if(i_valid_char ==1){
    Decode(kbd_data);    
  }
  i_valid_char =0;

//If the x key on the kbd is pressed then we call the function that measures
//the values for PWMX
  if(ok_to_measure_pwmx == 1){
    
    MeasurePWMX(pwm_x_measurement);
    delay(100);                       //Wait for 100msec before continuing

    
    if(pwm_x_measurement == DONE){
      if(cont_flag == true) {
      pwm_x_measurement = THI;
      ok_to_measure_pwmx = 1;         //If we've measured everything then stop
    }
    else if (cont_flag == false){
       ok_to_measure_pwmx = 0;       
      }
    }
    
  }

    if(ok_to_measure_pwmy == 1){
    
    MeasurePWMY(pwm_y_measurement);
    delay(100);                       //Wait for 100msec before continuing
    
    if(pwm_y_measurement == DONE){
      if(cont_flag == true) {
      pwm_y_measurement = THI;
      ok_to_measure_pwmy = 1;         //If we've measured everything then stop
    }
    else if (cont_flag == false){
       ok_to_measure_pwmy = 0;       
      }        //If we've measured everything then stop
    }
    
  }

  if(ok_to_measure_pwmz == 1){
    
    MeasurePWMZ(pwm_z_measurement);
    delay(100);                       //Wait for 100msec before continuing
    
    if(pwm_z_measurement == DONE){
      if(cont_flag == true) {
      pwm_z_measurement = THI;
      ok_to_measure_pwmz = 1;         //If we've measured everything then stop
    }
    else if (cont_flag == false){
       ok_to_measure_pwmz = 0;       
      }        //If we've measured everything then stop
    }
    
  }

}
