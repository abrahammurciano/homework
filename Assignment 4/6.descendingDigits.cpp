/*
 * File Name:				6.descendingDigits.cpp
 * Program Description:		Takes a positive integer, and tells you if the digits are in descending
 * order
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		4
 * Question Number:			6
 * Author:					Abraham Murciano
 *
 * Created on:				Sun Oct 28 2018
 * Last Modified on:		Sun Nov 04 2018
 */

#include <cmath>
#include <iostream>
using namespace std;

int main() {

	// Receive input from user
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

	// According to the exact phrasing of the question, it is implied that if the user inputs a one
	// digit number, the program should really output "NO".
	// The question states "if each digit is one smaller than the previous digit on its
	// left", only then I should print "YES".
	// However, if there is only one digit, it is NOT smaller that "the previous digit on its left"
	// since there is no such digit.
	// Therefore I included this if statement:
	//
	// if (n < 10) {
	//     descending = false;
	// }
	//
	// However, moodle expected "YES" with one digit numbers as well.
	// Just wanted to point that out...

	// Repeat loop while n can be divided by 10 without becoming 0
	while (n /= 10) {		 // The last digit is removed from n
		digit = digitLeft;   // Get the next left value for digit
		digitLeft = n % 10;  // Get the next left digit for digitLeft

		// Check if the current digit is greater than or equal to the on eto its left
		if (digit >= digitLeft) {
			descending = false;  // Set descending to false
			break;  // Once we know it's not in descending order, we needn't check the other digits
		}
	}

	// Output wheather or not the digits are in descending order
	cout << (descending ? "YES" : "NO") << endl;

	return 0;
}

/*
enter a number:
4321
YES
*/