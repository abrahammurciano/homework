/*
 * File Name:				4.reverse.cpp
 * Program Description:		Reverses an array recursively
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		11
 * Question Number:			4
 * Author:					Abraham Murciano
 *
 * Created on:				Tue Jan 08 2019
 * Last Modified on:		Tue Jan 08 2019
 */

#include <iostream>
using namespace std;

void reverse(int arr[], int n) {
	if (n > 1) {
		swap(arr[0], arr[n - 1]);  // Swap the first and last element
		reverse(arr + 1, n - 2);   // Repeat for the rest of the array
	}
}

// Function that prints the values of a 1D array of integers separated by a space
void printArray(int array[], int n, bool newLine = true) {
	for (int i = 0; i < n - 1; i++) {
		cout << array[i] << ' ';
	}

	if (n > 0) {
		cout << array[n - 1];
	}

	if (newLine) {
		cout << endl;
	}
}

int main() {
	int n;
	cout << "enter a number:" << endl;
	cin >> n;

	int* arr = new int[n];
	cout << "enter array values:" << endl;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << "before:" << endl;
	printArray(arr, n);

	reverse(arr, n);

	cout << "after:" << endl;
	printArray(arr, n);

	delete[] arr;

	return 0;
}

/*
========== Sample Run - start ==========
enter a number:
6
enter array values:
1 2 3 4 5 6
before:
1 2 3 4 5 6
after:
6 5 4 3 2 1
=========== Sample Run - end ===========
----------------------------------------
========== Sample Run - start ==========
enter a number:
5
enter array values:
9 7 5 3 1
before:
9 7 5 3 1
after:
1 3 5 7 9
=========== Sample Run - end ===========
----------------------------------------
*/