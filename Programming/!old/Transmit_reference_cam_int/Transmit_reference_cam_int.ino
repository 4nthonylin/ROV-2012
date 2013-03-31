#include <PS2X_lib.h>
#include <SoftwareSerial.h>  

SoftwareSerial misc(2, 4); //rx, tx
PS2X ps2x; // create PS2 Controller Class

// Arrays, 0 = Left, 1 = Right, 2 = Vertical 1, 3 = Vertical 2

int ledPin = 3;
int error = 0; 
byte data[] = {
  0, 0};
byte pwm[] = {
  0, 0, 0, 0};
byte dir[] = {
  0, 0, 0, 0, 0, 0, 0, 0};
int servo[] = {
  90, 90, 90, 90};
int switchPin[] = {
  8, 9, 10, 11, 12, 13};
int button[] = {
  0, 0, 0, 0, 0, 0};
byte type = 0;
byte command[] = {
  0xAA}; //sync, led on, led off
int sensor[] = {
  0}; // compass
byte sync = 0xAA;
byte button1 = B00000000;

void ps2();
void transmit();
void get();
void servoCalc();

void setup()
{
  Serial.begin(9600);
  misc.begin(2400);
  pinMode(ledPin, OUTPUT);
  error = ps2x.config_gamepad(5, 7, 6, 8);   //setup pins and settings:  GamePad(clock, command, attention, data, Pressures?, Rumble?) check for error
}

void loop()
{
//  misc.listen();
  ps2();
  transmit();
  get();
  servoCalc();
}

void ps2(){
  ps2x.read_gamepad();

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

  if(ps2x.Button(PSB_PAD_UP))
    servo[0]+= 3;
  if(ps2x.Button(PSB_PAD_DOWN))
    servo[0]-= 3;
  if(ps2x.Button(PSB_PAD_LEFT))
    servo[1]-= 3;
  if(ps2x.Button(PSB_PAD_RIGHT))
    servo[1]+= 3;

  if(ps2x.Button(PSB_PINK))
    servo[2]-= 3;

  if(ps2x.Button(PSB_RED))
    servo[2]+= 3;

  if(ps2x.Button(PSB_R1))
    servo[3]+= 3;
  if(ps2x.Button(PSB_R2))
    servo[3]-= 3;

  for(int index = 0; index < 4; index++){
    if(servo[index] >= 180)
      servo[index] = 180;
    if(servo[index] <= 0)
      servo[index] = 0;
  }

  if(ps2x.Button(PSB_SELECT)){
    for(int index = 0; index < 4; index++)
      servo[index] = 90;
  }
}


void buttonGet(){
  for(int x = 0; x <= 5; x++)
    button[x] = digitalRead(switchPin[x]);
}

void servoCalc(){
  if(button[0] == LOW)
    servo[0] += 3;
  else if(button[1] == LOW)
    servo[0] -= 3;
  if(button[2] == LOW)
    servo[1] += 3;
  else if(button[3] == LOW)
    servo[1] -= 3;
  if(button[4] == LOW)
    servo[2] += 3;
  else if(button[5] == LOW)
    servo[2] -= 3;
}

void transmit()
{
  Serial.write(sync);

  for(int x = 0; x < 4; x++){
    //  Serial.print(" ,");
    Serial.write(pwm[x]);
  }

  for(int z = 0; z < 8; z++){
    //    Serial.print(" ,");
    Serial.write(dir[z]);
  }

  for(int y = 0; y < 4; y++){
    //    Serial.print(" ,");
    Serial.write(servo[y]);
    //    Serial.print(" ,");
  }
  //unsigned int test = 360;

  // byte dataByte1 = test & B11111111;
  //byte dataByte2 = (test >> 8) & B11111111;

  misc.write(sync);
  misc.write(data[0]);
  misc.write(data[1]);

}

/*
void servoCalc(){
  for(int index = 0; index < 3; index++){
    if(button[index] == 1)
      servo[index] += 3;
    else if(button[index] == 2)
      servo[index] -= 3;
  }
}
*/

void get(){
  if(Serial.available() >= 3 && Serial.read() == sync){
    digitalWrite(ledPin, HIGH);
    data[0] = Serial.read();
    data[1] = Serial.read();
  }

  else if(Serial.available() == 0)
    digitalWrite(ledPin, LOW);
/*
  if(misc.available() >= 4 && misc.read() == sync){
    for(int x = 0; x < 3; x++)
      button[x] = misc.read();
  }
  */
}


























