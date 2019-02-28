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

	cout << "enter two rational numbers" << endl;
	int n1, d1, n2, d2;
	char c;  // Character to ignore the '/' in the input stream
	cin >> n1 >> c >> d1 >> n2 >> c >> d2;

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

=========== Sample Run - end ===========
----------------------------------------
*/