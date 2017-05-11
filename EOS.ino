#include "Movement.h"
#include "Distance.h"
#include "Variables.h"

//TODO: Refactor code

void setup() {
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
	pinMode(3, OUTPUT);
	pinMode(2, INPUT);
	pinMode(12, OUTPUT);
	pinMode(13, INPUT);
	Serial.begin(9600);
}

void loop() {
  //Distance sensors
  leftS = sensorLeftRead();
  rightS = sensorRightRead();

  for (int i = 0; i < 500; ++i)
  {
    //Margin of error before determining if the sensors are level
    int range = 50;

    //The smaller the difference, the more the sensors are level
    int diff = leftS - rightS;

    //If the robot is close to a surface
    if(!huge_distance())
    {
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

    forward_move();
  }
}


