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
      Serial.println("Place board flat and press '1' to measure when ready");     
      break;     
      
    case '1': 
      calibrated_x_0 = Calibrate(PWMX);
      x_g_force = 0;
      Serial.print("0 degrees: ");
      Serial.println(calibrated_x_0);
      Serial.print("G force: ");
      Serial.println(x_g_force);
      Serial.println("Place board sideways and press '2' to measure when ready");
      break;

   case '2': 
      calibrated_x_90 = Calibrate(PWMX);
      x_g_force = -1;
      Serial.print("180 degrees: ");
      Serial.println(calibrated_x_90);
      Serial.print("G force: ");
      Serial.println(x_g_force);
      Serial.println("Place board sideways in the other direction and press '3' to measure when ready");
      break;

   case '3': 
      calibrated_x_270 = Calibrate(PWMX);
      x_g_force = 1;
      Serial.print("360 degrees: ");
      Serial.println(calibrated_x_270);
      Serial.print("G force: ");
      Serial.println(x_g_force);
      Serial.println("X-axis calibration completed");
      Serial.println("**********************************");
      Serial.println("Press '4' and place board flat to begin calibration of y-axis");
      break;

      case '4': 
      calibrated_y_0_a = Calibrate(PWMY);
      Serial.print("0 degrees: ");
      Serial.println(calibrated_y_0_a);
      Serial.println("Place board sideways on y-axis and press '5' to measure when ready");
      break;

   case '5': 
      calibrated_y_180 = Calibrate(PWMY);
      Serial.print("180 degrees: ");
      Serial.println(calibrated_y_180);
      Serial.println("Place board flat in the other direction and press '6' to measure when ready");
      break;

   case '6': 
      calibrated_y_0_b = Calibrate(PWMY);
      Serial.print("360 degrees: ");
      Serial.println(calibrated_y_0_b);
      Serial.println("Y-axis calibration completed");
      Serial.println("**********************************");
      Serial.println("Press '7' and place board flat to begin calibration of z-axis");
      break; 

   case '7': 
      calibrated_z_0_a = Calibrate(PWMZ);
      Serial.print("0 degrees: ");
      Serial.println(calibrated_z_0_a);
      Serial.println("Lift board up and press '8' to measure when ready");
      break;

   case '8': 
      calibrated_z_180 = Calibrate(PWMZ);
      Serial.print("180 degrees: ");
      Serial.println(calibrated_z_180);
      Serial.println("Lift board up further and press '9' to measure when ready");
      break;

   case '9': 
      calibrated_z_0_b = Calibrate(PWMZ);
      Serial.print("360 degrees: ");
      Serial.println(calibrated_z_0_b);
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
