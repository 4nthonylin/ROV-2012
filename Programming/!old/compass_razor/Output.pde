
void printdata(void)
{    
      Serial.write(0xAA);
/*
      #if PRINT_EULER == 1
      Serial.print("ANG:");
      Serial.print(ToDeg(roll));
      Serial.print(",");
      Serial.print(ToDeg(pitch));
      Serial.print(",");
      Serial.print(ToDeg(yaw));
      #endif      
      #if PRINT_ANALOGS==1
      Serial.print(",AN:");
      Serial.print(AN[sensors[0]]);  //(int)read_adc(0)
      Serial.print(",");
      Serial.print(AN[sensors[1]]);
      Serial.print(",");
      Serial.print(AN[sensors[2]]);  
      Serial.print(",");
      Serial.print(ACC[0]);
      Serial.print (",");
      Serial.print(ACC[1]);
      Serial.print (",");
      Serial.print(ACC[2]);
      Serial.print(",");
      Serial.print(magnetom_x);
      Serial.print (",");
      Serial.print(magnetom_y);
      Serial.print (",");
      Serial.print(magnetom_z);      
      #endif
      */
      int test = MAG_Degree;
        byte dataByte1 = test & B11111111;
  byte dataByte2 = (test >> 8) & B11111111;

 
    //  Serial.print(MAG_Heading);
    //  Serial.print(", ");
      Serial.write(dataByte1);
      Serial.write(dataByte2);
      /*#if PRINT_DCM == 1
      Serial.print (",DCM:");
      Serial.print(convert_to_dec(DCM_Matrix[0][0]));
      Serial.print (",");
      Serial.print(convert_to_dec(DCM_Matrix[0][1]));
      Serial.print (",");
      Serial.print(convert_to_dec(DCM_Matrix[0][2]));
      Serial.print (",");
      Serial.print(convert_to_dec(DCM_Matrix[1][0]));
      Serial.print (",");
      Serial.print(convert_to_dec(DCM_Matrix[1][1]));
      Serial.print (",");
      Serial.print(convert_to_dec(DCM_Matrix[1][2]));
      Serial.print (",");
      Serial.print(convert_to_dec(DCM_Matrix[2][0]));
      Serial.print (",");
      Serial.print(convert_to_dec(DCM_Matrix[2][1]));
      Serial.print (",");
      Serial.print(convert_to_dec(DCM_Matrix[2][2]));
      #endif*/
  //    Serial.println();    
      
}

long convert_to_dec(float x)
{
  return x*10000000;
}

