/*
 * File Name:				rectangle.cpp
 * Program Description:		A polygon class and derived classes for triangles and rectangles
 * Course Name:				Workshop in C++
 * Assignment Number:		6
 * Question Number:			2
 * Author:					Abraham Murciano
 */

#include "rectangle.h"

// Default Constructor
rectangle::rectangle() {}

// Constructor
rectangle::rectangle(int a, int b) {
	sides = new int[numSides = 4];
	setAC(a);
	setBD(b);
}

// Get sides A and C
int rectangle::getAC() const {
	return getSide(0);
}

// Get sides B and D
int rectangle::getBD() const {
	return getSide(1);
}

// Get given side
int rectangle::getSide(int side) const {
	if (side < 0 || side > 3) {
		throw "Error: Can only get sides 0 to 3 of rectangle.";
	}
	return sides[side];
}

// Set sides A and C
void rectangle::setAC(int val) {
	setSide(0, val);
}

// Set sides B and D
void rectangle::setBD(int val) {
	setSide(1, val);
}

// Set a given side and the opposite side
void rectangle::setSide(int side, int val) {
	if (side < 0 || side > 3) {
		throw "Error: Can only set sides 0 to 3 of rectangle.";
	}
	if (val <= 0) {
		throw "Error: Polygons cannot have sides with a negative length.";
	}
	sides[(side + 2) % 4] = sides[side] = val;
}