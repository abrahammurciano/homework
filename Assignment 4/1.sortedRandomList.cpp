/*
 * File Name:				4.sortedRandomList.cpp
 * Program Description:		Chooses 10 integers between 1 and 1000 and prints
 * them. Then tells you if the numbers are in order
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		4
 * Question Number:			1
 * Author:					Abraham Murciano
 *
 * Created on:				Sun Oct 28 2018
 * Last Modified on:		Sun Nov 04 2018
 */

#include <ctime>
#include <iostream>
using namespace std;

int main() {

	// Set a seed for random number generation
	srand(time(0));

	// Declare variables
	bool sorted = true;		   // Flag to keep track of wheather or not the numbers are sorted
	int n = 0, nPrevious = 0;  // Variables to store the current and previous random numbers

	// Loop to generate 10 random numbers
	for (int i = 0; i < 10; i++) {
		nPrevious = n;							   // Update the previous number
		n = rand() % 1000 + 1;					   // Generate a new random number (1 to 1000)
		cout << n << ((i + 1 < 10) ? ' ' : '\n');  // Output the new number

		// Check if the new number is still in order
		if (n < nPrevious) {
			sorted = false;
		}
	}

	// Output wheather or not it's sorted
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