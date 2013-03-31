#include <DHT22.h>
#include <Servo.h>
#include <stdio.h>

#define ledpin 3
#define DHT22_PIN 26

DHT22 myDHT22(DHT22_PIN);
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
byte compass[2];
byte* humidity;
byte* temperature;
int hum;
int temp;
byte sync = 0xAA;
byte error;
byte buff[17];
unsigned long lastCheck = 0;
unsigned long currentTime;
unsigned long lastTransmit;

boolean get();
void transmit();
void output();
void sensor();
byte checksum();
boolean verify(byte cs);

void setup(){
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);
  for (int x = 0; x < 5; x++) pinMode(motorPin[x], OUTPUT);
  for(int y = 0; y < 8; y++) pinMode(dirPin[y], OUTPUT);
  pinMode(ledpin, OUTPUT);
  cam1x.attach(servoPin[1]);
  cam1y.attach(servoPin[0]);
  cam2.attach(servoPin[2]);
  arm.attach(servoPin[3]);
  error = 0x00;
  lastTransmit = millis();
}

void loop(){
  currentTime = millis();
  output();
  sensor();
  if(currentTime - lastTransmit > 100) transmit();
  digitalWrite(ledpin, LOW);
}

void sensor(){
  DHT22_ERROR_t errorCode;
  currentTime = millis();
  if(currentTime - lastCheck > 2100){
    errorCode = myDHT22.readData();
    switch(errorCode)
    {
    case DHT_ERROR_NONE:
      temp = myDHT22.getTemperatureCInt();
      hum = myDHT22.getHumidityInt();
      temperature = (byte*) &temp;
      humidity = (byte*) &hum;  
      break;

    default:
      error = 0x03;
      break;
    }
    lastCheck = currentTime;
  }

  if(Serial2.available() >= 3 && Serial2.read() == sync){
    for(int x = 0; x < 2; x++) compass[x] = Serial2.read();
  }
}

void output(){
  get();
  for(int z = 0; z < 8; z++)
    digitalWrite(dirPin[z], dir[z]);
  for(int y = 0; y < 5; y++)
    analogWrite(motorPin[y], pwm[y]);

  cam1x.write(servo[0]);
  cam1y.write(servo[1]);
  cam2.write(servo[2]);
  arm.write(servo[3]);

}













