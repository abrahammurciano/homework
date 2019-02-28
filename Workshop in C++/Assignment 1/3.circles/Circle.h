/*
 * File Name:				Circle.h
 * Program Description:		Calculates area and circumference of 3 circles and calculates if any
 * point is inside the circles
 * Course Name:				Workshop in C++
 * Assignment Number:		1
 * Question Number:			3
 * Author:					Abraham Murciano
 */

#ifndef Circle_h
#define Circle_h

#include "Point.h"

const float PI = 3.14;

class Circle {
  private:
	Point center;
	float radius;

  public:
	Circle();
	Circle(Point _center, float _radius);
	Point getCenter();
	float getRadius();
	void setCenter(Point _center);
	float area();
	float circumference();
	int outside(Point p);
};

#endif
