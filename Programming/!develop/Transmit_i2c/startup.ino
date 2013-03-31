void startup(){
  while(currentTime - startTime < 5000 && !ps2x.Button(PSB_START)){
    ps2x.read_gamepad();
    currentTime = millis();
    errorm = 0x01;
    Wire.beginTransmission(0x14);
    for(int x = 0; x < 2; x++) Wire.write(comp[x]);
    for(int y = 0; y < 4; y++) Wire.write(hum[y]);
    for(int z = 0; z < 4; z++) Wire.write(temp[z]);
    Wire.write(errorm);
    Wire.endTransmission();
          digitalWrite(indicator[0], HIGH);
      digitalWrite(indicator[1], HIGH);
      digitalWrite(indicator[2], HIGH);

  }
  errorm = 0x00;
      digitalWrite(indicator[0], LOW);
      digitalWrite(indicator[1], LOW);
      digitalWrite(indicator[2], LOW);
}



