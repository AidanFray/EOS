// Distance_Sensors.h
#ifndef _DISTANCE_SENSORS_h
#define _DISTANCE_SENSORS_h
class _sensors
{
public:
	_sensors() {};

	//Integer that provides a cut-off for the distance
	const int out_of_range_val = 5000;

	//Value for distance for the left and right sensors
	float leftSensorValue;
	float rightSensorValue;

	//Methods below return data from the sensors
	void sensorLeftRead();
	void sensorRightRead();

	//Method that deals with distances over the cut-off point
	bool huge_distance();
};
extern _sensors Sensor;

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#endif

