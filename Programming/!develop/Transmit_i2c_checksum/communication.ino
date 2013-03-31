void transmit()
{
  Serial.write(sync);
  for(int x = 0; x < 5; x++) Serial.write(pwm[x]);
  for(int z = 0; z < 8; z++) Serial.write(dir[z]);
  for(int y = 0; y < 4; y++) Serial.write(servo[y]);
  Serial.write(checksum());
}

void get(){
  if(Serial.available() >= 9 && Serial.read() == sync){

    for(int x = 0; x < 7; x++) buff[x] = Serial.read();
    byte checksum = Serial.read();

    if(verify(checksum)){
      for(int x = 0; x < 2; x++) comp[x] = buff[x];
      for(int y = 0; y < 2; y++) hum[y] = buff[y+2];
      for(int z = 0; z < 2; z++) temp[z] = buff[z+4];
      errorm = buff[6];
      digitalWrite(indicator[1], HIGH);
    }
  }
  else digitalWrite(indicator[1], LOW);

  i2c();
}

boolean verify(byte cs){
  byte temp = (buff[0] & buff[1]) ^ (buff[2] & buff[3]) ^ (buff[4] & buff[5]) ^ buff[6];  

  if(cs == temp) return true;
  else return false;
}

byte checksum(){
  return (pwm[0] & pwm[1]) ^ (pwm[2] & pwm[3]) ^ (pwm[4] & dir[0]) ^ (dir[1] & dir[2]) ^ (dir[3] & dir[4]) ^ (dir[5] & dir[6]) ^ (dir[7] & servo[0]) ^ (servo[1] & servo[2]) ^ servo[3]; 
}

void i2c(){
  Wire.beginTransmission(0x14);
  for(int x = 0; x < 2; x++) Wire.write(comp[x]);
  for(int y = 0; y < 2; y++) Wire.write(hum[y]);
  for(int z = 0; z < 2; z++) Wire.write(temp[z]);
  Wire.write(errorm);
  Wire.endTransmission();
}


