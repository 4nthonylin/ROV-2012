#include <Wire.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

int switchPin[] = {
  8, 9, 10, 11, 12, 13};
int button[] = {
  0, 0, 0, 0, 0, 0};
byte buttons[] = {
  0, 0, 0};
byte sync = 0xAA;
byte error;
int bearing;
byte comp[2];
int temperature;
byte temp[2];
int humidity;
byte hum[2];

void buttonGet();
void update_lcd();
void servoCalc();

void setup(){
  Wire.begin(0x14);
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
  lcd.begin(16, 2);
  for(int x = 0; x < 6; x++){
    pinMode(switchPin[x], INPUT);
    digitalWrite(switchPin[x], HIGH);
  }
}

void loop(){
  buttonGet();
  servoCalc();
  update_lcd();
  
  union bearing_tag {
    byte bearing_b[2];
    int bearing_fval;
  } 
  bearing_Union;

  bearing_Union.bearing_b[0] = comp[0];
  bearing_Union.bearing_b[1] = comp[1];
  bearing = bearing_Union.bearing_fval;
}

void update_lcd(){

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(buttons[0]);
  lcd.print(" ,");
  lcd.print(buttons[1]);
  lcd.print(" ,");
  lcd.print(buttons[2]);
  lcd.setCursor(0, 1);
  lcd.print("Bearing: ");
  lcd.print(bearing);
  lcd.print("; ");
  lcd.print(error);
  delay(100);
}

void buttonGet(){
  for(int x = 0; x <= 5; x++)
    button[x] = digitalRead(switchPin[x]);
}

void servoCalc(){
  if(button[0] == LOW)
    buttons[2] = 2;
  else if(button[1] == LOW)
    buttons[2] = 1;
  else
    buttons[2] = 0;
  if(button[2] == LOW)
    buttons[1] = 2;
  else if(button[3] == LOW)
    buttons[1] = 1;
  else
    buttons[1] = 0;
  if(button[4] == LOW)
    buttons[0] = 2;
  else if(button[5] == LOW)
    buttons[0]= 1;
  else
    buttons[0] = 0;
}

void requestEvent(){
  Wire.write(buttons, 3);
}

void receiveEvent(int howMany){
  if(Wire.available() >= 3){
    comp[0] = Wire.read();
    comp[1] = Wire.read();
    error = Wire.read();
  }
}

















