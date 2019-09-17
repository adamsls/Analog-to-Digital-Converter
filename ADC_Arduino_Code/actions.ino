/******************************************************************
Filename      :actions

/*****************************************************************
*  Function    : MeasurePWMX
*  Returns     : void
*  Parameters  : void
*  Description : this function will read and interpret the time
*              : and voltage parameters for PWMX
*****************************************************************/
void MeasurePWMX(byte cmd){

      switch(cmd){
        case THI:
          pwm_x_thi = ReadPulse(PWMX,HIGH);
          pwm_x_measurement = TLO;
          break;
        case TLO:
          pwm_x_tlo = ReadPulse(PWMX,LOW);
          pwm_x_measurement = TPWM;
          break;
        case TPWM:
          pwm_x_tpwm = pwm_x_thi + pwm_x_tlo;
          pwm_x_measurement = VPWM;
          break;
        case VPWM:
          pwm_x_vin = CalculateVin(pwm_x_thi);         
          pwm_x_measurement = GF;
          break;
        //determine G force values using function 'convert_to_g'
        case GF:
          x_g_force = convert_to_g(pwm_x_vin, calibrated_x_0, calibrated_x_180);         
          pwm_x_measurement = SHOW;
          break;
        case SHOW:
          ChannelHeader();         
          ShowPWMX(pwm_x_thi,pwm_x_tlo,pwm_x_tpwm,pwm_x_vin, x_g_force);
          pwm_x_measurement = DONE;
          break;
        case DONE:
          pwm_x_measurement = DONE;
          break;
      }
}

void MeasurePWMY(byte cmd){

      switch(cmd){
        case THI:
          pwm_y_thi = ReadPulse(PWMY,HIGH);
          pwm_y_measurement = TLO;
        case TLO:
          pwm_y_tlo = ReadPulse(PWMY,LOW);
          pwm_y_measurement = TPWM;
          break;
        case TPWM:
          pwm_y_tpwm = pwm_y_thi + pwm_y_tlo;
          pwm_y_measurement = VPWM;
          break;
        case VPWM:
          pwm_y_vin = CalculateVin(pwm_y_thi);         
          pwm_y_measurement = GF;
          break;
        //determine G force values using function 'convert_to_g'
        case GF:
          y_g_force = convert_to_g(pwm_y_vin, calibrated_y_0, calibrated_y_180);         
          pwm_y_measurement = SHOW;
          break;
        case SHOW:
          ChannelHeader();          
          ShowPWMY(pwm_y_thi,pwm_y_tlo,pwm_y_tpwm,pwm_y_vin, y_g_force);
          pwm_y_measurement = DONE;
          break;
        case DONE:
          pwm_y_measurement = DONE;
          break;
      }
}

void MeasurePWMZ(byte cmd){

      switch(cmd){
        case THI:
          pwm_z_thi = ReadPulse(PWMZ,HIGH);
          pwm_z_measurement = TLO;
        case TLO:
          pwm_z_tlo = ReadPulse(PWMZ,LOW);
          pwm_z_measurement = TPWM;
          break;
        case TPWM:
          pwm_z_tpwm = pwm_z_thi + pwm_z_tlo;
          pwm_z_measurement = VPWM;
          break;
        case VPWM:
          pwm_z_vin = CalculateVin(pwm_z_thi);         
          pwm_z_measurement = GF;
          break;
        //determine G force values using function 'convert_to_g'
        case GF:
          z_g_force = convert_to_g(pwm_z_vin, calibrated_z_0, calibrated_z_180);         
          pwm_z_measurement = SHOW;
          break;
        case SHOW:
          ChannelHeader();         
          ShowPWMZ(pwm_z_thi,pwm_z_tlo,pwm_z_tpwm,pwm_z_vin, z_g_force);
          pwm_z_measurement = DONE;
          break;
        case DONE:
          pwm_z_measurement = DONE;
          break;
      }
}
/*****************************************************************
*  Function    : ReadPulse
*  Returns     : pulse time in usec
*  Parameters  : the pin we want to read and the state
*  Description : this function read the high or low of the 
*              : specified pin
*****************************************************************/
unsigned long ReadPulse(int pin, int state){
  unsigned long t=0;
  
  t = pulseIn(pin, state);
  if (t < 20) {
     t = pulseIn(pin,state);    
  }

  return(t);
}
