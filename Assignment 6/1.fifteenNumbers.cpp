/*
 * File Name:				1.fifteenNumbers.cpp
 * Program Description:		Reads in 15 whole numbers and outputs wheather or not the list contains
 * all the numbers between 1 and 15
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		6
 * Question Number:			1
 * Author:					Abraham Murciano
 *
 * Created on:				Sun Nov 11 2018
 * Last Modified on:		Sun Nov 11 2018
 */

#include <iostream>
using namespace std;

int main() {

	// Declare the length of the array & the minimum and maximum values that are "GOOD"
	int const length = 15, min = 1, max = 15;
	int list[length];  // Declare array of length 'length'

	cout << "enter 15 numbers:" << endl;  // Prompt for input

	// Loop to input 15 numbers and check if they're within the 'good' range
	for (int i = 0; i < length; i++) {
		cin >> list[i];  // Read a number into the ith position
	}

	// Variable to store whether or not list contains all numbers from 1 to 15
	bool containsAllNums = true;

	// Go through all the numbers between min and max to see if they're all contained in list
	for (int i = min; i <= max; i++) {
		bool found = false;  // Assume the number is not in list until it's found

		// Iterate through list checking if i is in list
		for (int j = 0; j < length; j++) {
			if (list[j] == i) {
				found = true;
				break;
			}
		}

		// If any number was not found, then the list doesn't contain all values
		if (!found) {
			containsAllNums = false;
			break;
		}
	}

	// Output wheather or not all the numbers are in list
	cout << (containsAllNums ? "" : "NOT ") << "GOOD" << endl;

	return 0;
}

/*
enter 15 numbers:
15 8 9 16 1 3 4 2 10 14 6 5 13 12 11
NOT GOOD
*/