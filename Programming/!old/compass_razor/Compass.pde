
// Local magnetic declination
// I use this web : http://www.ngdc.noaa.gov/geomagmodels/Declination.jsp
#define MAGNETIC_DECLINATION -6.0    // not used now -> magnetic bearing

float RadiansToDegrees(float rads)
{
  // Correct for when signs are reversed.

//  
//  if(rads < 0)
//    rads += 2*PI;
//      
//  // Check for wrap due to addition of declination.
//  if(rads > 2*PI)
//    rads -= 2*PI;
//   
  // Convert radians to degrees for readability.
  float heading = rads * 180/PI;
       
  return heading;
}

void Compass_Heading()
{
  float MAG_X;
  float MAG_Y;
  float cos_roll;
  float sin_roll;
  float cos_pitch;
  float sin_pitch;
  
  cos_roll = cos(roll);
  sin_roll = sin(roll);
  cos_pitch = cos(pitch);
  sin_pitch = sin(pitch);
  // Tilt compensated Magnetic filed X:
  MAG_X = magnetom_x*cos_pitch+magnetom_y*sin_roll*sin_pitch+magnetom_z*cos_roll*sin_pitch;
  // Tilt compensated Magnetic filed Y:
  MAG_Y = magnetom_y*cos_roll-magnetom_z*sin_roll;
  // Magnetic Heading
  MAG_Heading = atan2(-MAG_Y,MAG_X);
  
  MAG_Degree = RadiansToDegrees(MAG_Heading);
}


