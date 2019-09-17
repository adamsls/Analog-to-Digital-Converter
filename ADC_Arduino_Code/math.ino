/******************************************************************
Filename      :maths

/*****************************************************************
*  Function    : CalculateVin
*  Returns     : void
*  Parameters  : int
*  Description : this function will determine the voltage on a 
*              : channel from the PWM high time
******************************************************************/
float CalculateVin(unsigned long thi){
  int num_steps =0;
  float v =0.0; 
  num_steps = thi/TCLK;
  v = num_steps * (VCC/256);
  return(v);
}
