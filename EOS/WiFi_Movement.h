// WiFi_Movement.h
#include "Movement.h"

#ifndef _WIFI_MOVEMENT_h
#define _WIFI_MOVEMENT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class WiFi_MovementClass
{
 public:
	 void setup();
	 void loop();

private:
	int PinOn = 400; 
	int moveAmount = 100; //How many loops the movement code performs

	void TurnPinsOff();
};

extern WiFi_MovementClass WiFi_Movement;

#endif

