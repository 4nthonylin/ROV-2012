#include <Wire.h>
#include <LiquidCrystal.h>
#include <stdio.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

byte sync = 0xAA;
byte error = 0x01;
int bearing;
byte comp[2];
int temperature;
byte temp[2];
int humidity;
byte hum[2];
unsigned long currentTime;
unsigned long previousTime;
byte degree[8] = {
  B00110,
  B01001,
  B01001,
  B00110,
  B00000,
  B00000,
  B00000,
};

void update_lcd();
void conversion();

void setup(){
  Wire.begin(0x14);
  Wire.onReceive(receiveEvent);
  currentTime = millis();
  previousTime = millis();

  lcd.begin(16, 2);
  lcd.createChar(1, degree);
  lcd.setCursor(1, 0);
  lcd.print("TAS ROV Mark 3");
  lcd.setCursor(1, 1);
  lcd.print("Control System");

  while(error == 0x01 && currentTime - previousTime < 5000) currentTime = millis();
}

void loop(){
  currentTime = millis();
  if(currentTime - previousTime > 100) update_lcd();
}

void update_lcd(){
  previousTime = currentTime;
  char buff[16];
  conversion();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(bearing);
  lcd.write(1);
  lcd.setCursor(14, 0);
  lcd.print(error);
  lcd.setCursor(0, 1);
  sprintf(buff, "%2d.%d C  %2d.%d RH", temperature/10, abs(temperature%10), humidity/10, abs(humidity%10));
  lcd.print(buff);
}













