void startup(){
  while(currentTime - startTime < 1500 && !ps2x.Button(PSB_START)){
    ps2x.read_gamepad();
    currentTime = millis();
    errorm = 0x01;
    i2c();
    digitalWrite(indicator[0], HIGH);
    digitalWrite(indicator[1], HIGH);
    digitalWrite(indicator[2], HIGH);
  }
  errorm = 0x00;
  i2c();
  digitalWrite(indicator[0], LOW);
  digitalWrite(indicator[1], LOW);
  digitalWrite(indicator[2], LOW);
  Serial.flush();
}



