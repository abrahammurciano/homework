/*
 * File Name:				3.sortPyramids.cpp
 * Program Description:		Takes input of 10 by 10 matrix, then sorts the bottom left triangle and
 * the top right triangle
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		7
 * Question Number:			3
 * Author:					Abraham Murciano
 *
 * Created on:				Wed Nov 21 2018
 * Last Modified on:		Thu Nov 22 2018
 */

#include <climits>
#include <iostream>
using namespace std;

// Function that takes an input between min and max inclusive, then returns the input.
// Outputs ERROR whenever input is invalid
int input(int min = INT_MIN, int max = INT_MAX) {
	int input;
	while (true) {
		cin >> input;
		if (input >= min && input <= max) {
			return input;
		}
		cout << "ERROR" << endl;
	}
}

// Function that performs insertion sort on given array
void sort(int array[], int size) {
	int notSorted = 1;				 // Holds index of first element of unsorted section of array
	while (notSorted < size) {		 // While there are unsorted elements
		int val = array[notSorted];  // Take the first value of the unsorted section

		// Perform binary search to find the index that val should be moved to within the sorted
		// section of the array
		int min = 0, max = notSorted;
		int mid;  // mid is the average of min and max

		do {
			mid = (min + max) / 2;   // mid is the average of min and max
			if (val < array[mid]) {  // If val is between positions 0 and mid-1
				max = mid;			 // max is the value of mid
			} else {				 // If val is between positions mid and max
				min = mid;			 // min is now mid
			}
		} while (max - min > 1);  // When max and min have a difference of 1, the search is over

		int index = max;  // The index to place val is max

		// Shift everything right to make room for val in the sorted section of the array and
		// increment notSorted
		for (int i = notSorted++; i > index; i--) {
			array[i] = array[i - 1];
		}
		array[index] = val;  // Put val into the correct position of the sorted section of the array
	}
}

// Function that prints the values of a 1D array of integers separated by a space
void printArray(int array[], int n, bool newLine = true) {
	if (n < 1) {
		return;
	}

	cout << array[0];
	for (int i = 1; i < n; i++) {
		cout << " " << array[i];
	}

	if (newLine) {
		cout << endl;
	}
}

int main() {

	cout << "enter 100 numbers:" << endl;  // Prompt for input

	const int N = 10;  // Size of square matrix
	int matrix[N][N];  // Declare matrix of size N*N

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			matrix[i][j] = input(1);  // Input values into matrix
		}
	}

	// Define 1D array 'triangle' to contain a copy of the triangles to sort them
	const int triangleSize =
		N * (N / 2) - (N / 2) * (-N % 2 + 1);  // Number of elements in each triangle (45 when N=10)
	int triangle[triangleSize];
	int ti;  // triangle index to copy values to and from triangle

	// Sort bottom right triangle
	// Copy the bottom right triangle into 1D array 'triangle' in order to sort it
	ti = 0;									// Set triangle index to 0
	for (int i = 1; i < N; i++) {			// Loop through rows
		for (int j = 0; j < i; j++) {		// Loop through elements in each row
			triangle[ti++] = matrix[i][j];  // Copy a value from the matrix into triangle
		}
	}

	sort(triangle, triangleSize);  // Sort the triangle

	// Copy 1D array 'triangle' back into the matrix
	ti = 0;									// Set triangle index to 0
	for (int i = 1; i < N; i++) {			// Loop through rows
		for (int j = 0; j < i; j++) {		// Loop through elements in each row
			matrix[i][j] = triangle[ti++];  // Copy a value from triangle into the matrix
		}
	}

	// Sort top left triangle
	// Copy the top left triangle into 1D array 'triangle' in order to sort it
	ti = 0;									// Set triangle index to 0
	for (int i = 0; i < N - 1; i++) {		// Loop through rows
		for (int j = i + 1; j < N; j++) {   // Loop through elements in each row
			triangle[ti++] = matrix[i][j];  // Copy a value from the matrix into triangle
		}
	}

	sort(triangle, triangleSize);  // Sort the triangle

	// Copy 1D array 'triangle' back into the matrix
	ti = 0;									// Set triangle index to 0
	for (int i = 0; i < N - 1; i++) {		// Loop through rows
		for (int j = i + 1; j < N; j++) {   // Loop through elements in each row
			matrix[i][j] = triangle[ti++];  // Copy a value from triangle into the matrix
		}
	}

	cout << endl << "sorted matrix:" << endl;

	// Print each row of the matrix
	for (int i = 0; i < N; i++) {
		printArray(matrix[i], N);
	}

	return 0;
}

/*
Sample Run:
enter 100 numbers:
1 11 21 31 41 51 61 71 81 91
2 12 22 32 42 52 62 72 82 92
3 13 23 33 43 53 63 73 83 93
4 14 24 34 44 54 64 74 84 94
5 15 25 35 45 55 65 75 85 95
6 16 26 36 46 56 66 76 86 96
7 17 27 37 47 57 67 77 87 97
8 18 28 38 48 58 68 78 88 98
9 19 29 39 49 59 69 79 89 99
10 20 30 40 50 60 70 80 90 100

sorted matrix:
1 11 21 22 31 32 33 41 42 43
2 12 44 51 52 53 54 55 61 62
3 4 23 63 64 65 66 71 72 73
5 6 7 34 74 75 76 77 81 82
8 9 10 13 45 83 84 85 86 87
14 15 16 17 18 56 88 91 92 93
19 20 24 25 26 27 67 94 95 96
28 29 30 35 36 37 38 78 97 98
39 40 46 47 48 49 50 57 89 99
58 59 60 68 69 70 79 80 90 100
*/