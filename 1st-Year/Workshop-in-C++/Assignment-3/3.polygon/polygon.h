/*
 * File Name:				polygon.h
 * Program Description:		An implementation of a polygon class
 * Course Name:				Workshop in C++
 * Assignment Number:		3
 * Question Number:			3
 * Author:					Abraham Murciano
 */

#ifndef polygon_h
#define polygon_h

#include "point.h"
//#include <iostream>
// using namespace std;

class polygon {
  private:
	point* vertices;
	int n;
	int capacity;

  public:
	polygon();
	polygon(const polygon& p);
	~polygon();
	polygon& operator<<(const point& p);
	point& operator[](int i) const;
	float perimeter() const;
};

#endif
