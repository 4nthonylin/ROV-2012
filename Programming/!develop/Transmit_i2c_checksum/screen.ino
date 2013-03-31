void screen(){
  conversion();
  char buff1[28];
  char buff3[28];
  char buff5[28];
  char buff7[28];
  char buff12[28];
  sprintf(buff1, "    %2d.%d C   %2d.%d RH  %3d", temperature/10, abs(temperature%10), humidity/10, abs(humidity%10), bearing);
  sprintf(buff3, "%3d", servo[1]);
  sprintf(buff5, "%3d", 180 - servo[0]);
  sprintf(buff7, "%3d", servo[2]);
  sprintf(buff12, "    %3d     %3d     %3d", pwm[0], pwm[1], pwm[2]);
  osd.write_to_screen(buff1, 1);
  osd.write_to_screen(buff3, 3);
  osd.write_to_screen(buff5, 5);
  osd.write_to_screen(buff7, 7);
  osd.write_to_screen(buff12, 12);
}

