#include <PS2X_lib.h>
#include <SoftwareSerial.h>


SoftwareSerial misc(2, 3);
PS2X ps2x; // create PS2 Controller Class


// Arrays, 0 = Left, 1 = Right, 2 = Vertical 1, 3 = Vertical 2

int ledPin = 3;
int error = 0; 
int data[] = {
  0, 0};
byte pwm[] = {
  0, 0, 0, 0};
byte dir[] = {
  0, 0, 0, 0, 0, 0, 0, 0};
int servo[] = {
  0, 0, 0};
byte type = 0;
byte command[] = {
  0xAA}; //sync, led on, led off
int sensor[] = {
  0}; // compass
byte sync = 0xAA;
byte button1 = B00000000;

void ps2();
void buttonGet();
void transmit();
void get();

void setup()
{
  Serial.begin(9600);
  misc.begin(4800);
  pinMode(ledPin, OUTPUT);
  error = ps2x.config_gamepad(5,7,6,8);   //setup pins and settings:  GamePad(clock, command, attention, data, Pressures?, Rumble?) check for error
}

void loop()
{
  ps2();
  //  buttonGet();
  transmit();
  get();
}


void ps2(){
  ps2x.read_gamepad();
  data[0] = (ps2x.Analog(PSS_LY));
  data[1] = (ps2x.Analog(PSS_RY));
  data[2] = (ps2x.Analog(PSAB_PAD_UP));
  data[3] = (ps2x.Analog(PSAB_PAD_DOWN));


  if(data[0] <= 104){
    pwm[0] = map(data[0], 104, 0, 0, 255);
    dir[0] = 0;
    dir[1] = 1;
  }
  else if(data[0] >= 150){
    pwm[0] = map(data[0], 150, 255, 0, 255);
    dir[0] = 1;
    dir[1] = 0;
  }
  else{
    pwm[0] = 0;
    dir[0] = 0;
    dir[1] = 0;
  }

  if(data[1] <= 104){
    pwm[1] = map(data[1], 104, 0, 0, 255);
    dir[2] = 0;
    dir[3] = 1;
  }
  else if(data[0] >= 150){
    pwm[1] = map(data[1], 150, 255, 0, 255);
    dir[2] = 1;
    dir[3] = 0;
  }
  else{
    pwm[1] = 0;
    dir[2] = 0;
    dir[3] = 0;
  }


  if(ps2x.Button(PSB_PAD_UP)){
    pwm[2] = data[2];
    dir[4] = 0;
    dir[5] = 1;
    pwm[3] = data[3];
    dir[6] = 0;
    dir[7] = 1;
  }
  else if(ps2x.Button(PSB_PAD_DOWN)){
    pwm[2] = data[2];
    dir[4] = 1;
    dir[5] = 0;
    pwm[3] = data[3];
    dir[6] = 1;
    dir[7] = 0;
  }
  else{
    pwm[2] = 0;
    dir[4] = 0;
    dir[5] = 0;
    pwm[3] = 0;
    dir[6] = 0;
    dir[7] = 0;
  }
}


/*
void buttonGet()
 {
 if(ps2x.Button(PSB_L1))
 bitWrite(button, 1, 1);
 else
 bitWrite(button, 1, 0);
 if(ps2x.Button(PSB_L2))
 bitWrite(button, 2, 1);
 else
 bitWrite(button, 2, 0);
 if(ps2x.Button(PSB_R1))
 bitWrite(button, 3, 1);
 else
 bitWrite(button, 3, 0);
 if(ps2x.Button(PSB_R2))
 bitWrite(button, 4, 1);
 else
 bitWrite(button, 4, 0);
 if(ps2x.Button(PSB_GREEN)) //Triangle
 bitWrite(button, 5, 1);
 else
 bitWrite(button, 5, 0);
 if(ps2x.Button(PSB_PINK)) //Square
 bitWrite(button, 6, 1);
 else
 bitWrite(button, 6, 0);
 if(ps2x.Button(PSB_BLUE)) // X
 bitWrite(button, 7, 1);
 else
 bitWrite(button, 7, 0);
 if(ps2x.Button(PSB_RED)) // Circle
 bitWrite(button, 8, 1);
 else
 bitWrite(button, 8, 0);
 }
 */

void transmit()
{
  Serial.println(sync);

  for(int x = 0; x < 4; x++)
    Serial.write(pwm[x]);

  for(int z = 0; z < 8; z++)
    Serial.write(dir[z]);

  for(int y = 0; y < 3; y++)
    Serial.write(servo[y]);
  //  Serial.write(button);
}

void get(){
  if(Serial.available() > 0 && Serial.read() == sync){
    digitalWrite(ledPin, HIGH);
    sensor[0] = Serial.read();
  }

  else if(Serial.available() == 0 || Serial.read() != sync)
    digitalWrite(ledPin, LOW);

  misc.listen();

  if(misc.available() >= 4 && misc.read() == sync){
    for(int x = 0; x <= 2; x++)
      servo[x] = misc.read();
  }
}
















