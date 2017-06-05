#include "Auto_Movement.h"
Auto_Movement AutoMovement;

void Auto_Movement::setup()
{
	//TODO: Re-factor and comment this
	Movement.leftForwards();
	Movement.rightForwards();
	pinMode(Movement.left1, OUTPUT);
	pinMode(Movement.left2, OUTPUT);
	pinMode(Movement.left3, OUTPUT);
	pinMode(Movement.left4, OUTPUT);
	digitalWrite(Movement.left1, HIGH);
	pinMode(Movement.right1, OUTPUT);
	pinMode(Movement.right2, OUTPUT);
	pinMode(Movement.right3, OUTPUT);
	pinMode(Movement.right4, OUTPUT);
	digitalWrite(Movement.right1, HIGH);
	pinMode(3, OUTPUT);
	pinMode(2, INPUT);
	pinMode(12, OUTPUT);
	pinMode(13, INPUT);
	Serial.begin(9600);
}

void Auto_Movement::loop()
{
	//Distance sensors
	Sensor.sensorLeftRead();
	Sensor.sensorRightRead();

	for (int i = 0; i < 5; ++i)
	{
		//The smaller the difference, the more the sensors are level
		int diff = Sensor.leftSensorValue - Sensor.rightSensorValue;

		//If the robot is close to a surface
		if ((!Sensor.huge_distance()))
		{
			//If the robots position doesn't need adjusting
			if (abs(diff) < range)
			{
				Movement.forward();
				Movement.move(motorDelay);
			}
			//If the right side needs adjusting
			else if (diff > 0)
			{
				Movement.right();
				Movement.move(motorDelay);
			}
			//If the left side needs adjusting
			else
			{
				Movement.left();
				Movement.move(motorDelay);
			}
		}
	}
}
