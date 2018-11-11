/*
 * File Name:				1.fifteenNumbers.cpp
 * Program Description:		Reads in 15 whole numbers and outputs wheather or not the list contains
 * only numbers between 1 and 15
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

	int const length = 15, min = 1, max = 15;
	int list[length];
	bool inRange = true;

	cout << "enter 15 numbers:" << endl;

	for (int i = 0; i < length; i++) {
		cin >> list[i];
		if (list[i] < min || list[i] > max) {
			inRange = false;
		}
	}

	cout << (inRange ? "" : "NOT ") << "GOOD" << endl;

	return 0;
}

/*
enter 15 numbers:
15 8 9 16 1 3 4 2 10 14 6 5 13 12 11
NOT GOOD
*/