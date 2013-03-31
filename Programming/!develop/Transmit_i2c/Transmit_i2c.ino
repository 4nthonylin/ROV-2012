#include <Wire.h>
#include <PS2X_lib.h>
#include <MAX7456.h>

//#define DATAOUT 12
//#define DATAIN  11
//#define SPICLOCK  13//sck
//#define MAX7456SELECT 10//ss
//#define VSYNC 2// INT0

PS2X ps2x; // create PS2 Controller Class
MAX7456 osd;

int indicator[3] = {
  2, 3, 4};
int error = 0; 
byte type = 0;
byte errorm = 0x01;
boolean mode = true; //true is forward, false is backward
byte comp[2];
byte temp[4];
byte hum[4];
int bearing;
float temperature;
float humidity;
byte pwm[5] = {
  0, 0, 0, 0, 0};
byte dir[8] = {
  0, 0, 0, 0, 0, 0, 0, 0};
byte servo[4] = {
  90, 90, 90, 90};
byte button[3] = {
  0, 0, 0};
byte sync = 0xAA;
unsigned long startTime;
unsigned long currentTime;

void ps2();
void transmit();
void get();
void servoLimit();
void conversion();
void screen();
void startup();

void setup()
{
  Serial.begin(9600);
  osd.begin(10, false);
  for(int x = 0; x < 3; x++) pinMode(indicator[x], OUTPUT);
  Wire.begin();
  error = ps2x.config_gamepad(5, 7, 6, 8);   //setup pins and settings:  GamePad(clock, command, attention, data, Pressures?, Rumble?) check for error
  startTime = millis();
  currentTime = millis();
  startup();
}

void loop()
{
  ps2();
  transmit();
  get();
  screen();
}

void servoLimit(){
  if(servo[0] > 180) servo[0] = 180;
  else if(servo[0] <= 2) servo[0] = 2;

  if(servo[1] > 180) servo[1] = 180;
  else if(servo[1] <= 2) servo[1] = 2;

  if(servo[2] > 180) servo[2] = 180;
  else if(servo[2] <= 2) servo[2] = 2;
}
