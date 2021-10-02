void loop(){
  float turn_heading;
  while(true) {
    mpu_loop();
    int dist = ping();
    if (dist > 10) {
      forward();
    }
    else 
    {
      Serial.println('OBSTACLE! - Turning left');
      // turn left until 90 degrees from current heading
      
      float heading = get_heading();
      float target_heading = heading;
      
      Serial.print("Heading = ");
      Serial.println(heading);
      while (target_heading <= (heading + 90)) {
        turn_heading = get_heading();
        Serial.print("Heading = ");
        Serial.println(turn_heading);
        turnLeft();
      }
      heading = turn_heading;
    }
  }
}
