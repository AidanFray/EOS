// Distance_Sensors.h


#ifndef _DISTANCE_SENSORS_h
#define _DISTANCE_SENSORS_h

class _sensors
{
public:
	_sensors() {};

	float leftS;
	float rightS;

	void sensorLeftRead();
	void sensorRightRead();

	const int out_of_range_val = 5000;
	bool huge_distance();
};
extern _sensors Sensor;

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#endif

