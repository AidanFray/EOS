#include "Distance.h"

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

bool huge_distance()
{

	//Evaluates
	bool leftOutOfRange = (leftS > out_of_range_val);
	bool rightOutOfRange = (rightS > out_of_range_val);

	if (leftOutOfRange && rightOutOfRange) {
		forward_move();
		return true;
	}
	else if (leftOutOfRange) {
		right_move();
		return true;
	}
	else if (rightOutOfRange)
	{
		left_move();
		return true;
	}

	return false;
}
