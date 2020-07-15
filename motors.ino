
// Lesson 03 Sensors - Avoid Obstacles
// www.smarsfan.com/play/lessons/lesson_03_sensors

// set Motor A to Arduino Pins
int motor_A = 12;
int motor_B = 13;

// set the Motor Speed using the Arduino Pins
int motor_A_speed = 10;
int motor_B_speed = 11;

// set the time between motor on and motor off
int wait_in_milliseconds = 1000;

// set the Rangefinder pins
#define echoPin 8 
#define trigPin 7  



// this code runs once at the start
void motor_setup() {

  // setup the Pin modes for the range finder
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // this sets the speed of communication between the computer and Arduino,
  // used when uploading your code
//  Serial.begin(9600);

  Serial.println("Motors - online");
  // set the Arduino pin to OUTPUT mode
  pinMode(motor_A, OUTPUT);
  pinMode(motor_B, OUTPUT);
}



// move forward
void forward() {

  // set the direction to forward
  digitalWrite(motor_A, HIGH);
  digitalWrite(motor_B, LOW);

  // set to full speed
  analogWrite(motor_A_speed, 255);
  analogWrite(motor_B_speed, 255);

  // wait
  delay(wait_in_milliseconds);

  // stop
  analogWrite(motor_A_speed, 0);
  analogWrite(motor_B_speed, 0);
}

// move backward
void backward() {

  // set the direction to backward
  digitalWrite(motor_A, LOW);
  digitalWrite(motor_B, HIGH);

  // set to full speed
  analogWrite(motor_A_speed, 255);
  analogWrite(motor_B_speed, 255);

  // wait
  delay(wait_in_milliseconds);

  // stop
  analogWrite(motor_A_speed, 0);
  analogWrite(motor_B_speed, 0);
}

// turn left
void turnLeft() {

  // set the direction to backward
  digitalWrite(motor_A, HIGH);
  digitalWrite(motor_B, HIGH);

  // set to full speed
  analogWrite(motor_A_speed, 255);
  analogWrite(motor_B_speed, 255);

  // wait
  delay(wait_in_milliseconds);

  // stop
  analogWrite(motor_A_speed, 0);
  analogWrite(motor_B_speed, 0);
}

// turn right
void turnRight() {

  // set the direction to backward
  digitalWrite(motor_A, LOW);
  digitalWrite(motor_B, LOW);

  // set to full speed
  analogWrite(motor_A_speed, 255);
  analogWrite(motor_B_speed, 255);

  // wait
  delay(wait_in_milliseconds);

  // stop
  analogWrite(motor_A_speed, 0);
  analogWrite(motor_B_speed, 0);
}

// the main program loop
void motor_loop(){
  while (true) {

   int dist = ping();
   if (dist < 5) {
     turnLeft();
   }
   else {
     forward();
     // wait 
    delay(wait_in_milliseconds);
   }
    
  }
}
