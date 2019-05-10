/*
 * File Name:				rectangle.h
 * Program Description:		A polygon class and derived classes for triangles and rectangles
 * Course Name:				Workshop in C++
 * Assignment Number:		6
 * Question Number:			2
 * Author:					Abraham Murciano
 */

#ifndef rectangle_h
#define rectangle_h

#include "polygon.h"
// using namespace std;

class rectangle : public polygon {
  public:
	// Constructors
	rectangle();
	rectangle(int a, int b);

	// Methods
	int getAC() const;
	int getBD() const;
	int getSide(int side) const;
	void setAC(int val);
	void setBD(int val);
	void setSide(int side, int val);
};

#endif
