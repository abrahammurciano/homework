/*
 * File Name:				polygon.cpp
 * Program Description:		An implementation of a polygon class
 * Course Name:				Workshop in C++
 * Assignment Number:		3
 * Question Number:			3
 * Author:					Abraham Murciano
 */

#include "polygon.h"
//#include "iostream"
// using namespace std;

polygon::polygon() {
	capacity = 4;
	vertices = new point[capacity];
	n = 0;
}

polygon::polygon(const polygon& p) {
	delete[] vertices;
	capacity = p.capacity;
	vertices = new point[capacity];
	n = p.n;
	for (int i = 0; i < n; i++) {
		vertices[i] = p[i];
	}
}

polygon::~polygon() {
	delete[] vertices;
}

polygon& polygon::operator<<(const point& p) {
	if (n >= capacity) {
		point* temp = vertices;
		vertices = new point[capacity *= 2];
		for (int i = 0; i < n; i++) {
			vertices[i] = temp[i];
		}
	}
	vertices[n++] = p;
	return *this;
}

point& polygon::operator[](int i) const {
	return vertices[i];
}

float polygon::perimeter() const {
	float perimeter = 0;
	if (n > 1) {
		for (int i = 0; i < n - 1; i++) {
			perimeter += vertices[i].distance(vertices[i + 1]);
		}
		perimeter += vertices[n - 1].distance(vertices[0]);
	}
	return perimeter;
}