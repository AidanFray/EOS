//version 2.1
#include "Auto_Movement.h"
#include "Serial_Turn.h"
#include "Distance_Sensors.h"
#include "Movement.h"

//Used to select what mode the robot is to run in
enum class Mode
{
	Auto_Movement,
	Manual_Control,
};

//----------------CHANGE ME TO SWITCH MODES--------------//
Mode opperation_mode = Mode::Auto_Movement;              //
//-------------------------------------------------------//

//Setup
void setup() 
{
	switch (opperation_mode)
	{
	case Mode::Auto_Movement:
		AutoMovement.setup();
	case Mode::Manual_Control:
		Manual_Control.setup();
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
	default:
		break;
	}
}
