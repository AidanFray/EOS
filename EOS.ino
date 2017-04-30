


  /*

  Old motor setup with dual sensor read.

  Attempting to modulate motor speed depending on sensor read.

  */

  //motor functions
  int motorDelay;

  byte left1, left2, left3, left4;

  byte right1, right2, right3, right4;

  int moveCount; // Counter for the number of steps

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

  //sensor
  //left hand sensor trig = 3 & echo = 2
  //right hand sensor trig = 12 & echo = 13

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

  void forward()
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

  void left_move()
  {
    digitalWrite(left2, HIGH);
    digitalWrite(right4, HIGH);
    delayMicroseconds(motorDelay);
    digitalWrite(left1, LOW);
    digitalWrite(right1, LOW);
    delayMicroseconds(motorDelay);
    digitalWrite(left3, HIGH);
    digitalWrite(right3, HIGH);
    delayMicroseconds(motorDelay);
    digitalWrite(left2, LOW);
    digitalWrite(right4, LOW);
    delayMicroseconds(motorDelay);
    digitalWrite(left4, HIGH);
    digitalWrite(right2, HIGH);
    delayMicroseconds(motorDelay);
    digitalWrite(left3, LOW);
    digitalWrite(right3, LOW);
    delayMicroseconds(motorDelay);
    digitalWrite(left1, HIGH);
    digitalWrite(right1, HIGH);
    delayMicroseconds(motorDelay);
    digitalWrite(left4, LOW);
    digitalWrite(right2, LOW);
    delayMicroseconds(motorDelay);
  }

  void right_move()
  {
    digitalWrite(left4, HIGH);
    digitalWrite(right2, HIGH);
    delayMicroseconds(motorDelay);
    digitalWrite(left1, LOW);
    digitalWrite(right1, LOW);
    delayMicroseconds(motorDelay);
    digitalWrite(left3, HIGH);
    digitalWrite(right3, HIGH);
    delayMicroseconds(motorDelay);
    digitalWrite(left4, LOW);
    digitalWrite(right2, LOW);
    delayMicroseconds(motorDelay);
    digitalWrite(left2, HIGH);
    digitalWrite(right4, HIGH);
    delayMicroseconds(motorDelay);
    digitalWrite(left3, LOW);
    digitalWrite(right3, LOW);
    delayMicroseconds(motorDelay);
    digitalWrite(left1, HIGH);
    digitalWrite(right1, HIGH);
    delayMicroseconds(motorDelay);
    digitalWrite(left2, LOW);
    digitalWrite(right4, LOW);
    delayMicroseconds(motorDelay);
  }

  void setup() {

    //motor

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

    moveCount = 0; // Set the counter to 0

             //sensors

    pinMode(3, OUTPUT);
    pinMode(2, INPUT);
    pinMode(12, OUTPUT);
    pinMode(13, INPUT);
    Serial.begin(9600);

  }

  float leftS;
  float rightS;
  void loop() {

    leftS = sensorLeftRead();
    rightS = sensorRightRead();

    for (int i = 0; i < 20; ++i)
    {
      int range = 100;
      int diff = leftS - rightS;

      if (abs(diff) < range)
      {
        forward();
      }
      else if (diff > 0)
      {
        right_move();
      }
      else
      {
        left_move();
      }
    }
  }
