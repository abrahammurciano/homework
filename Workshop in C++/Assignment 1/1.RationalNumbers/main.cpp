/*
 * File Name:				main.cpp
 * Program Description:		Compares two rational numbers
 * Course Name:				Workshop in C++
 * Assignment Number:		1
 * Question Number:			1
 * Author:					Abraham Murciano
 */

#include "Rational.h"
#include <iostream>
using namespace std;

int main() {

	cout << "enter two rational numbers" << endl;  // Prompt for input
	int n1, d1, n2, d2;							   // Declare variables to store input
	char c;									// Character to ignore the '/' in the input stream
	cin >> n1 >> c >> d1 >> n2 >> c >> d2;  // Read in input

	// Declare 2 rational numbers with the user's inputs
	Rational num1(n1, d1);
	Rational num2(n2, d2);

	if (num1.equal(num2)) {
		cout << "equal" << endl;
	} else {
		cout << "different ";
		num1.print();
		cout << ' ';
		num2.print();
		cout << endl;
	}

	return 0;
}

/*
========== Sample Run - start ==========
enter two rational numbers
5/2 1025/410
equal
=========== Sample Run - end ===========
----------------------------------------
========== Sample Run - start ==========
enter two rational numbers
5/0 5/1
equal
=========== Sample Run - end ===========
----------------------------------------
========== Sample Run - start ==========
enter two rational numbers
2/0 3/0
different 2/1 3/1
=========== Sample Run - end ===========
----------------------------------------
*/