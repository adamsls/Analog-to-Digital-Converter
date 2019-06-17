
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
    Serial.println(average_val);
    return average_val;

  }
  
  float convert_to_g(float Vin, float max_g, float min_g) {

    //find equation of the line:

    //find slope:
    Serial.println(max_g);
    Serial.println(min_g);
    Serial.println(Vin);

    float slope = 2 / (max_g - min_g);

    //find intercept
    float intercept = 1 - (slope * max_g);
    
    float g_force = (Vin * slope) + intercept;

    return (g_force);
    }
