#include <Wire.h>

byte datas;
volatile byte* BearingIntPtr;
byte Data[2];
byte sync = 0xAA;


void setup(){
  Wire.begin(0x14);
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Serial.begin(9600);
}


void loop(){
  if(datas == 0) digitalWrite(13, LOW);
  if(datas == 1) digitalWrite(13, HIGH);
  
  if(Serial.available() >= 3 && Serial.read() == sync){
    Data[0] = Serial.read();
    Data[1] = Serial.read();
  }

}

void receiveEvent(int howMany){
  if(Wire.available() > 0)
    datas = Wire.read();
}

void requestEvent(){
  
  Wire.write(Data, 2); 

}




