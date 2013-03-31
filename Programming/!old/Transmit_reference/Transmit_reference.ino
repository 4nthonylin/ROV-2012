#include <PS2X_lib.h>
#include <SoftwareSerial.h>


SoftwareSerial misc(9, 10);
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
  0, 0, 0, 0};
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
  error = ps2x.config_gamepad(5, 7, 6, 8);   //setup pins and settings:  GamePad(clock, command, attention, data, Pressures?, Rumble?) check for error
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
  data[0] = ((int)ps2x.Analog(PSS_LY));
  data[1] = ((int)ps2x.Analog(PSS_RY));
  if(ps2x.Button(PSB_PAD_UP))
    data[2] = ((int)ps2x.Analog(PSAB_PAD_UP));
  if(ps2x.Button(PSB_PAD_DOWN))
    data[3] = ((int)ps2x.Analog(PSAB_PAD_DOWN));



  if(ps2x.Analog(PSS_LY) <= 104){
    pwm[0] = map(ps2x.Analog(PSS_LY), 104, 0, 0, 255);
    dir[0] = 0;
    dir[1] = 1;
  }
  else if(ps2x.Analog(PSS_LY) >= 150){
    pwm[0] = map(ps2x.Analog(PSS_LY), 150, 255, 0, 255);
    dir[0] = 1;
    dir[1] = 0;
  }
  else{
    pwm[0] = 0;
    dir[0] = 0;
    dir[1] = 0;
  }

  if(ps2x.Analog(PSS_RY) <= 80){
    pwm[1] = map(ps2x.Analog(PSS_RY), 80, 0, 0, 255);
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
    dir[4] = 0;
    dir[5] = 1;
    pwm[3] = 255;
    dir[6] = 0;
    dir[7] = 1;
  }
  else if(ps2x.Button(PSB_L2)){
    pwm[2] = 255;
    dir[4] = 1;
    dir[5] = 0;
    pwm[3] = 255;
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

  if(ps2x.Button(PSB_R1))
    servo[3]++;
  else if(ps2x.Button(PSB_R2))
    servo[3]--;
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
  Serial.write(sync);

  for(int x = 0; x < 4; x++){
    //  Serial.print(" ,");
    Serial.write(pwm[x]);
  }

  for(int z = 0; z < 8; z++){
    //  Serial.print(" ,");
    Serial.write(dir[z]);
  }

  for(int y = 0; y < 3; y++){
    //  Serial.print(" ,");
    Serial.write(servo[y]);
  }
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



















