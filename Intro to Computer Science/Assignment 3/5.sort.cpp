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

	int num1, num2, num3, smallest, middle, biggest, temp;
	cout << "enter 3 numbers: " << endl;
	cin >> num1 >> num2 >> num3;

	biggest = num1;
	middle = num2;
	smallest = num3;
	if (smallest > middle) {
		// Swap smallest and middle
		temp = middle;
		middle = smallest;
		smallest = temp;
	}
	if (middle > biggest) {
		// Swap biggest and middle
		temp = middle;
		middle = biggest;
		biggest = temp;
	}
	if (smallest > middle) {
		// Swap smallest and middle
		temp = middle;
		middle = smallest;
		smallest = temp;
	}

	cout << smallest << " " << middle << " " << biggest << endl;

	return 0;
}

/*
enter 3 numbers:
9 6 1
1 6 9
*/