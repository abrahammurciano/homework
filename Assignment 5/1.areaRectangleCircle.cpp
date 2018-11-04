/*
 * File Name:				1.areaRectangleCircle.cpp
 * Program Description:		Calculates the area of a rectangle, then of a circle
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		5
 * Question Number:			1
 * Author:					Abraham Murciano
 *
 * Created on:				Sun Nov 04 2018
 * Last Modified on:		Sun Nov 04 2018
 */

#include <iostream>
using namespace std;

// Declare constant Pi
const float PI = 3.14159;

// Function that calculates the area of a rectangle given its dimensions
int area(int width, int height) {

	// Check if either width or height are negative
	if (width < 0 || height < 0) {
		return -1;
	}

	// Return area of rectangle
	return width * height;
}

// Function that calculates the area of a circle given its dimensions
float area(float radius) {

	// Check if radius is negative
	if (radius < 0) {
		return -1;
	}

	// Return area of circle
	return PI * radius * radius;
}

int main() {

	// Prompt user for input
	cout << "enter length and width of the rectangle:" << endl;
	int w, h;			// Stores user input for width and height
	int areaRectangle;  // Stores computed area of rectangle
	while (true) {
		cin >> w >> h;

		// Call area function for rectangle
		areaRectangle = area(w, h);

		// If area returned a non-negative value, stop asking for input
		if (areaRectangle >= 0) {
			break;
		}

		cout << "ERROR" << endl;
	}

	// Output the area of the rectangle
	cout << areaRectangle << endl;

	// Prompt user for input
	cout << "enter radius of the circle:" << endl;
	int r;			   // Stores user input for radius
	float areaCircle;  // Stores computed area of circle
	while (true) {
		cin >> r;

		// Call area function for rectangle
		areaCircle = area(r);

		// If area returned a non-negative value, stop asking for input
		if (areaCircle >= 0) {
			break;
		}

		cout << "ERROR" << endl;
	}

	// Output the area of the circle
	cout << areaCircle << endl;

	return 0;
}

/*
enter length and width of the rectangle:
8
4
32
enter radius of the circle:
8
201.062
*/