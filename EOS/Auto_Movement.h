// Auto_Movement.h
#include "Movement.h"

#ifndef _AUTO_MOVEMENT_h
#define _AUTO_MOVEMENT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class Auto_Movement
{
 public:
	 //Equates to speed. With 1200 being the max speed
	 const int motorDelay = 1200;

	 //Margin for error when determining if parallel
	 const int range = 50;

	 void setup();
	 void loop();
};

extern Auto_Movement AutoMovement;

#endif

