/*
 * File Name:				point.h
 * Program Description:		An implementation of a polygon class
 * Course Name:				Workshop in C++
 * Assignment Number:		3
 * Question Number:			3
 * Author:					Abraham Murciano
 */

#ifndef point_h
#define point_h

//#include <iostream>
// using namespace std;

class point {
  private:
	float X;
	float Y;

  public:
	point();
	point(float X, float Y);
	point(const point& p);
	float x() const;
	float y() const;
	point& x(float X);
	point& y(float Y);
	float distance(const point& p) const;
};

#endif
