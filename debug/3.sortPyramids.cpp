/*
 * File Name:				3.sortPyramids.cpp
 * Program Description:		Takes input of 10 by 10 matrix, then sorts the bottom left triangle and
 * the
 * top right triangle
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		7
 * Question Number:			3
 * Author:					Abraham Murciano
 *
 * Created on:				Wed Nov 21 2018
 * Last Modified on:		Wed Nov 21 2018
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

// Function that performs binary search on an array 'arr' and searches for the index of the highest
// value less than (or equal to) 'search'
int binSearch(int arr[], int size, int search) {

	// min is the lowest index 'search' could be at
	// max is the highest index 'search' could be at
	int min = 0, max = size;
	int mid;  // mid is the average of min and max

	do {						  // When max and min cross each other, the search is over
		mid = (min + max) / 2;	// mid is the average of min and max
		if (search < arr[mid]) {  // If search number is in the first half of array
			max = mid;			  // max is the value of mid
		} else {				  // If search number is in the second half of array
			min = mid;			  // min is one more than the value of mid
		}
	} while (max - min > 1);

	return max;  // Return the index of the highest value below search
}

// Function that performs insertion sort on given array
void sort(int array[], int size) {
	int notSorted = 1;
	while (notSorted < size) {
		int val = array[notSorted];
		int index = binSearch(array, notSorted, val);
		for (int i = notSorted++; i > index; i--) {
			array[i] = array[i - 1];
		}
		array[index] = val;
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

	cout << "enter 100 numbers:" << endl;

	const int N = 10;
	int matrix[N][N];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			matrix[i][j] = input(1);
		}
	}

	// Copy bottom left triangle into another array
	const int triangleSize = N * (N / 2) - (N / 2) * (-N % 2 + 1);
	int triangle1[triangleSize];
	int triangle2[triangleSize];
	int ti1 = 0;
	int ti2 = 0;
	for (int i = 0; i < N; i++) {	  // Loop through rows
		for (int j = 0; j < i; j++) {  // Loop through elements in each row
			triangle1[ti1++] = matrix[i][j];
		}
	}

	printArray(triangle1, triangleSize);
	cout << endl;

	sort(triangle1, triangleSize);

	printArray(triangle1, triangleSize);
	cout << endl;

	return 0;
}

/*
Sample Run:

*/