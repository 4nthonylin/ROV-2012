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

void get(){
  if(Serial.available() >= 12 && Serial.read() == sync){
    for(int x = 0; x < 2; x++) comp[x] = Serial.read();
    for(int y = 0; y < 4; y++) hum[y] = Serial.read();
    for(int z = 0; z < 4; z++) temp[z] = Serial.read();
    errorm = Serial.read();
    digitalWrite(indicator[1], HIGH);
  }
  else
    digitalWrite(indicator[1], LOW);

  Wire.beginTransmission(0x14);
  for(int x = 0; x < 2; x++) Wire.write(comp[x]);
  for(int y = 0; y < 4; y++) Wire.write(hum[y]);
  for(int z = 0; z < 4; z++) Wire.write(temp[z]);
  Wire.write(errorm);
  Wire.endTransmission();
}
