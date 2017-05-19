//version 2.0

#include "Distance_Sensors.h"
#include "Movement.h"

//Used to select what mode the robot is to run in
enum class Mode
{
	Auto_Movement,
	Manual_Control,
};

Mode opperation_mode = Mode::Auto_Movement; //Default

//Run at the start
void setup() {
  Movement.leftForwards();
  Movement.rightForwards();
  pinMode(Movement.left1, OUTPUT);
  pinMode(Movement.left2, OUTPUT);
  pinMode(Movement.left3, OUTPUT);
  pinMode(Movement.left4, OUTPUT);
  digitalWrite(Movement.left1, HIGH);
  pinMode(Movement.right1, OUTPUT);
  pinMode(Movement.right2, OUTPUT);
  pinMode(Movement.right3, OUTPUT);
  pinMode(Movement.right4, OUTPUT);
  digitalWrite(Movement.right1, HIGH);
  pinMode(3, OUTPUT);
  pinMode(2, INPUT);
  pinMode(12, OUTPUT);
  pinMode(13, INPUT);
  Serial.begin(9600);
}

//Operation loop that is end
void loop()
{
	switch (opperation_mode)
	{
	case Mode::Auto_Movement:
		Movement.loop();
	case Mode::Manual_Control:
		//-------------------//
		// Serial Code here  //
		//-------------------//
	default:
		break;
	}
}
