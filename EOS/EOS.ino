//version 2.2
#include "WiFi_Movement.h"
#include "Auto_Movement.h"
#include "Serial_Turn.h"
#include "Distance_Sensors.h"
#include "Movement.h"

//Used to select what mode the robot is to run in
enum class Mode
{
	Auto_Movement,
	Manual_Control,
	WiFi_Control
};

//----------------CHANGE ME TO SWITCH MODES--------------//
Mode opperation_mode = Mode::WiFi_Control;              //
//-------------------------------------------------------//

//Setup
void setup() 
{
	//TODO: Add method that asks user to select a mode

	switch (opperation_mode)
	{
	case Mode::Auto_Movement:
		AutoMovement.setup();
	case Mode::Manual_Control:
		Manual_Control.setup();
	case Mode::WiFi_Control:
		WiFi_Movement.setup();
	default:
		break;
	}
}

//Main loop
void loop()
{
	switch (opperation_mode)
	{
	case Mode::Auto_Movement:
		AutoMovement.loop();
	case Mode::Manual_Control:
		Manual_Control.loop();
	case Mode::WiFi_Control:
		WiFi_Movement.loop();
	default:
		break;
	}
}
