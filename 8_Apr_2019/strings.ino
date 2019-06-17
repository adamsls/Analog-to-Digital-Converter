/*
Filename      :strings
Author        :Fergal Brennan
Course        :FLASHE Project
Description   :This file holds the string table for the project
*/

/***********************************************
*  Function    : ChannelHeader
*  Returns     : void
*  Parameters  : void
*  Description : this function will print header
*              : info to the screen
***********************************************/



void ChannelHeader(void){
  Serial.print("CH\t\t");
  Serial.print("THIGH\t\t");
  Serial.print("TLOW\t\t");
  Serial.print("TPWM\t\t");
  Serial.print("VIN\t\t");
  Serial.println("G FORCE");
}
/***********************************************
*  Function    : ShowPWMX
*  Returns     : void
*  Parameters  : thi,tlo,tpwm,voltage
*  Description : this function will print pwm x channel
*              : data to the screen
***********************************************/
void ShowPWMX(unsigned long thi, unsigned long tlo, unsigned long tpwm, double v, double x_g_force){
    Serial.print("X\t\t");
    Serial.print(thi);
    Serial.print("\t\t");
    Serial.print(tlo);
    Serial.print("\t\t");
    Serial.print(tpwm);
    Serial.print("\t\t");
    Serial.print(v);
    Serial.print("\t\t");
    Serial.println(x_g_force);
}

void ShowPWMY(unsigned long thi, unsigned long tlo, unsigned long tpwm, double v){
    Serial.print("Y\t\t");
    Serial.print(thi);
    Serial.print("\t\t");
    Serial.print(tlo);
    Serial.print("\t\t");
    Serial.print(tpwm);
    Serial.print("\t\t");
    Serial.print(v);
    Serial.println("");
}

void ShowPWMZ(unsigned long thi, unsigned long tlo, unsigned long tpwm, double v){
    Serial.print("Z\t\t");
    Serial.print(thi);
    Serial.print("\t\t");
    Serial.print(tlo);
    Serial.print("\t\t");
    Serial.print(tpwm);
    Serial.print("\t\t");
    Serial.print(v);
    Serial.println(""); 
}
/***********************************************
*  Function    : PrintMenu
*  Returns     : void
*  Parameters  : void
*  Description : this function will print the user
*              : menu to the screen
***********************************************/
void PrintMenu(void){
  Serial.println("Press 'f' to calibrate (note G-force values unavailable without calibration)");
  Serial.println("Press 't' to toggle the TSIG1");
  Serial.println("Press 'v' to view this menu"); 
  Serial.println("Press 'x' to measure Channel X");
  Serial.println("Press 'y' to measure Channel Y");
  Serial.println("Press 'z' to measure Channel Z");
  Serial.println("Press 'a' to measure all channels");
  Serial.println("Press 'c' to toggle all channels continuously");

}


/***********************************************
*  Function    : SendWelcomeMessage
*  Returns     : void
*  Parameters  : void
*  Description : this function will print user
*              : date and menu to the screen
***********************************************/
void SendWelcomeMessage(void){
  Serial.println("=====================================");
  Serial.println("-------- FLASHE Project 2019 --------");
  Serial.println("=====================================");
  PrintMenu();
  Serial.println("=====================================");
}
