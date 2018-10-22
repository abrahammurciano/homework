/*
 * File Name:				5.sort.cpp
 * Program Description:		Sorts 3 numbers
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		3
 * Question Number:			5
 * Author:					Abraham Murciano
 * 
 * Created on:				Mon Oct 22 2018
 * Last Modified on:		Mon Oct 22 2018
 */

#include <iostream>
using namespace std;

int main() {
	
	int num1, num2, num3, smallest, middle, biggest;
	cout << "enter 3 numbers: " << endl;
	cin >> num1 >> num2 >> num3;

	// Assume num1 is biggest. work out middle and smallest
	biggest = num1;
	middle = (num2 > num3)? num2 : num3;
	smallest = (num2 <= num3)? num2 : num3;
	if (num2 > biggest) {
		// Assume num2 is biggest. work out middle and smallest
		biggest = num2;
		middle = (num1 > num3)? num1 : num3;
		smallest = (num1 <= num3)? num1 : num3;
	}
	if (num3 > biggest) {
		// Assume num3 is biggest. work out middle and smallest
		biggest = num3;
		middle = (num2 > num1)? num2 : num1;
		smallest = (num2 <= num1)? num2 : num1;
	}

	cout << smallest << " " << middle << " " << biggest << endl;

	return 0;
}

/*
enter 3 numbers:
9 6 1
1 6 9
*/