/*
 * File Name:				2.twoPositiveNumbers.cpp
 * Program Description:		Takes 2 positive numbers and then a list of numbers until the sum of the
 * list is > the first number or the number of numbers in the list is > the second number
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		4
 * Question Number:			2
 * Author:					Abraham Murciano
 *
 * Created on:				Sun Oct 28 2018
 * Last Modified on:		Sun Nov 04 2018
 */

#include <iostream>
using namespace std;

int main() {

	int sum = 0, count = 0;		   // Variables that keep track of the nubmer & sum of inputs
	int maxSum = 0, maxCount = 0;  // 2 positive integers the user will input

	cout << "enter 2 positive numbers:" << endl;  // Prompt the user for inputs
	// Go through this for loop twice, once for each of the inputs
	for (int i = 0; i < 2; i++) {
		// Go through this while loop forever until the user inputs a valid number
		while (true) {
			int input;
			cin >> input;
			if (input > 0) {
				// After input is valid, store input into correct variable, then exit loop
				if (i == 0) {
					maxSum = input;  // If it's the first input
				} else {
					maxCount = input;  // If it's the second input
				}
				break;
			}
			cout << "ERROR" << endl;
		}
	}

	// Start capturing list input
	cout << "enter a list of numbers:" << endl;  // Prompt the user for a list
	while (sum <= maxSum && count < maxCount) {
		// Do this until the max sum or count have been reached
		int n;
		cin >> n;  // Input the next number of the list
		sum += n;  // Add it to sum
		count++;   // Increment the list counter
	}

	// Output the sum
	cout << sum << endl;

	return 0;
}

/*
enter 2 positive numbers:
25
12
enter a list of numbers:
9
8
7
6
30
*/