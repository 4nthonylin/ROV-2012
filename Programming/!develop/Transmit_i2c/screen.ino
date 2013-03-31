void screen(){
  conversion();
  byte servox[1];
  servox[0] = 180 - servo[0];
  int temp1 = (temperature - (int)temp) * 100;
  int hum1 = (humidity - (int)humidity) * 100;
  char buff1[28];
  char buff3[28];
  char buff5[28];
  char buff7[28];
  char buff9[28];
  char buff12[28];
  sprintf(buff1, "  %0d.%d C   %0d.%d%% RH  %3d", (int)temperature, temp1, (int)humidity, hum1, bearing);
  sprintf(buff3, "%3d", servo[1]);
  sprintf(buff5, "%3d", servox[0]);
  sprintf(buff7, "%3d", servo[2]);
  sprintf(buff9, "%3d", servo[3]);
  sprintf(buff12, "    %3d     %3d     %3d", pwm[0], pwm[1], pwm[2]);
  osd.write_to_screen(buff1, 1);
  osd.write_to_screen(buff3, 3);
  osd.write_to_screen(buff5, 5);
  osd.write_to_screen(buff7, 7);
  osd.write_to_screen(buff9, 9);
  osd.write_to_screen(buff12, 12);
}

