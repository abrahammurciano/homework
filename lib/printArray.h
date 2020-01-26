#ifndef printArray_h
#define printArray_h

#include <iostream>
using namespace std;

// Function that prints the values of a 1D array of integers separated by a space
void printArray(int array[], int n, bool newLine = true) {
	for (int i = 0; i < n - 1; i++) {
		cout << array[i] << ' ';
	}

	if (n > 1) {
		cout << array[n - 1];
	}

	if (newLine) {
		cout << endl;
	}
}

#endif
