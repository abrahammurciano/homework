/*
 * File Name:				4.sortIndices.cpp
 * Program Description:		Given a list, will calculate the sorted indices
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		6
 * Question Number:			4
 * Author:					Abraham Murciano
 *
 * Created on:				Mon Nov 12 2018
 * Last Modified on:		Mon Nov 12 2018
 */

#include <cfloat>
#include <iostream>
using namespace std;

// Function that swaps two variables
void mySwap(int& x, int& y) {
	int t = x;
	x = y;
	y = t;
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

	int const N = 6;   // Length of arrays
	float numbers[N];  // Store all the inputs
	int indices[N];	// Store all the indices in order

	// Set indices to increasing values from 0 to N-1 {1, 2, ... N-2, N-1}
	for (int i = 0; i < N; i++) {
		indices[i] = i;
	}

	cout << "enter  6 numbers between 0 and 1:" << endl;  // Prompt for inputs

	// Repeat until all numbers are in range
	while (true) {
		bool inRange = true;		   // Store whether or not all numbers are in range
		for (int i = 0; i < N; i++) {  // Input N values
			cin >> numbers[i];		   // Read a value into the ith number
			if (numbers[i] <= 0 || numbers[i] >= 1) {
				inRange = false;  // If the newly input number is out of range, remember that
			}
		}
		if (inRange) {
			break;  // If no numbers were illegal, don't repeat
		}
		cout << "ERROR" << endl;
	}

	// Go through numbers in the order of indices (not in the order 0, 1, 2...)
	for (int i = 0; i < N; i++) {
		// For every nubmer, go through all the numbers after itself
		for (int j = i; j < N; j++) {
			// Check if any number after itself is smaller than itself
			if (numbers[indices[j]] < numbers[indices[i]]) {
				mySwap(indices[j], indices[i]);  // Swap the indices pointing to those numbers
			}
		}
	}

	cout << "sorted indices:" << endl;
	printArray(indices, N);
	cout << endl;

	return 0;
}

/*
Sample run:
enter  6 numbers between 0 and 1:
0.6 0.5 0.4 0.3 0.2 0.1
sorted indices:
5 4 3 2 1 0

Sample run:
enter  6 numbers between 0 and 1:
0.1 0.2 0.3 0.4 0.5 1.6
ERROR
0.3 0.2  0.4 0.1 0.05 0.9
sorted indices:
4 3 1 0 2 5
*/