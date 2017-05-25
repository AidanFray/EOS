#include "Movement.h"
#include "Distance_Sensors.h"
_movement Movement = _movement();

void _movement::move(int motorDelay) {
	digitalWrite(left2, HIGH);
	digitalWrite(right2, HIGH);
	delayMicroseconds(motorDelay);
	digitalWrite(left1, LOW);
	digitalWrite(right1, LOW);
	delayMicroseconds(motorDelay);
	digitalWrite(left3, HIGH);
	digitalWrite(right3, HIGH);
	delayMicroseconds(motorDelay);
	digitalWrite(left2, LOW);
	digitalWrite(right2, LOW);
	delayMicroseconds(motorDelay);
	digitalWrite(left4, HIGH);
	digitalWrite(right4, HIGH);
	delayMicroseconds(motorDelay);
	digitalWrite(left3, LOW);
	digitalWrite(right3, LOW);
	delayMicroseconds(motorDelay);
	digitalWrite(left1, HIGH);
	digitalWrite(right1, HIGH);
	delayMicroseconds(motorDelay);
	digitalWrite(left4, LOW);
	digitalWrite(right4, LOW);
	delayMicroseconds(motorDelay);
}
void _movement::right() {
	rightForwards();
	leftReverse();
}
void _movement::left()
{
	leftForwards();
	rightReverse();
}
void _movement::forward()
{
	leftForwards();
	rightForwards();
}
void _movement::reverse()
{
	leftReverse();
	rightReverse();
}

void _movement::leftForwards()
{ 
	left1 = 7; left2 = 6; left3 = 5; left4 = 4; 
}
void _movement::rightForwards()
{ 
	right1 = 8; right2 = 9; right3 = 10; right4 = 11; 
}
void _movement::leftReverse()
{ 
	left1 = 4; left2 = 5; left3 = 6; left4 = 7; 
}
void _movement::rightReverse()
{ 
	right1 = 11; right2 = 10; right3 = 9; right4 = 8; 
}