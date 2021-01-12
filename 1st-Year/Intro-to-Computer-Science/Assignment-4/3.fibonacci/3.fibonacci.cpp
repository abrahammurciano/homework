/*
 * File Name:				3.fibonacci.cpp
 * Program Description:		Print fibonacci sequence up to a given number
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		4
 * Question Number:			3
 * Author:					Abraham Murciano
 *
 * Created on:				Sun Oct 28 2018
 * Last Modified on:		Sun Nov 04 2018
 */

#include <iostream>
using namespace std;

int main() {

	int n = 0;			// User input
	int fibN = 0;		// Each value of the sequence
	int fibNMinus1 = 1; // Previous value of sequence
	int fibNMinus2 = 0; // 2nd previous value

	// Ask user for a non-negative integer
	cout << "enter a number:" << endl;
	while (true) {
		cin >> n;
		// Test if not negative
		if (n >= 0) {
			break;
		}
		cout << "ERROR" << endl;
	}

	// Print the first 2 values (unless n is 0, then stop after the 1st one)
	cout << (n == 0 ? "0" : "0 1");

	// Calculate each value of sequence until (n+1)th value
	// Start at the 3rd value
	for (int i = 2; i <= n; i++) {
		fibN = fibNMinus1 + fibNMinus2; // Calculate the new value
		cout << ' ' << fibN;			// Output new value

		fibNMinus2 = fibNMinus1; // Update 2nd previous value
		fibNMinus1 = fibN;		 // Update previous value
	}

	cout << endl;

	return 0;
}

/*
enter a number:
9
0 1 1 2 3 5 8 13 21 34
*/