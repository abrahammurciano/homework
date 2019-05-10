/*
 * File Name:				triangle.cpp
 * Program Description:		A polygon class and derived classes for triangles and rectangles
 * Course Name:				Workshop in C++
 * Assignment Number:		6
 * Question Number:			2
 * Author:					Abraham Murciano
 */

#include "triangle.h"

// Default Constructor
triangle::triangle() {}

// Constructor
triangle::triangle(int a, int b, int c) {
	sides = new int[numSides = 3];
	setA(a);
	setB(b);
	setC(c);
}

// Get side A
int triangle::getA() const {
	return getSide(0);
}

// Get side B
int triangle::getB() const {
	return getSide(1);
}

// Get side C
int triangle::getC() const {
	return getSide(2);
}

// Get given side
int triangle::getSide(int side) const {
	if (side < 0 || side > 2) {
		throw "Error: Can only get sides 0 to 2 of triangle.";
	}
	return sides[side];
}

// Set side A
void triangle::setA(int val) {
	setSide(0, val);
}

// Set side B
void triangle::setB(int val) {
	setSide(1, val);
}

// Set side C
void triangle::setC(int val) {
	setSide(2, val);
}

// Set a given side
void triangle::setSide(int side, int val) {
	if (side < 0 || side > 2) {
		throw "Error: Can only set sides 0 to 2 of triangle.";
	}
	if (val <= 0) {
		throw "Error: Polygons cannot have sides with a negative length.";
	}
	sides[side] = val;
}