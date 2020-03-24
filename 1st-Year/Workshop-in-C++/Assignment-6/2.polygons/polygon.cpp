/*
 * File Name:				polygon.cpp
 * Program Description:		A polygon class and derived classes for triangles and rectangles
 * Course Name:				Workshop in C++
 * Assignment Number:		6
 * Question Number:			2
 * Author:					Abraham Murciano
 */

#include "polygon.h"
#include "iostream"
using namespace std;

// Default constructor
polygon::polygon() {
	numSides = 0;
	sides = NULL;
}

// Constructor
polygon::polygon(int numSides) {
	try {
		input(numSides);
	} catch (const char* e) {
		*this = polygon();
		throw e;
	}
}

// Copy constructor
polygon::polygon(const polygon& poly) {
	numSides = poly.numSides;
	sides = new int[numSides];
	for (int i = 0; i < numSides; i++) {
		sides[i] = poly.sides[i];
	}
}

// Destructor
polygon::~polygon() {
	if (sides != NULL) {
		delete[] sides;
	}
}

void polygon::input(int numSides) {
	if (numSides < 3) {
		throw "Error: Polygon must have at least 3 sides";
	}
	this->numSides = numSides;
	sides = new int[numSides];
	cout << "enter sides for polygon:" << endl;
	for (int i = 0; i < numSides; i++) {
		cin >> sides[i];
		if (sides[i] <= 0) {
			throw "Error: Polygons cannot have sides with a negative length.";
		}
	}
}

// Get number of sides
int polygon::getNumSides() const {
	return numSides;
}

// Get array of side lengths
int* polygon::getSides() const {
	return sides;
}

// Returns the perimeter of the polygon
int polygon::perimeter() const {
	int perimeter = 0;
	for (int i = 0; i < numSides; i++) {
		perimeter += sides[i];
	}
	return perimeter;
}

// Checks if two polygons have the same number of sides and the same perimeter
bool polygon::operator==(const polygon& poly) const {
	if (numSides != poly.numSides) {
		return false;
	}
	return perimeter() == poly.perimeter();
}

// Checks if two polygons have the same number of sides and the same perimeter
bool polygon::operator!=(const polygon& poly) const {
	return !(*this == poly);
}
