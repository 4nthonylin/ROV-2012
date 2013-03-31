#include <Servo.h>

Servo cam1x;
Servo cam1y;
Servo cam2;
Servo arm;

byte inData[4];  // Allocate some space for the Bytes
byte pwm[] = {
  0, 0, 0, 0, 0};
byte dir[] = {
  0, 0, 0, 0, 0, 0, 0, 0};
byte servo[] = {
  90, 90, 90};
int motorPin[] = {
  6, 7, 8, 9, 10};
int dirPin[] = {
  30, 31, 32, 33, 34, 35, 36, 37};
int servoPin[] = {
  22, 23, 24, 25};
//byte button = B00000000;
int sensor[] = {
  0};
byte command[] = {
  0xAA, 0xAB, 0xAC}; //sync, led on, led off
byte sync = 0xAA;
boolean get();
void transmit();
void output();
// 0 = left, 1 = right, 2 = vertical1, 3 = vertical2

void setup(){
  Serial1.begin(9600);
  Serial2.begin(9600);
  for (int x = 0; x < 4; x++)
    pinMode(motorPin[x], OUTPUT);
  for(int y = 0; y < 8; y++)
    pinMode(dirPin[y], OUTPUT);
  pinMode(3, OUTPUT);
  cam1x.attach(servoPin[0]);
  cam1y.attach(servoPin[1]);
  cam2.attach(servoPin[2]);
  arm.attach(servoPin[3]);
}

void loop(){
  if (get()){
    digitalWrite(3, HIGH);
    output();
    transmit();

  }
  else
    digitalWrite(3, LOW);
}

void transmit(){
  Serial1.write(sync);
  Serial1.write(sensor[0]);
  Serial1.write(sensor[1]);
}

boolean get(){
  if(Serial1.available() >= 18 && Serial1.read() == sync){
    for(int x = 0; x < 5; x++)
      pwm[x] = Serial1.read();
    for(int z = 0; z < 8; z++)
      dir[z] = Serial1.read();

    for(int y = 0; y < 4; y++)
      servo[y] = Serial1.read();
    //    button = Serial1.read();
    return true;
  }
  if(Serial2.available() >= 2 && Serial2.read() == sync){
    sensor[0] = Serial2.read();
    sensor[1] = Serial2.read();
    return true;
  }
  else
    return false;
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




