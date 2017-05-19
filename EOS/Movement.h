// Movement.h
#include "Distance_Sensors.h"
#ifndef _MOVEMENT_h
#define _MOVEMENT_h
class _movement
{
public:
	_movement() {};

	//Pin orders for left wheel
	float left1, left2, left3, left4;
	//Pin orders for right wheel
	float right1, right2, right3, right4;

	//Equates to speed. With 1200 being the max speed
	const int motorDelay = 1200;

	//Margin for error when determining if parallel
	const int range = 50;			

	//The loop for robot movement
	void loop();

	//Method moves the robot
	void move();

	//Methods change the direction
	void right();
	void left();
	void forward();
	void reverse();

	//These functions change the wheel directions
	void leftForwards();
	void rightForwards();
	void leftReverse();
	void rightReverse();
};
extern _movement Movement;

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#endif

