/*
 * File Name:				3.noDuplicates.cpp
 * Program Description:		Reads in values until a 0 is read in, then removes all duplicate entries
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		6
 * Question Number:			3
 * Author:					Abraham Murciano
 *
 * Created on:				Sun Nov 11 2018
 * Last Modified on:		Sun Nov 11 2018
 */

#include <iostream>
using namespace std;

// Function that deletes duplicate values of array of length n, and adjusts n to new size
void delDup(int array[], int& n) {

	// Loop through every value of array starting from the 2nd one
	for (int i = 1; i < n; i++) {

		// Loop through every value of array up to the ith one
		for (int j = 0; j < i; j++) {

			// Check if the ith one is a repetition of a previous one. If so, delete it
			if (array[i] == array[j]) {
				n--;  // Decrement n because one element is being deleted

				// Shift all values after the ith one, 1 position to the left
				for (int k = i; k < n; k++) {
					array[k] = array[k + 1];
				}

				i--;	// Decrement i so the new value that was put into position i isn't skipped
				break;  // No more values need to be checked against the deleted element
			}
		}
	}
}

// Function that prints the values of a 1D array of integers separated by a space
void printArray(int array[], int n) {
	if (n < 1) {
		return;
	}
	cout << array[0];
	for (int i = 1; i < n; i++) {
		cout << " " << array[i];
	}
}

int main() {

	int vect[100];   // Declare an array of size 100
	int length = 0;  // Initialise length to 0

	cout << "enter up to 100  values, to stop enter 0:" << endl;  // Prompt for input

	// Read in up to 100 values
	for (int n = 1; length < 100; length++) {
		cin >> n;  // Read a value into n
		if (n == 0) {
			break;  // If user input 0, stop reading in values
		}
		vect[length] = n;  // Assign the input to the next position of vect
	}

	delDup(vect, length);  // Delete duplicates of vect, and update length to new size

	// Output the new vector and its size
	cout << "the new vector is:" << endl;
	printArray(vect, length);  // Print the new values of vect
	cout << endl;
	cout << "number of elements: " << length << endl;

	return 0;
}

/*
enter up to 100  values, to stop enter 0:
1 5 8 9 5 4 1 2 3 5 1 4 8 9 6 5 0
the new vector is:
1 5 8 9 4 2 3 6
number of elements: 8
*/