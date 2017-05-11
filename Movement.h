#pragma once
#include "Variables.h"

//These methods change the direction the wheels travel
void leftForwards();
void leftReverse();
void rightForwards();
void rightReverse();

//Will cause motion in the set direction the wheels are set
void move();

//Moves the robot left
void right_move();

//Moves the robot right
void left_move();

//Moves the robot straight forward
void forward_move();

//Moves the robot straight backwards
void reverse_move();

