#include "WiFi_Movement.h"

WiFi_MovementClass WiFi_Movement;

void WiFi_MovementClass::setup()
{
	Movement.leftForwards();
	Movement.rightForwards();

	//Sets all the pins
	pinMode(Movement.left1, OUTPUT);
	pinMode(Movement.left2, OUTPUT);
	pinMode(Movement.left3, OUTPUT);
	pinMode(Movement.left4, OUTPUT);
	pinMode(Movement.right1, OUTPUT);
	pinMode(Movement.right2, OUTPUT);
	pinMode(Movement.right3, OUTPUT);
	pinMode(Movement.right4, OUTPUT);

	pinMode(A0, INPUT);
	pinMode(A1, INPUT);
	pinMode(A2, INPUT);
	pinMode(A3, INPUT);


}

void WiFi_MovementClass::loop()
{
	//Responses from the ESP8266 board
	int up = analogRead(A0);
	int down = analogRead(A1);
	int left = analogRead(A2);
	int right = analogRead(A3);

	Serial.write(up);
	Serial.write(up);
	Serial.write(up);
	Serial.write(up);



	if (up > PinOn)
	{
		for (int i = 0; i < moveAmount; i++)
		{
			Movement.forward();
			Movement.move(1200);
		}
	}
	else if (down > PinOn)
	{
		for (int i = 0; i < moveAmount; i++)
		{
			Movement.reverse();
			Movement.move(1200);
		}
	}
	else if (left > PinOn)
	{
		for (int i = 0; i < moveAmount; i++)
		{
			Movement.left();
			Movement.move(1200);
		}
	}
	else if (right > PinOn)
	{
		for (int i = 0; i < moveAmount; i++)
		{
			Movement.right();
			Movement.move(1200);
		}
	}

	TurnPinsOff();
}

void WiFi_MovementClass::TurnPinsOff()
{
	for (int i = 4; i <= 11; i++)
	{
		digitalWrite(i, LOW);
	}
}
