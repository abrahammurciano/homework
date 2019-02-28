/*
 * File Name:				Circle.cpp
 * Program Description:		Calculates area and circumference of 3 circles and calculates if any
 * point is inside the circles
 * Course Name:				Workshop in C++
 * Assignment Number:		1
 * Question Number:			3
 * Author:					Abraham Murciano
 */

#ifndef Circle_cpp
#define Circle_cpp

#include "Circle.h"
#include "Point.h"
#include <math.h>

Circle::Circle() {
	center = Point();
	radius = 0;
}

Circle::Circle(Point _center, float _radius) {
	center = _center;
	radius = _radius;
}

Point Circle::getCenter() {
	return center;
}

float Circle::getRadius() {
	return radius;
}

void Circle::setCenter(Point _center) {
	center = _center;
}

float Circle::area() {
	return PI * radius * radius;
}

float Circle::circumference() {
	return 2 * PI * radius;
}

int Circle::outside(Point p) {
	float d = sqrt((center.x - p.x) * (center.x - p.x) + (center.y - p.y) * (center.y - p.y));
	if (d > radius) {
		return 1;
	} else if (d < radius) {
		return -1;
	} else {
		return 0;
	}
}

#endif