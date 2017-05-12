#include "Distance_Sensors.h"
#include "Movement.h"

//Methods that record data from the sensors

_sensors Sensor = _sensors();

void _sensors::sensorLeftRead()
{
	digitalWrite(12, LOW);
	delayMicroseconds(2);
	digitalWrite(12, HIGH);
	delayMicroseconds(10);
	digitalWrite(12, LOW);
	leftS = pulseIn(13, HIGH);
}
void _sensors::sensorRightRead()
{
	digitalWrite(3, LOW);
	delayMicroseconds(2);
	digitalWrite(3, HIGH);
	delayMicroseconds(10);
	digitalWrite(3, LOW);
	rightS = pulseIn(2, HIGH);
}

bool _sensors::huge_distance()
{
	//Evaluates
	bool leftOutOfRange = (Sensor.leftS > out_of_range_val);
	bool rightOutOfRange = (Sensor.rightS > out_of_range_val);

	if (leftOutOfRange && rightOutOfRange) {
		Movement.forward();
		return true;
	}
	else if (leftOutOfRange) {
		Movement.right();
		return true;
	}
	else if (rightOutOfRange)
	{
		Movement.left();
		return true;
	}

	return false;
}
