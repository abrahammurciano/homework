/*
 * File Name:				point.cpp
 * Program Description:		An implementation of a polygon class
 * Course Name:				Workshop in C++
 * Assignment Number:		3
 * Question Number:			3
 * Author:					Abraham Murciano
 */

#include "point.h"
#include "cmath"
using namespace std;

point::point() {
	x(0);
	y(0);
}

point::point(float X, float Y) {
	x(X);
	y(Y);
}

point::point(const point& p) {
	x(p.x());
	y(p.y());
}

float point::x() const {
	return X;
}

float point::y() const {
	return Y;
}

point& point::x(float X) {
	this->X = X;
	return *this;
}

point& point::y(float Y) {
	this->Y = Y;
	return *this;
}

float point::distance(const point& p) const {
	return sqrt((x() - p.x()) * (x() - p.x()) + (y() - p.y()) * (y() - p.y()));
}
