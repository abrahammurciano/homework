/*
 * File Name:				main.cpp
 * Program Description:		An implementation of a class for rational numbers with operators
 * Course Name:				Workshop in C++
 * Assignment Number:		2
 * Question Number:			1
 * Author:					Abraham Murciano
 */

#include "Rnl.h"
#include <iostream>
using namespace std;

int main() {
	int n, d;
	cout << "Enter two rational numbers" << endl;
	cout << boolalpha;

	cout << "a: ";
	cin >> n;
	cin.ignore(1, '/');
	cin >> d;
	if (d == 0) {
		cout << "ERROR" << endl;
	}

	Rnl a(n, d);

	cout << "b: ";
	cin >> n;
	cin.ignore(1, '/');
	cin >> d;
	if (d == 0) {
		cout << "ERROR" << endl;
	}

	Rnl b(n, d);

	cout << "b-a: ";
	(b - a).print();
	cout << endl;

	cout << "a!=b: ";
	cout << (bool)(a != b) << endl;

	cout << "a<b: ";
	cout << (a < b) << endl;

	cout << "a>b: ";
	cout << (a > b) << endl;

	cout << "a>=b: ";
	cout << (a >= b) << endl;

	cout << "a++: ";
	(a++).print();
	cout << endl;

	cout << "--a: ";
	(--a).print();
	cout << endl;

	cout << "a--: ";
	(a--).print();
	cout << endl;

	b = a;

	cout << "b-a: ";
	(b - a).print();
	cout << endl;

	cout << "b/a: ";
	(b / a).print();
	cout << endl;

	cout << "a!=b: ";
	cout << (a != b) << endl;

	cout << "a<b: ";
	cout << (a < b) << endl;

	cout << "a>=b: ";
	cout << (a >= b) << endl;

	return 0;
}

/*
========== Sample Run - start ==========
Enter two rational numbers
a: 2/3
b: 3/4
b-a: 1/12
a!=b: true
a<b: true
a>b: false
a>=b: false
a++: 2/3
--a: 2/3
a--: 2/3
b-a: 0
b/a: 1
a!=b: false
a<b: false
a>=b: true
=========== Sample Run - end ===========
----------------------------------------
*/