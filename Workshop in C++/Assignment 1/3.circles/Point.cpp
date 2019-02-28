/*
 * File Name:				Point.cpp
 * Program Description:		Calculates area and circumference of 3 circles and calculates if any
 * point is inside the circles
 * Course Name:				Workshop in C++
 * Assignment Number:		1
 * Question Number:			3
 * Author:					Abraham Murciano
 */

#ifndef Point_cpp
#define Point_cpp

#include "Point.h"
using namespace std;

Point::Point() {
	x = 0;
	y = 0;
}

Point::Point(float _x, float _y) {
	x = _x;
	y = _y;
}

#endif