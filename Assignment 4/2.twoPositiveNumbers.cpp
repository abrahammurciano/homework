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
 * Last Modified on:		Sun Oct 28 2018
 */

#include <iostream>
using namespace std;

int main() {

	// These are the 2 positive integers that we will ask the user to input
	int sum = 0, maxSum = 0, count = 0, maxCount = 0;

	cout << "enter 2 positive numbers:" << endl;
	// Go through this for loop twice, once for each of the inputs
	for (int i = 0; i < 2; i++) {
		// Go through this while loop forever until the user inputs a valid
		// number
		while (true) {
			int input;
			cin >> input;
			if (input > 0) {
				// After input is valid, store the input into the correct
				// variable, then exit the loop
				if (i == 0) {
					maxSum = input;
				} else {
					maxCount = input;
				}
				break;
			}
			cout << "ERROR" << endl;
		}
	}

	// Start capturing list input
	cout << "enter a list of numbers:" << endl;
	while (sum <= maxSum && count < maxCount) {
		int n;
		cin >> n;
		sum += n;
		count++;
	}
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