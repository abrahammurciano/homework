/*
 * File Name:				4.sumOfSequence.cpp
 * Program Description:		Computes the sum of the first n elements of the
 * series given in the question
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		4
 * Question Number:			4
 * Author:					Abraham Murciano
 *
 * Created on:				Sun Oct 28 2018
 * Last Modified on:		Sun Nov 04 2018
 */

#include <iostream>
using namespace std;

int main() {

	// Ask user for 2 numbers to be stored in x and n
	int x = 0, n = 0;
	cout << "enter 2 numbers:" << endl;
	cin >> x;
	while (true) {
		cin >> n;
		if (n > 0) {
			break;
		}
		cout << "ERROR" << endl;
	}

	// Set values for each sub-expression of n when n=0 (before the first term)
	int coefficientNumerator = -1;		// This part of the sequence: (-1)^(n-1)
	int twoNMinusOne = -1;				// This part of the sequence: 2n-1
	float xPow2NMinus1 = 1 / (float)x;	// This part of the sequence: x^(2n-1)

	float sum = 0;	// Stores the value of the whole sequence as each iteration is added

	for (int i = 0; i < n; i++) {
		// Work out the next (-1)^(n-1)
		coefficientNumerator *= -1;

		// Work out the next 2n-1
		twoNMinusOne += 2;

		// Work out coefficient: (-1)^(n-1)/(2n-1)
		float coefficient = (float)coefficientNumerator / twoNMinusOne;

		// Work out x^(2n-1)
		xPow2NMinus1 *= x * x;

		// Work out expression: (-1)^(n-1)/(2n-1)x^(2n-1) and add it to sum
		sum += coefficient * xPow2NMinus1;
	}

	// Output the value of the sum of the sequence
	cout << sum << endl;

	return 0;
}

/*
enter 2 numbers:
3 2
-6

enter 2 numbers:
5 4
-10572.4
*/