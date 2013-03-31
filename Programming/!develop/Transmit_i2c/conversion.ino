void conversion(){
  union bearing_tag {
    byte bearing_b[2];
    int bearing_fval;
  } 
  bearing_Union;

  union humidity_tag {
    byte humidity_b[4];
    float humidity_fval;
  } 
  humidity_Union;

  union temperature_tag {
    byte temperature_b[4];
    float temperature_fval;
  } 
  temperature_Union;

  for(int x = 0; x < 2; x++) bearing_Union.bearing_b[x] = comp[x];
  for(int y = 0; y < 4; y++) humidity_Union.humidity_b[y] = hum[y];
  for(int z = 0; z < 4; z++) temperature_Union.temperature_b[z] = temp[z];

  bearing = bearing_Union.bearing_fval;
  humidity = humidity_Union.humidity_fval;
  temperature = temperature_Union.temperature_fval;
}

