#pragma once
#include "Movement.h"

//Holds the data for the sensor readings
float leftS;
float rightS;

//Methods that record data from the sensors
float sensorLeftRead();
float sensorRightRead();
int out_of_range_val = 5000;
bool huge_distance();
