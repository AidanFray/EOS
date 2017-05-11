//motor functions
int motorDelay;

//Pins for left and right wheels
byte left1, left2, left3, left4;
byte right1, right2, right3, right4;

void setup() {
  //Sets up directions for wheels
  leftForwards();
  rightForwards();

  pinMode(left1, OUTPUT);
  pinMode(left2, OUTPUT);
  pinMode(left3, OUTPUT);
  pinMode(left4, OUTPUT);
  digitalWrite(left1, HIGH);
  pinMode(right1, OUTPUT);
  pinMode(right2, OUTPUT);
  pinMode(right3, OUTPUT);
  pinMode(right4, OUTPUT);
  digitalWrite(right1, HIGH);

  motorDelay = 1200;

  pinMode(3, OUTPUT);
  pinMode(2, INPUT);
  pinMode(12, OUTPUT);
  pinMode(13, INPUT);
  Serial.begin(9600);
}

//These methods change the direction the wheels travel
void leftForwards()
{
  left1 = 7; left2 = 6; left3 = 5; left4 = 4;
}
void leftReverse()
{
  left1 = 4; left2 = 5; left3 = 6; left4 = 7;
}
void rightForwards()
{
  right1 = 8; right2 = 9; right3 = 10; right4 = 11;
}
void rightReverse()
{
  right1 = 11; right2 = 10; right3 = 9; right4 = 8;
}

//Methods that record data from the sensors
float sensorLeftRead()
{
  digitalWrite(12, LOW);
  delayMicroseconds(2);
  digitalWrite(12, HIGH);
  delayMicroseconds(10);
  digitalWrite(12, LOW);
  return pulseIn(13, HIGH);
}
float sensorRightRead()
{
  digitalWrite(3, LOW);
  delayMicroseconds(2);
  digitalWrite(3, HIGH);
  delayMicroseconds(10);
  digitalWrite(3, LOW);
  return pulseIn(2, HIGH);
}

//Will cause motion in the set direction the wheels are set
void move()
{
  digitalWrite(left2, HIGH);
  digitalWrite(right2, HIGH);
  delayMicroseconds(motorDelay);
  digitalWrite(left1, LOW);
  digitalWrite(right1, LOW);
  delayMicroseconds(motorDelay);
  digitalWrite(left3, HIGH);
  digitalWrite(right3, HIGH);
  delayMicroseconds(motorDelay);
  digitalWrite(left2, LOW);
  digitalWrite(right2, LOW);
  delayMicroseconds(motorDelay);
  digitalWrite(left4, HIGH);
  digitalWrite(right4, HIGH);
  delayMicroseconds(motorDelay);
  digitalWrite(left3, LOW);
  digitalWrite(right3, LOW);
  delayMicroseconds(motorDelay);
  digitalWrite(left1, HIGH);
  digitalWrite(right1, HIGH);
  delayMicroseconds(motorDelay);
  digitalWrite(left4, LOW);
  digitalWrite(right4, LOW);
  delayMicroseconds(motorDelay);
}

//Moves the robot left
void right_move()
{
  rightForwards();
  leftReverse();
  move();
}

//Moves the robot right
void left_move()
{
  leftForwards();
  rightReverse();
  move();
}

//Moves the robot straight forward
void forward_move()
{
  leftForwards();
  rightForwards();
  move();
}

//Moves the robot straight backwards
void reverse_move()
{
  leftReverse();
  rightReverse();
  move();
}

//Holds the data for the sensor readings
float leftS;
float rightS;

void loop() {

  //Distance sensors
  leftS = sensorLeftRead();
  rightS = sensorRightRead();

  for (int i = 0; i < 5; ++i)
  {
    int range = 50;
    int out_of_range_val = 3000;
    int diff = leftS - rightS;

    //If the robots position doesn't need adjusting
    if (abs(diff) < range)
    {
      forward_move();
    }
    //If the right side needs adjusting
    else if (diff > 0)
    {
      right_move();
    }
    //If the left side needs adjusting
    else
    {
      left_move();
    }

  }
}
