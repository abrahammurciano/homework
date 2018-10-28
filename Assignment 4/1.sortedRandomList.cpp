/*
 * File Name:				4.sortedRandomList.cpp
 * Program Description:		Chooses 10 integers between 1 and 1000 and prints
 * them. Then tells you if teh numbers are in order
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		4
 * Question Number:			1
 * Author:					Abraham Murciano
 *
 * Created on:				Sun Oct 28 2018
 * Last Modified on:		Sun Oct 28 2018
 */

#include <ctime>
#include <iostream>
using namespace std;

int main() {

	srand(time(0));
	bool sorted = true;
	int n = 0, nPrevious = 0;

	for (int i = 0; i < 10; i++) {
		nPrevious = n;
		n = rand() % 1000 + 1;
		cout << n << ((i + 1 < 10) ? ' ' : '\n');
		if (n < nPrevious) {
			sorted = false;
		}
	}

	if (sorted) {
		cout << "sorted list" << endl;
	} else {
		cout << "not sorted list" << endl;
	}

	return 0;
}

/*
757 610 130 328 382 919 918 28 726 272
not sorted list
*/