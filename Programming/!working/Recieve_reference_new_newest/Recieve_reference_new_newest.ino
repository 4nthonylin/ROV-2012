#include <Servo.h>
#define ledpin 3

Servo cam1x;
Servo cam1y;
Servo cam2;
Servo arm;

byte pwm[5] = {
  0, 0, 0, 0, 0};
byte dir[8] = {
  0, 0, 0, 0, 0, 0, 0, 0};
byte servo[4] = {
  90, 90, 90, 90};
int motorPin[5] = {
  6, 7, 8, 9, 10};
int dirPin[8] = {
  30, 31, 32, 33, 34, 35, 36, 37};
int servoPin[] = {
  22, 23, 24, 25};
//byte button = B00000000;
byte compass[2];
byte sync = 0xAA;
byte error;
boolean get();
void transmit();
void output();
byte errorcheck();


// 0 = left, 1 = right, 2 = vertical1, 3 = vertical2

void setup(){
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);
  for (int x = 0; x < 5; x++)
    pinMode(motorPin[x], OUTPUT);
  for(int y = 0; y < 8; y++)
    pinMode(dirPin[y], OUTPUT);
  pinMode(ledpin, OUTPUT);
  cam1x.attach(servoPin[1]);
  cam1y.attach(servoPin[0]);
  cam2.attach(servoPin[2]);
  arm.attach(servoPin[3]);
  error = 0x05;
}

void loop(){
  if (get()){
    //  digitalWrite(ledpin, HIGH);
    output();
  }
  transmit();
  // else
  //   digitalWrite(ledpin, LOW);
}

void transmit(){
  if(Serial2.available() >= 3 && Serial2.read() == sync){
    compass[0] = Serial2.read();
    compass[1] = Serial2.read();
    digitalWrite(ledpin, HIGH);
  }
  else
    digitalWrite(ledpin, LOW);

  Serial.write(sync);
  Serial.write(compass[0]);
  Serial.write(compass[1]);
}

boolean get(){

  if(Serial1.available() >= 18 && Serial1.read() == sync){
    for(int x = 0; x < 5; x++)
      pwm[x] = Serial1.read();
    for(int z = 0; z < 8; z++)
      dir[z] = Serial1.read();
    for(int y = 0; y < 4; y++)
      servo[y] = Serial1.read();
    return true;
  }
  else
    return false;

}

byte errorcheck(){

  return 0x00;
}

void output(){

  for(int z = 0; z < 8; z++)
    digitalWrite(dirPin[z], dir[z]);
  for(int y = 0; y < 5; y++)
    analogWrite(motorPin[y], pwm[y]);

  cam1x.write(servo[0]);
  cam1y.write(servo[1]);
  cam2.write(servo[2]);
  arm.write(servo[3]);
}



