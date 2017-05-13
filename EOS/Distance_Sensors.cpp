#include "Distance_Sensors.h"
#include "Movement.h"
_sensors Sensor = _sensors();

void _sensors::sensorLeftRead()
{
	digitalWrite(12, LOW);
	delayMicroseconds(2);
	digitalWrite(12, HIGH);
	delayMicroseconds(10);
	digitalWrite(12, LOW);
	leftSensorValue = pulseIn(13, HIGH);
}
void _sensors::sensorRightRead()
{
	digitalWrite(3, LOW);
	delayMicroseconds(2);
	digitalWrite(3, HIGH);
	delayMicroseconds(10);
	digitalWrite(3, LOW);
	rightSensorValue = pulseIn(2, HIGH);
}

bool _sensors::huge_distance()
{
	bool leftOutOfRange = (leftSensorValue > out_of_range_val);
	bool rightOutOfRange = (rightSensorValue > out_of_range_val);

	//If both sensors are out of range
	if (leftOutOfRange && rightOutOfRange) {
		Movement.forward();
		return true;
	}
	//If just the left sensor is out of range
	else if (leftOutOfRange) {
		Movement.right();
		return true;
	}
	//If just the right sensor is out of range
	else if (rightOutOfRange)
	{
		Movement.left();
		return true;
	}

	return false;
}
