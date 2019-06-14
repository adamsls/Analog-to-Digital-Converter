

float Calibrate (int channel) {
  
  float current_val = 0;
  float final_val = 0;
  float average_val = 0;
  for (int i = 0; i<10; i++){
     float Vin = ReadPulse(channel,HIGH);
     current_val = CalculateVin(Vin);
     final_val += current_val;
     average_val = final_val/10;
      
  }
    return average_val;

  }

  float convert_to_g(float Vin, float cal_90, float cal_270) {

    float a = Vin - cal_90;
    Serial.println(a);
    float b = cal_270 - cal_90;
    Serial.println(b);
    float c = a / b;
    Serial.println(c);
    float g_force = c - 1;
    Serial.println(g_force);
    
    //float g_force = 2((Vin - cal_0)/(cal_270 - cal_0)) - 1;


    return (g_force);
    }
