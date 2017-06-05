#include "Serial_Turn.h"
_manual Manual_Control = _manual();

void _manual::setup()
{
	flush_buffer();

	Movement.leftForwards();
	Movement.rightForwards();

	pinMode(Movement.left1, OUTPUT);
	pinMode(Movement.left2, OUTPUT);
	pinMode(Movement.left3, OUTPUT);
	pinMode(Movement.left4, OUTPUT);

	pinMode(Movement.right1, OUTPUT);
	pinMode(Movement.right2, OUTPUT);
	pinMode(Movement.right3, OUTPUT);
	pinMode(Movement.right4, OUTPUT);

	motorDelay = 2000;
	angle = 0;
	moveCount = 0;

	Serial.begin(9600);
}
void _manual::loop()
{
	if(commandTrigger == 0) {
		command = "";
		number = 0;
		command = get_command();
	}
	if (commandTrigger == 1) {
		if (command == "A" || command == "D") {

			instruction = "\n\nEnter the angle you'd like to turn in degrees\n";
			confirmationMessage = "\n\nThanks you've set the angle in degrees to ";
			number = get_md_number();
			angle = number;

			if (number>0) {
				Serial.print(confirmationMessage);
				Serial.println(number);
				Serial.print("\n\nType 'Q' and press enter to stop motion\n\nmoving...\n\n");
				delay(1000);
			}

			if (command == "A") {
				moveSteps = calculateAngleSteps(angle);
				Movement.leftForwards();
			}
			else if (command == "D") {
				moveSteps = calculateAngleSteps(angle);
				Movement.rightForwards();
			}
		}
		else if (command == "W" || command == "S") {

			instruction = "\n\nEnter the distance you'd like to move in mm\n";
			confirmationMessage = "\n\nThanks you've set the distance in mm to ";
			number = get_md_number();
			distanceInMM = number;

			if (number>0) {
				Serial.print(confirmationMessage);
				Serial.println(number);
				Serial.print("\n\nType 'Q' and press enter to stop motion\n\nmoving...\n\n");
				delay(1000);
			}

			if (command == "W") {
				moveSteps = calculateDistanceSteps(distanceInMM);
				Movement.forward();
			}
			else if (command == "S") {
				moveSteps = calculateDistanceSteps(distanceInMM);
				Movement.reverse();
			}
		}
		else if (command == "X") {

			instruction = "\n\nEnter the speed you'd like to set from 0-10\n";
			confirmationMessage = "\n\nThanks you've set the speed to ";
			number = get_md_number();
			motorDelay = motorDelayCalc();
			Serial.print(confirmationMessage);
			Serial.println(number);
		}
		else if (command == "R") {
			Serial.print("\n\nRepeating last action\n\nmoving...\n\n");
			moveSteps = repeatCount;
			commandTrigger = 0;
		}
	}
	repeatCount = moveCount;

	while (moveCount<moveSteps) {

		moveCount = moveCount + 1;

		Movement.move(motorDelay);
		if (Serial.available() > 0) {
			byte incoming = Serial.read();
			String input = "";
			input = char(incoming);
			input.toUpperCase();

			if (input == "Q") {
				stopMove();
			}
			else if (input == "A") {
				Movement.leftForwards();
			}
			else if (input == "D") {
				Movement.rightForwards();
			}
			else if (input == "W") {
				Movement.forward();
			}
			else if (input == "S") {
				Movement.reverse();
			}
			else if (input == "X") {
				instruction = "\n\nEnter the speed you'd like to set from 0-10\n";
				confirmationMessage = "\n\nThanks you've set the speed to ";
				number = get_md_number();
				motorDelay = motorDelayCalc();
				Serial.print(confirmationMessage);
				Serial.println(number);
			}
			else {
				while (Serial.available() > 0) {  //flush the buffer to prevent junk data being passed anywhere if greater than 0
					Serial.read(); delay(100);
				}
			}
		}
	}
	repeatCount = moveSteps;
	moveCount = 0;
	moveSteps = 0;
	angle = 0;
	distance = 0;
	distanceInMM = 0;
	instruction = "";
	confirmationMessage = "";
	digitalWrite(Movement.left1, LOW);
	digitalWrite(Movement.right1, LOW);
}

String _manual::get_command()
{
	Serial.print("\nType a command and press enter\n\nA = Turn Left.\nD = Turn Right.\nW = Move Forward.\nS = Move Backwards.\nX = Set speed.\nR = Repeat last action.\n");

	flush_buffer();

	//Do nothing
	while (Serial.available() == 0);
	
	while (Serial.available() > 0) 
	{
		String input = String(Serial.read());
		input.toUpperCase();

		//looks for a value ( valid number - outside 0 -9) in the specified ASCII range
		if (input == "A" || input == "D" || input == "S" || input == "W" || input == "X" || input == "R") 
		{
			command = input;
			Serial.print("\n\nThanks this command you've chosen is: " + command);
			commandTrigger = 1;

			flush_buffer();
		}
		else {

			Serial.println("\nInvalid entry! Try again.\n"); //if not valid number returns an error
			flush_buffer();
		}
	}
	return command;
}
int _manual::get_md_number()
{
	Serial.print(instruction);
	number = 0;

	flush_buffer();
	while (Serial.available() == 0);
	
	while (Serial.available() > 0) {

		byte incoming = Serial.read();

		//looks for a value ( valid number 0 - 9) in the specified ACSII range
		if (incoming >= '0' && incoming <= '9') { 
			number = (number * 10) + (incoming - '0'); 
			delay(50);
			commandTrigger = 0;
		}
		else {

			Serial.println("\nInvalid entry! Try again.\n"); //if not valid number returns an error
			flush_buffer();
		}
	}
	return number;
}

int _manual::motorDelayCalc()
{
	if (number > 10) {
		number = number / number;
	}
	motorDelay = 2200 - (1000 * number / 10);
	return motorDelay;
}

int _manual::calculateDistanceSteps(float distanceInMM)
{
	return distanceInMM / mmsPerStep + 0.5;
}

int _manual::calculateAngleSteps(float angle)
{
	return stepsPerTurn / 360 * angle + 0.5;
}

int _manual::stopMove()
{
	moveCount = moveSteps;
	Serial.print("\n\nMovement has been stopped!\n\n");
	flush_buffer();
}

void _manual::flush_buffer()
{
	//flush the buffer to prevent junk data being passed anywhere if greater than 0
	while (Serial.available() > 0) {  
		Serial.read(); 
		delay(100);
	}
}
