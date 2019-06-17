/*
Filename      :comms
Author        :Fergal Brennan
Course        :FLASHE Project
Description   :This file holds the serial port
*/

/***********************************************
*  Function    : GetChar
*  Returns     : byte
*  Parameters  : void
*  Description : this function will receive a 
*              : character from the serial port
***********************************************/
char GetChar(void){
  if (Serial.available() > 0) {
     i_valid_char =1;
    return(Serial.read());
   
  }
  else{
    i_valid_char =0;
    return('\0');
    
  }
}
