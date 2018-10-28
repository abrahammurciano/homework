/*
 * File Name:				6.descendingDigits.cpp
 * Program Description:		Takes a positive integer, and tells you if the
 * digits are in descending order
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		4
 * Question Number:			6
 * Author:					Abraham Murciano
 *
 * Created on:				Sun Oct 28 2018
 * Last Modified on:		Sun Oct 28 2018
 */

#include <cmath>
#include <iostream>
using namespace std;

int main() {

	cout << "enter a number:" << endl;
	int n;
	while (true) {
		cin >> n;
		if (n > 0) {
			break;
		}
		cout << "ERROR" << endl;
	}

	int digit = 0;
	int digitLeft = n % 10;  // Set digitLeft to the right-most digit
	bool descending = true;  // Set descending flag to true
	int nCopy = n;			 // Copy of n for manipulating
	int position = 0;
	// while nCopy can be divided into 10 (i.e. has more than 1 digit)
	while (nCopy /= 10) {
		digit = digitLeft;
		position++;
		digitLeft = (n % (int)pow(10, position + 1)) / pow(10, position);
		if (digit >= digitLeft) {
			descending = false;
			break;
		}
	}

	cout << (descending ? "YES" : "NO") << endl;

	return 0;
}

/*
enter a number:
4321
YES
*/