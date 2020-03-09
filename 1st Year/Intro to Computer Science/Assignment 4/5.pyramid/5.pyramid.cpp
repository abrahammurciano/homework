/*
 * File Name:				5.pyramid.cpp
 * Program Description:		Prints all integers from given number to 1 in decending order (works for
 * any number of digits)
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		4
 * Question Number:			5
 * Author:					Abraham Murciano
 *
 * Created on:				Sun Oct 28 2018
 * Last Modified on:		Sun Nov 04 2018
 */

#include <iostream>
using namespace std;

int main() {

	// Input a number
	cout << "enter a one digit number:" << endl;  // Prompt user for a number
	int n = 0;
	while (true) {
		cin >> n;
		if (n > 0) {
			break;
		}
		cout << "ERROR" << endl;
	}

	int numOfSpaces = 0;  // Variable to store the number of spaces to print before each line

	// Loop to print out each line (we need n lines)
	// Counter counts down because each line starts from a lower number
	for (int i = n; i > 0; i--) {

		// Print the necessary spaces to right-align the numbers
		// Dont print any spaces for the first line
		if (i != n) {
			numOfSpaces += 2;  // Add 2 spaces to account for the ", "

			// Now add the number of digits to numOfSpaces
			int numOfDigits = 1;  // Start with 1 digit
			int prevNum = i + 1;  // Store previous number to number of digits

			// Increment numOfDigits as many times as prevNum can be / by 10 without becoming 0
			while (prevNum /= 10) {
				numOfDigits++;
			}

			// Output the necessary number of spaces
			numOfSpaces += numOfDigits;
			for (int i = 0; i < numOfSpaces; i++) {
				cout << ' ';
			}
		}

		// Output the row of numbers
		cout << i;  // Output the first number

		// Start at the second highest number, then go downwards
		for (int j = i - 1; j > 0; j--) {
			cout << ", " << j;
		}
		cout << endl;
	}

	return 0;
}

/*
enter a one digit number:
4
4, 3, 2, 1
   3, 2, 1
	  2, 1
		 1
*/