/*
 * File Name:				5.pyramid.cpp
 * Program Description:		Prints all integers from given number to 1 in decending order
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		#
 * Question Number:			#
 * Author:					Abraham Murciano
 *
 * Created on:				Sun Oct 28 2018
 * Last Modified on:		Sun Oct 28 2018
 */

#include <iostream>
using namespace std;

int main() {

	cout << "enter a one digit number:" << endl;
	int n;
	while (true) {
		cin >> n;
		if (n > 0) {
			break;
		}
		cout << "ERROR" << endl;
	}

	int numOfSpaces = 0;

	// Loop to print out each line
	for (int i = n; i > 0; i--) {
		// Print the necessary spaces to right-align the numbers
		if (i != n) {
			// Add 2 spaces to sub for the ", "
			numOfSpaces += 2;
			// Now add the number of digits to numOfSpaces
			int numOfDigits = 1;
			int iCopy = i + 1;
			while (iCopy /= 10) {
				numOfDigits++;
			}
			numOfSpaces += numOfDigits;
			cout << string(numOfSpaces, ' ');
		}

		// Loop to print out each number
		cout << i;
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