#include "Movement.h"
#ifndef _SERIAL_TURN_h
#define _SERIAL_TURN_h

class _manual
{
public:
	void setup();
	void loop();

	float wheelDiameter = 68.5;
	float stepsPerRevolution = 512;
	float mmsPerStep = (wheelDiameter * 3.1416) / stepsPerRevolution;
	float wheelDistance = 90;
	float turnCircleDist = (wheelDistance * 3.1416);
	float stepsPerTurn = turnCircleDist / mmsPerStep;
	
	int motorDelay;
	int moveCount;
	int moveSteps;// number of steps the motor is to move
	int angle;
	int distanceInMM;
	int distance;
	int speed;
	int repeatCount;

	int number = 0;
	String command = "";
	String instruction = "";
	String confirmationMessage = "";
	int commandTrigger = 0;

	String get_command();

	int get_md_number();

	int motorDelayCalc();

	int calculateDistanceSteps(float distanceInMM);

	int calculateAngleSteps(float angle);

	int stopMove();
	
	void flush_buffer();

};
extern _manual Manual_Control;

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#endif

