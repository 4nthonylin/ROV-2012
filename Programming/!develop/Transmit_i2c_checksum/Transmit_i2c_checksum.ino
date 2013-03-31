#include <Wire.h>
#include <PS2X_lib.h>
#include <MAX7456.h>
#include <stdio.h>

//#define DATAOUT 12
//#define DATAIN  11
//#define SPICLOCK  13//sck
//#define MAX7456SELECT 10//ss
//#define VSYNC 9// INT0

/*
0x00 = no error
 0x01 = startup
 0x02 = ps2 controller error
 0x03 = humidity sensor error
*/

PS2X ps2x; // create PS2 Controller Class
MAX7456 osd;

int indicator[3] = {
  2, 3, 4};
int error = 0; 
byte type = 0;
byte errorm = 0x01;
boolean mode = true; //true is forward, false is backward
byte buff[7];
byte comp[2];
byte temp[2];
byte hum[2];
int bearing;
int temperature;
int humidity;
byte pwm[5] = {
  0, 0, 0, 0, 0};
byte dir[8] = {
  0, 0, 0, 0, 0, 0, 0, 0};
byte servo[4] = {
  90, 90, 90, 90};
byte sync = 0xAA;
unsigned long startTime;
unsigned long currentTime;
unsigned long errorCheck;

void ps2();
void transmit();
void get();
void servoLimit();
void conversion();
void screen();
void startup();
void led();
boolean verify(int cs);
byte checksum();
void i2c();

void setup()
{
  Serial.begin(9600);
  osd.begin(10, false);
  for(int x = 0; x < 3; x++) pinMode(indicator[x], OUTPUT);
  Wire.begin();
  error = ps2x.config_gamepad(5, 7, 6, 8);   //GamePad(clock, command, attention, data)
  startTime = millis();
  currentTime = millis();
  errorCheck = millis();
  startup();
}

void loop()
{
  currentTime = millis();
  ps2();
  transmit();
  get();
  screen();
  if(currentTime - errorCheck > 5000){ /////////////
    error = ps2x.config_gamepad(5, 7, 6, 8);   //GamePad(clock, command, attention, data)
    errorCheck = currentTime;
  }
}

void led(){
  if(errorm != 0x00){
    digitalWrite(indicator[2], HIGH);
    digitalWrite(indicator[0], LOW); 
  }
  else{
    digitalWrite(indicator[2], LOW);
    digitalWrite(indicator[0], HIGH);
  }
}


