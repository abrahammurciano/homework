/*
 * File Name:				3.fibonacci.cpp
 * Program Description:		Print fibonacci sequence up to a given number
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		4
 * Question Number:			3
 * Author:					Abraham Murciano
 *
 * Created on:				Sun Oct 28 2018
 * Last Modified on:		Sun Oct 28 2018
 */

#include <iostream>
using namespace std;

int main() {

	// Ask user for a non-negative integer
	int n = 0, fibN = 0, fibNMinus1 = 0, fibNMinus2 = 0;
	cout << "enter a number:" << endl;
	while (true) {
		cin >> n;
		if (n >= 0) {
			break;
		}
		cout << "ERROR" << endl;
	}

	for (int i = 0; i < n + 1; i++) {
		fibNMinus2 = fibNMinus1;
		fibNMinus1 = fibN;
		fibN = fibNMinus1 + fibNMinus2 + (i == 1 ? 1 : 0);
		cout << fibN << (i < n ? ' ' : '\n');
	}

	return 0;
}

/*
enter a number:
9
0 1 1 2 3 5 8 13 21 34
*/