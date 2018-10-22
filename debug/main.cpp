/*
 * File Name:				4.triangles.cpp
 * Program Description:		Says if given triangle is equilateral, isosceles or scalene.
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		3
 * Question Number:			4
 * Author:					Abraham Murciano
 * 
 * Created on:				Mon Oct 22 2018
 * Last Modified on:		Mon Oct 22 2018
 */

#include <iostream>
using namespace std;

int main() {
	
	cout << "enter 3 numbers:" << endl;
	int a, b, c;
	cin >> a >> b >> c;
	
	if (a + b < c || a + c < b || b + c < a) {
		cout << "cannot form a triangle" << endl;
	} else if (a == b && b == c) {
		cout << "equilateral triangle" << endl;
	} else if (a == b || b == c || a == c) {
		cout << "isosceles triangle" << endl;
	} else {
		cout << "scalene triangle" << endl;
	}

	return 0;
}

/*
enter 3 numbers:
7 5 3
scalene triangle
*/
