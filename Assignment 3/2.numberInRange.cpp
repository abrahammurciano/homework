/*
 * File Name:				2.numberInRange.cpp
 * Program Description:		checks if a given number falls within a specified range
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		3
 * Question Number:			3
 * Author:					Abraham Murciano
 * 
 * Created on:				Mon Oct 22 2018
 * Last Modified on:		Mon Oct 22 2018
 */

#include <iostream>
using namespace std;

int main() {
	
	cout << "enter 3 numbers:" << endl;
	int first, last, number;
	cin >> first >> last >> number;
	
	if (first <= number && number <= last) {
		cout << "between" << endl;
	} else if (number < first) {
		cout << "smaller" << endl;
	} else if (number > last) {
		cout << "bigger" << endl;
	}
	

	return 0;
}

/*
enter 3 numbers:
3 7 5
between
*/