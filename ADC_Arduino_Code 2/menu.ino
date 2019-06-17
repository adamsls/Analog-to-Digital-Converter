/**************************************************************************
Filename      :menu
Author        :Fergal Brennan
Course        :FLASHE Project
Description   :This file holds the menu for the command line interface
**************************************************************************/

/*************************************************************************
*  Function    : RunMenu
*  Returns     : void
*  Parameters  : byte, command to be executed
*  Description : this function will decode the incoming byte from the 
*              : keyboard and take the appropriate action
*************************************************************************/


void Decode(char cmd){

//Decode the character received from the keyboard  
  switch(cmd){
    
//If the character was an 'm' then print the menu
    case 'm':
      PrintMenu();
    break;

//If the character was a '1' then toggle the TSIG1 pin. 
//If the pin was low, then we make it high. The pins state 
//is stored in the variable 'b_tsig1_state'
    case 't':
      if(b_tsig1_state == LOW){
        b_tsig1_state = HIGH;  
        Serial.println("TSIG1 is high");
      }
      else{
        b_tsig1_state = LOW;  
        Serial.println("TSIG1 is low");
      }
      digitalWrite(TSIG1,b_tsig1_state);
    break;
     
//If the character received was an 'x' then set the flag that will
//enable the PWMX channel to be measured
    case 'x':
      if(ok_to_measure_pwmx == 0){ 
        cont_flag = false;
        pwm_x_measurement = THI;
        ok_to_measure_pwmx = 1;
      }
      break;

    case 'y':
      if(ok_to_measure_pwmy == 0){
        cont_flag = false;
        pwm_y_measurement = THI;
        ok_to_measure_pwmy = 1;
      }
      break;

    case 'z':
      if(ok_to_measure_pwmz == 0){
        cont_flag = false;
        pwm_z_measurement = THI;
        ok_to_measure_pwmz = 1;
      }
      break;

    case 'a':
      pwm_x_measurement = THI;
      pwm_y_measurement = THI;
      pwm_z_measurement = THI;
      ok_to_measure_pwmx = 1;
      ok_to_measure_pwmy = 1;
      ok_to_measure_pwmz = 1;    
    
      break;
      
     case 'f':
      Serial.println("Measuring x-axis");
      Serial.println("Tilt board away by 90 degrees and press '1' to measure when ready");     
      break;     
      
    case '1': 
      calibrated_x_180 = Calibrate(PWMX);
      x_g_force = -1;
      Serial.print("180 degrees in x axis: ");
      Serial.print(calibrated_x_180);
      Serial.println("V");      
      Serial.print("G force: ");
      Serial.println(x_g_force);
      Serial.println("Tilt board forward by 90 degrees and press '2' to measure when ready");
      break;

   case '2': 
      calibrated_x_0 = Calibrate(PWMX);
      x_g_force = 1;
      Serial.print("0 degrees in x axis: ");
      Serial.print(calibrated_x_0);
      Serial.println("V");      
      Serial.print("G force: ");
      Serial.println(x_g_force);
      Serial.println("X-axis calibration completed");
      Serial.println("**********************************");
      Serial.println("Tilt board 90 degrees to the left and press '3' to begin calibration of y-axis");
      break;

   case '3': 
      calibrated_y_180 = Calibrate(PWMY);
      y_g_force = -1;
      Serial.print("180 degrees in y axis: ");
      Serial.print(calibrated_y_180);
      Serial.println("V");
      Serial.print("G force: ");
      Serial.println(y_g_force);
      Serial.println("Tilt board 90 degrees to the right and press '4' to measure when ready");
      break;

      case '4': 
      calibrated_y_0 = Calibrate(PWMY);
      y_g_force = 1;
      Serial.print("0 degrees in y axis: ");
      Serial.print(calibrated_y_0);
      Serial.println("V");
      Serial.print("G force: ");
      Serial.println(y_g_force);
      Serial.println("Y-axis calibration completed");
      Serial.println("**********************************");
      Serial.println("Place board upside down and press '5' to begin calibration of z-axis");
      break;

   case '5': 
      calibrated_z_180 = Calibrate(PWMZ);
      z_g_force = -1;
      Serial.print("180 degrees in z axis: ");
      Serial.print(calibrated_z_180);
      Serial.println("V");
      Serial.print("G force: ");
      Serial.println(z_g_force);
      Serial.println("Place board flat facing up and press '6' to measure when ready");
            break;

   case '6': 
      calibrated_z_0 = Calibrate(PWMZ);
      z_g_force = 1;      
      Serial.print("0 degrees in z axis: ");
      Serial.print(calibrated_z_0);
      Serial.println("V");
      Serial.print("G force: ");
      Serial.println(z_g_force);
      Serial.println("Z-axis calibration completed");
      Serial.println("**********************************");
      break; 
       
    case 'c':

        if (cont_flag == true) {
          Serial.println("stopping");
          cont_flag = false;
          }
          
          else if (cont_flag == false){
            cont_flag = true;
            pwm_x_measurement = THI;
            pwm_y_measurement = THI;
            pwm_z_measurement = THI;
            ok_to_measure_pwmx = 1;
            ok_to_measure_pwmy = 1;
            ok_to_measure_pwmz = 1; 
          }
        
       break;


  }//End of Switch

  
}
