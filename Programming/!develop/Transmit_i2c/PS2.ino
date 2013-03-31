void ps2(){
  ps2x.read_gamepad();

  if(error == 0){
    if(mode){
      if(ps2x.Analog(PSS_LY) <= 110){
        pwm[0] = map(ps2x.Analog(PSS_LY), 110, 0, 0, 255);
        dir[0] = 0;
        dir[1] = 1;
      }
      else if(ps2x.Analog(PSS_LY) >= 150){
        pwm[0] = map(ps2x.Analog(PSS_LY), 150, 255, 0, 255);
        dir[0] = 1;
        dir[1] = 0;
      }
      else{
        pwm[0] = 0;
        dir[0] = 0;
        dir[1] = 0;
      }
      if(ps2x.Analog(PSS_RY) <= 105){
        pwm[1] = map(ps2x.Analog(PSS_RY), 105, 0, 0, 255);
        dir[2] = 0;
        dir[3] = 1;
      }
      else if(ps2x.Analog(PSS_RY) >= 170){
        pwm[1] = map(ps2x.Analog(PSS_RY), 170, 255, 0, 255);
        dir[2] = 1;
        dir[3] = 0;
      }
      else{
        pwm[1] = 0;
        dir[2] = 0;
        dir[3] = 0;
      }
    }
    else{
      if(ps2x.Analog(PSS_LY) <= 110){
        pwm[1] = map(ps2x.Analog(PSS_LY), 110, 0, 0, 255);
        dir[2] = 1;
        dir[3] = 0;
      }
      else if(ps2x.Analog(PSS_LY) >= 150){
        pwm[1] = map(ps2x.Analog(PSS_LY), 150, 255, 0, 255);
        dir[2] = 0;
        dir[3] = 1;
      }
      else{
        pwm[1] = 0;
        dir[2] = 0;
        dir[3] = 0;
      }
      if(ps2x.Analog(PSS_RY) <= 105){
        pwm[0] = map(ps2x.Analog(PSS_RY), 105, 0, 0, 255);
        dir[0] = 1;
        dir[1] = 0;
      }
      else if(ps2x.Analog(PSS_RY) >= 170){
        pwm[0] = map(ps2x.Analog(PSS_RY), 170, 255, 0, 255);
        dir[0] = 0;
        dir[1] = 1;
      }
      else{
        pwm[0] = 0;
        dir[0] = 0;
        dir[1] = 0;

      }
    }

    if(ps2x.Button(PSB_L1)){
      pwm[2] = 255;
      dir[4] = 1;
      dir[5] = 0;
      pwm[3] = 255;
      dir[6] = 1;
      dir[7] = 0;
    }
    else if(ps2x.Button(PSB_L2)){
      pwm[2] = 255;
      dir[4] = 0;
      dir[5] = 1;
      pwm[3] = 255;
      dir[6] = 0;
      dir[7] = 1;
    }
    else{
      pwm[2] = 0;
      dir[4] = 0;
      dir[5] = 0;
      pwm[3] = 0;
      dir[6] = 0;
      dir[7] = 0;
    }

    if(ps2x.Button(PSB_L3)) mode = false;
    if(ps2x.Button(PSB_R3)) mode = true;

    if(ps2x.Button(PSB_PAD_LEFT))
      servo[1]-= 2;
    if(ps2x.Button(PSB_PAD_RIGHT))
      servo[1]+= 2;
    if(ps2x.Button(PSB_PAD_UP))
      servo[0]-= 2;
    if(ps2x.Button(PSB_PAD_DOWN))
      servo[0]+= 2;
    if(ps2x.Button(PSB_PINK))
      servo[2]-= 1;
    if(ps2x.Button(PSB_RED))
      servo[2]+= 1;
    if(ps2x.Button(PSB_R1))
      servo[3] = 180;
    else if(ps2x.Button(PSB_R2))
      servo[3] = 0;
    else
      servo[3] = 90;

    if(ps2x.Button(PSB_BLUE)) pwm[4] = 100;
    if(ps2x.Button(PSB_GREEN)) pwm[4] = 0;
    if(ps2x.Button(PSB_SELECT)){
      for(int index = 0; index < 4; index++)
        servo[index] = 90;
    }
  }
  else{
    for(int x = 0; x < 4; x++) servo[x] = 90;
    for(int y = 0; y < 5; y++) pwm[y] = 0;
    for(int z = 0; z < 8; z++) dir[z] = 0;
  }
  servoLimit();
}

