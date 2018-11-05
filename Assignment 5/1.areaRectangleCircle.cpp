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

#include <climits>  // Necessary to use the maximum and minimum integer values
#include <iostream>
using namespace std;

int area(int, int);
float area(float);
float getArea(int);

int main() {

	cout << "enter length and width of the rectangle:" << endl;  // Prompt user
	int rect = getArea(2);  // Call getArea to ask for 2 inputs. It will then call area
	cout << rect << endl;

	cout << "enter radius of the circle:" << endl;  // Prompt user
	float circle = getArea(1);  // Call getArea to ask for 1 input. It will then call area
	cout << circle << endl;

	return 0;
}

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

	// Check if radius is negative or 0
	if (radius <= 0) {
		return -1;
	}

	// Declare constant Pi
	const float PI = 3.14159;

	// Return area of circle
	return PI * radius * radius;
}

// Function that reads in 1 or 2 values until valid values are inputted
// Then it calls 'area' with the necessary number of arguments and returns the area of the shape
float getArea(int numInputs = 1) {
	float areaShape = 0;		 // Will store the area of the shape
	int input1 = 0, input2 = 0;  // Will store user inputs

	// Loop to keep asking for input until valid value(s) are given
	while (true) {
		if (numInputs == 1) {  // If only one input is required, the shape is a circle
			cin >> input1;
			// If area didn't return an error code (eg -1), break
			if ((areaShape = area(input1)) >= 0) {
				break;
			}
		} else if (numInputs == 2) {  // If only one input is required, the shape is a circle
			cin >> input1 >> input2;
			// If area didn't return an error code, break
			if ((areaShape = area(input1, input2)) >= 0) {
				break;
			}
		}

		cout << "ERROR" << endl;
	}

	return areaShape;
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