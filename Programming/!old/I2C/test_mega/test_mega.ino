#include <Wire.h>

byte buffer;
int data;
signed int bearing;
byte datas[2];
byte sync = 0xAA;

void setup(){
  Serial.begin(9600);
  //  Serial1.begin(9600);
  Wire.begin();


}

void loop(){
  if(Serial.available() > 0) buffer = Serial.read();

  if(buffer == '0') data = 0;
  if(buffer == '1') data = 1;

  Wire.beginTransmission(0x14);
  Wire.write(data);
  Wire.endTransmission();


  Wire.requestFrom(0x14, 2);
  if(Wire.available() >= 2){
    datas[0] = Wire.read();
    datas[1] = Wire.read();
  }

  /*
  if(Serial1.available() >=3 && Serial1.read() == sync)
   {
   datas[0] = Serial1.read();
   datas[1] = Serial1.read();
   }
   */

  union bearing_tag {
    byte bearing_b[2]; 
    signed int bearing_fval;
  } 
  bearing_Union;    

  bearing_Union.bearing_b[0] = datas[0];
  bearing_Union.bearing_b[1] = datas[1];  
  bearing = bearing_Union.bearing_fval;

  Serial.println();
  Serial.print(bearing);
  delay(1);
}





