#include "Movement.h"

void leftForwards()
{
	left1 = 7; left2 = 6; left3 = 5; left4 = 4;
}

void leftReverse()
{
	right1 = 8; right2 = 9; right3 = 10; right4 = 11;
}

void rightForwards()
{
	right1 = 8; right2 = 9; right3 = 10; right4 = 11;
}

void rightReverse()
{
	right1 = 11; right2 = 10; right3 = 9; right4 = 8;
}

//Movements controls
void move()
{
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
void right_move()
{
	rightForwards();
	leftReverse();
	move();
}
void left_move()
{
	leftForwards();
	rightReverse();
	move();
}
void forward_move()
{
	leftForwards();
	rightForwards();
	move();
}
void reverse_move()
{
	leftReverse();
	rightReverse();
	move();
}

