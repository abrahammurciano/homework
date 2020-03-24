/*
 * File Name:				main.cpp
 * Program Description:		A polygon class and derived classes for triangles and rectangles
 * Course Name:				Workshop in C++
 * Assignment Number:		6
 * Question Number:			2
 * Author:					Abraham Murciano
 */

#include "polygon.h"
#include "rectangle.h"
#include "triangle.h"
#include <iostream>
using namespace std;

polygon inputPolygon(int n) {
	if (n == 3) {
		cout << "enter sides for polygon:" << endl;
		int a, b, c;
		cin >> a >> b >> c;
		return triangle(a, b, c);
	} else if (n == 4) {
		cout << "enter sides for polygon:" << endl;
		int a, b;
		cin >> a >> b;
		return rectangle(a, b);
	} else {
		return polygon(n);
	}
}

int main() {
	try {
		cout << "enter number of sides for polygon 1:" << endl;
		int a;
		cin >> a;
		polygon shape1 = inputPolygon(a);
		cout << "enter number of sides for polygon 2:" << endl;
		int b;
		cin >> b;
		if (a != b) {
			cout << "not equal" << endl;
			return 0;
		}
		polygon shape2 = inputPolygon(b);
		cout << (shape1 != shape2 ? "not " : "") << "equal" << endl;
	} catch (const char* e) {
		cout << e << endl;
	}
	return 0;
}

/*
========== Sample Run - start ==========

=========== Sample Run - end ===========
----------------------------------------
*/