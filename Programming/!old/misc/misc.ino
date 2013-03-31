#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

int switchPin[] = {
  8, 9, 10, 11, 12, 13};
int button[] = {
  0, 0, 0, 0, 0, 0};
int buttons[] = {
  0, 0, 0};
int last[] = {
  0, 0, 0};
unsigned int data[] = {
  0};
byte sync = 0xAA;

void buttonGet();
void transmit();
void update_lcd(boolean error);
boolean get();
boolean change();
void servoCalc();

void setup(){
  Serial.begin(2400);
  lcd.begin(16, 2);
  for(int x = 0; x < 6; x++){
    pinMode(switchPin[x], INPUT);
    digitalWrite(switchPin[x], HIGH);
  }
}

void loop(){
  buttonGet();
  servoCalc();
  transmit();
  get();
  update_lcd(false);
}

void update_lcd(boolean error){
  if(!error){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(buttons[0]);
    lcd.print(" ,");
    lcd.print(buttons[1]);
    lcd.print(" ,");
    lcd.print(buttons[2]);
    lcd.setCursor(0, 1);
    lcd.print("Bearing: ");
    lcd.print(data[0]);
  }

  else if(error){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(buttons[0]);
    lcd.print(" ,");
    lcd.print(buttons[1]);
    lcd.print(" ,");
    lcd.print(buttons[2]);
    lcd.setCursor(0, 1);
    lcd.println("Error");
  }
}


void buttonGet(){
  for(int x = 0; x <= 5; x++)
    button[x] = digitalRead(switchPin[x]);
}

void servoCalc(){
  if(button[0] == LOW)
    buttons[0] = 2;
  else if(button[1] == LOW)
    buttons[0] = 1;
  else
    buttons[0] = 0;
  if(button[2] == LOW)
    buttons[1] = 1;
  else if(button[3] == LOW)
    buttons[1] = 2;
  else
    buttons[1] = 0;
  if(button[4] == LOW)
    buttons[2] = 1;
  else if(button[5] == LOW)
    buttons[2]= 2;
  else
    buttons[2] = 0;
}

void transmit(){
  Serial.write(sync);
  for(int z = 0; z < 3; z++)
    Serial.write(buttons[z]);
}

boolean get(){

  if(Serial.available() >= 3 && Serial.read() == sync){
    byte dataByte1 = Serial.read();
    byte dataByte2 = Serial.read();
    unsigned int value = dataByte1;

    data[0] = value | (dataByte2 << 8);
    return true;
  }
  else if(Serial.available() <= 1)
    return false;
}















