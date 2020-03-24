/*
 * File Name:				triangle.h
 * Program Description:		A polygon class and derived classes for triangles and rectangles
 * Course Name:				Workshop in C++
 * Assignment Number:		6
 * Question Number:			2
 * Author:					Abraham Murciano
 */

#ifndef triangle_h
#define triangle_h

#include "polygon.h"
// using namespace std;

class triangle : public polygon {
  public:
	// Constructors
	triangle();
	triangle(int a, int b, int c);

	// Methods
	int getA() const;
	int getB() const;
	int getC() const;
	int getSide(int side) const;
	void setA(int val);
	void setB(int val);
	void setC(int val);
	void setSide(int side, int val);
};

#endif
