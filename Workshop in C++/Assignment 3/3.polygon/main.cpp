/*
 * File Name:				main.cpp
 * Program Description:		An implementation of a polygon class
 * Course Name:				Workshop in C++
 * Assignment Number:		3
 * Question Number:			3
 * Author:					Abraham Murciano
 */

#include "point.h"
#include "polygon.h"
#include <iostream>
using namespace std;

int main() {

	polygon poly;  // Declare polygon
	int N;		   // Declare number of vertices
	cin >> N;	  // Read in number of vertices

	// Check that number of vertices is greater than 0
	if (N <= 0) {
		cout << "ERROR" << endl;
		return 0;
	}

	// Read in vertices, one at a time
	for (int i = 0; i < N; i++) {
		float x, y;			  // Declare variables for x and y coordinates of vertex
		cin >> x >> y;		  // Read in x and y coordinates of vertex
		poly << point(x, y);  // Create a point with x and y, then append it to polygon
	}

	cout << (int)poly.perimeter() << endl;  // Print perimeter

	return 0;
}

/*
========== Sample Run - start ==========
3 10 10 10 14 13 10
12
=========== Sample Run - end ===========
----------------------------------------
========== Sample Run - start ==========
0 3 5 2 5 3 1
ERROR
=========== Sample Run - end ===========
----------------------------------------
========== Sample Run - start ==========
10 4.3 6.3 4.9 1.4 5.5 2.3 9.5 7.4 6.0 4.1 8.6 4.9 7.6 3.7 0.3 -3 9.4 -7.5 0 4.1
61
=========== Sample Run - end ===========
----------------------------------------
*/