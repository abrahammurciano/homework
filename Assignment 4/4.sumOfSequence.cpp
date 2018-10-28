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
 * Last Modified on:		Sun Oct 28 2018
 */

#include <iostream>
using namespace std;

int main() {

	// Ask user for 2 numbers to be stiored in x and n
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

	float sum = 0;
	int temp = 0;
	for (int i = 1; i <= n; i++) {
		// Work out (-1)^(n-1)
		int coefficientNumerator = -1;
		temp = coefficientNumerator;
		for (int j = 0; j <= i - 1; j++) {
			temp *= coefficientNumerator;
		}
		coefficientNumerator = temp;

		// Work out 2n-1
		int twoNMiusOne = 2 * i - 1;

		// Work out coefficient: (-1)^(n-1)/(2n-1)
		float coefficient = (float)coefficientNumerator / twoNMiusOne;

		// Work out x^(2n-1)
		int xPow2NMinus1 = x;
		temp = xPow2NMinus1;
		for (int j = 2; j <= twoNMiusOne; j++) {
			temp *= xPow2NMinus1;
		}
		xPow2NMinus1 = temp;

		// Work out expression: (-1)^(n-1)/(2n-1)x^(2n-1)
		float expression = coefficient * xPow2NMinus1;
		sum += expression;
	}
	cout << sum << endl;

	return 0;
}

/*
enter 2 numbers:
3 2
-6
*/