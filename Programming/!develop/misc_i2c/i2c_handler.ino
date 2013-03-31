void receiveEvent(int howMany){
  if(Wire.available() >= 7){
    for(int x = 0; x < 2; x++) comp[x] = Wire.read();
    for(int y = 0; y < 2; y++) hum[y] = Wire.read();
    for(int z = 0; z < 2; z++) temp[z] = Wire.read();
    error = Wire.read();
  }
}
