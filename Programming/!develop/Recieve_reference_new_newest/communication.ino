void transmit(){
  digitalWrite(ledpin, HIGH);
  Serial.write(sync);
  for(int z = 0; z < 2; z++) Serial.write(compass[z]);
  for(int x = 0; x < 2; x++) Serial.write(humidity[x]);     
  for(int y = 0; y < 2; y++) Serial.write(temperature[y]);     
  Serial.write(error);
  Serial.write(checksum());
  lastTransmit = currentTime;
}

boolean get(){
  if(Serial1.available() >= 19 && Serial1.read() == sync){
    for(int x = 0; x < 17; x++) buff[x] = Serial1.read();
    byte checksum = Serial1.read();

    if(verify(checksum)){
      for(int x = 0; x < 5; x++) pwm[x] = buff[x];
      for(int z = 0; z < 8; z++) dir[z] = buff[z + 5];
      for(int y = 0; y < 4; y++) servo[y] = buff[y + 13];
      return true;
    }
    else return false;
  }
  else
    return false;
}

byte checksum(){
  return (compass[0] & compass[1]) ^ (humidity[0] & humidity[1]) ^ (temperature[0] & temperature[1]) ^ error;  
}

boolean verify(byte checksum){
  byte cs = (buff[0] & buff[1]) ^ (buff[2] & buff[3]) ^ (buff[4] & buff[5]) ^ (buff[6] & buff[7]) ^ (buff[8] & buff[9]) ^ (buff[10] & buff[11]) ^ (buff[12] & buff[13]) ^ (buff[14] & buff[15]) ^ buff[16]; 
  if(cs == checksum) return true;
  else return false;
}
