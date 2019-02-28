/*
 * File Name:				main.cpp
 * Program Description:		Calculates area and circumference of 3 circles and calculates if any
 * point is inside the circles
 * Course Name:				Workshop in C++
 * Assignment Number:		1
 * Question Number:			3
 * Author:					Abraham Murciano
 */

#include "Circle.h"
#include <iostream>
using namespace std;

int main() {
	int const N = 3;  // Number of circles to input (program works for any N)

	cout << "enter the center point and radius of " << N << " circles" << endl;

	Circle circles[N];			   // Make an array of N circles
	for (int i = 0; i < N; i++) {  // Input the details of each circle
		float r;				   // Variables to store user input
		Point p;
		cin >> p.x >> p.y >> r;		// Read in user input
		circles[i] = Circle(p, r);  // Construct a circle and put it into array
	}

	// Print area of each circle
	cout << "area\t";
	for (int i = 0; i < N; i++) {
		cout << (char)('A' + i) << ": " << circles[i].area() << '\t';
	}
	cout << endl;

	// Print circumference of each circle
	cout << "hekef\t";
	for (int i = 0; i < N; i++) {
		cout << (char)('A' + i) << ": " << circles[i].circumference() << '\t';
	}
	cout << endl;

	int count[N] = {0};  // Declare array of counters to count the number of points in each circle
	while (true) {		 // Input points
		Point p;
		cin >> p.x >> p.y;
		if (!p.x && !p.y) {  // If input is (0,0) stop reading in points
			break;
		}
		for (int i = 0; i < N; i++) {		  // For each point, go through all N circles
			if (circles[i].outside(p) < 1) {  // Check if point is inside circle
				count[i]++;					  // Increment count
			}
		}
	}

	// Print number of points in all N circles
	cout << "num of points in circle\t";
	for (int i = 0; i < N; i++) {
		cout << (char)('A' + i) << ':' << count[i] << '\t';
	}
	cout << endl;

	return 0;
}

/*
========== Sample Run - start ==========
enter the center point and radius of 3 circles
0 0 3
1 1 2
5 5 2
area    A: 28.26        B: 12.56        C: 12.56
hekef   A: 18.84        B: 12.56        C: 12.56
0 1
1 0
0 4
0 0
num of points in circle A:2     B:2     C:0
=========== Sample Run - end ===========
----------------------------------------
*/