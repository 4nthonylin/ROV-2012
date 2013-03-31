#include <Wire.h>
#include <PS2X_lib.h>

PS2X ps2x; // create PS2 Controller Class

int ledPin = 3;
int error = 0; 
byte type = 0;
byte errorm = 0x00;
boolean mode = true; //true is forward, false is backward
byte data[2];
byte pwm[5] = {
  0, 0, 0, 0, 0};
byte dir[8] = {
  0, 0, 0, 0, 0, 0, 0, 0};
byte servo[4] = {
  90, 90, 90, 90};
byte button[3] = {
  0, 0, 0};
byte sync = 0xAA;

void ps2();
void transmit();
void get();
void servoCalc();
void servoLimit();

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  Wire.begin();
  error = ps2x.config_gamepad(5, 7, 6, 8);   //setup pins and settings:  GamePad(clock, command, attention, data, Pressures?, Rumble?) check for error
}

void loop()
{
  // misc.listen();
  ps2();
  transmit();
  get();
  servoCalc();
}

void ps2(){
  ps2x.read_gamepad();

  if(error == 0){
    if(mode){
      if(ps2x.Analog(PSS_LY) <= 110){
        pwm[0] = map(ps2x.Analog(PSS_LY), 110, 0, 0, 255);
        dir[0] = 0;
        dir[1] = 1;
      }
      else if(ps2x.Analog(PSS_LY) >= 160){
        pwm[0] = map(ps2x.Analog(PSS_LY), 160, 255, 0, 255);
        dir[0] = 1;
        dir[1] = 0;
      }
      else{
        pwm[0] = 0;
        dir[0] = 0;
        dir[1] = 0;
      }
      if(ps2x.Analog(PSS_RY) <= 100){
        pwm[1] = map(ps2x.Analog(PSS_RY), 100, 0, 0, 255);
        dir[2] = 0;
        dir[3] = 1;
      }
      else if(ps2x.Analog(PSS_RY) >= 130){
        pwm[1] = map(ps2x.Analog(PSS_RY), 130, 255, 0, 255);
        dir[2] = 1;
        dir[3] = 0;
      }
      else{
        pwm[1] = 0;
        dir[2] = 0;
        dir[3] = 0;
      }
    }
    else{
      if(ps2x.Analog(PSS_LY) <= 110){
        pwm[1] = map(ps2x.Analog(PSS_LY), 110, 0, 0, 255);
        dir[0] = 1;
        dir[1] = 0;
      }
      else if(ps2x.Analog(PSS_LY) >= 160){
        pwm[1] = map(ps2x.Analog(PSS_LY), 160, 255, 0, 255);
        dir[0] = 0;
        dir[1] = 1;
      }
      else{
        pwm[1] = 0;
        dir[0] = 0;
        dir[1] = 0;
      }
      if(ps2x.Analog(PSS_RY) <= 100){
        pwm[0] = map(ps2x.Analog(PSS_RY), 100, 0, 0, 255);
        dir[2] = 1;
        dir[3] = 0;
      }
      else if(ps2x.Analog(PSS_RY) >= 130){
        pwm[0] = map(ps2x.Analog(PSS_RY), 130, 255, 0, 255);
        dir[2] = 0;
        dir[3] = 1;
      }
      else{
        pwm[0] = 0;
        dir[2] = 0;
        dir[3] = 0;

      }
    }

    if(ps2x.Button(PSB_L1)){
      pwm[2] = 255;
      dir[4] = 1;
      dir[5] = 0;
      pwm[3] = 255;
      dir[6] = 1;
      dir[7] = 0;
    }
    else if(ps2x.Button(PSB_L2)){
      pwm[2] = 255;
      dir[4] = 0;
      dir[5] = 1;
      pwm[3] = 255;
      dir[6] = 0;
      dir[7] = 1;
    }
    else{
      pwm[2] = 0;
      dir[4] = 0;
      dir[5] = 0;
      pwm[3] = 0;
      dir[6] = 0;
      dir[7] = 0;
    }

    if(ps2x.Button(PSB_L3)) mode = false;
    if(ps2x.Button(PSB_R3)) mode = true;

    if(ps2x.Button(PSB_PAD_LEFT))
      servo[1]-= 2;
    if(ps2x.Button(PSB_PAD_RIGHT))
      servo[1]+= 2;
    if(ps2x.Button(PSB_PAD_UP))
      servo[0]-= 2;
    if(ps2x.Button(PSB_PAD_DOWN))
      servo[0]+= 2;
    if(ps2x.Button(PSB_PINK))
      servo[2]-= 1;
    if(ps2x.Button(PSB_RED))
      servo[2]+= 1;
    if(ps2x.Button(PSB_R1))
      servo[3] = 180;
    else if(ps2x.Button(PSB_R2))
      servo[3] = 0;
    else
      servo[3] = 90;

    if(ps2x.Button(PSB_BLUE)) pwm[4] = 200;
    if(ps2x.Button(PSB_GREEN)) pwm[4] = 0;
    if(ps2x.Button(PSB_SELECT)){
      for(int index = 0; index < 4; index++)
        servo[index] = 90;
    }
  }
  else{
    for(int x; x < 4; x++) servo[x] = 90;
    for(int y; y < 5; y++) pwm[y] = 0;
    for(int z; z < 8; z++) dir[z] = 0;
  }
  servoLimit();
}

void servoLimit(){
  if(servo[0] >= 179) servo[0] = 179;
  if(servo[0] <= 1) servo[0] = 1;

  if(servo[1] >= 179) servo[1] = 179;
  if(servo[1] <= 1) servo[1] = 1;

  if(servo[1] >= 179) servo[2] = 179;
  if(servo[2] <= 1) servo[2] = 1;

  if(servo[3] >= 179) servo[3] = 179;
  if(servo[3] <= 1) servo[3] = 1;

}

void transmit()
{
  Serial.write(sync);
  for(int x = 0; x < 5; x++){
    Serial.write(pwm[x]);
  }
  for(int z = 0; z < 8; z++){
    Serial.write(dir[z]);
  }
  for(int y = 0; y < 4; y++){
    Serial.write(servo[y]);
  }
}

void servoCalc(){
  for(int index = 0; index < 3; index++){
    if(button[index] == 1)
      servo[index] += 1;
    else if(button[index] == 2)
      servo[index] -= 1;
  }
}

void get(){
  if(Serial.available() >= 3 && Serial.read() == sync){
    data[0] = Serial.read();
    data[1] = Serial.read();
    digitalWrite(ledPin, HIGH);
  }
  else
    digitalWrite(ledPin, LOW);


  Wire.beginTransmission(0x14);
  Wire.write(data[0]);
  Wire.write(data[1]);
  Wire.write(errorm);
  Wire.endTransmission();

  Wire.requestFrom(0x14, 3);
  if(Wire.available() >= 3){
    button[0] = Wire.read();
    button[1] = Wire.read();
    button[2] = Wire.read();
  }
}










































