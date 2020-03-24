/*
 * File Name:				polygon.h
 * Program Description:		A polygon class and derived classes for triangles and rectangles
 * Course Name:				Workshop in C++
 * Assignment Number:		6
 * Question Number:			2
 * Author:					Abraham Murciano
 */

#ifndef polygon_h
#define polygon_h

#include <stdlib.h>
using namespace std;

class polygon {
  protected:
	// Data
	int numSides;
	int* sides;

  public:
	// Constructors
	polygon();
	polygon(int numSides);
	polygon(const polygon& poly);
	~polygon();

	// Methods
	void input(int numSides);
	int getNumSides() const;
	int* getSides() const;
	int perimeter() const;

	// Operators
	bool operator==(const polygon& poly) const;
	bool operator!=(const polygon& poly) const;
};

#endif
