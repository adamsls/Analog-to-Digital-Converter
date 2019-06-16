
//function to calibrate the board by taking multiple initial measurements and averaging

float Calibrate (int channel) {
  
  float current_val = 0;
  float final_val = 0;
  float average_val = 0;
  
  for (int i = 0; i < 10; i++){
    
     float Vin = ReadPulse(channel,HIGH);
     current_val = CalculateVin(Vin);
     final_val += current_val;
  }

    average_val = final_val/10;
    return average_val;

  }

  float convert_to_g(float Vin) {

    float max_volt = 3.3;
    float min_volt = 0.0;
    float volt_range = max_volt - min_volt;
    float g_max = 3.0;
    float g_min = -3.0;
    float g_range = g_max - g_min;
    float g_force = g_min + (((Vin - min_volt)*g_range)/volt_range);

    if (Vin > max_volt) {
      Serial.println("Error");
      }
    return (g_force);
    }
