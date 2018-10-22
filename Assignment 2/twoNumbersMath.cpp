
/*
 * File Name:				twoNumbersMath.cpp
 * Program Description:		Gets 2 numbers and prints their sum, difference, product and division.
 * Course Name:				Introduction to Computer Science
 * Exercise Number:			2
 * Question Number:			6
 * Author:					Abraham Murciano
 * 
 * Created on:				Oct 14, 2018, 9:49:31 PM
 * Last Modified on:			Oct 14, 2018, 10:03:03 PM
 */

//#include <cstdlib>
//#include <cstring>
#include <iostream>
//#include <math.h>
using namespace std;

int main () {

	int a, b; //Two variables to store the user input
	cout << "enter two numbers:" << endl;
	cin >> a >> b;
	cout << a << "+" << b << "=" << a + b << endl;
	cout << a << "-" << b << "=" << a - b << endl;
	cout << a << "*" << b << "=" << a * b << endl;
	cout << a << "/" << b << "=" << (float)a / (float)b << endl;
	
	return 0;
}

/*
enter two numbers:
7
3
7+3=10
7-3=4
7*3=21
7/3=2.33333
 */