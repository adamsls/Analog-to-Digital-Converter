

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

  float convert_to_g(float Vin, float cal_180, float cal_90) {


    float g_range = cal_180 - cal_90;
    g_force = Vin * g_range;

    return (g_force);
    }
