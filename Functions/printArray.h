#ifndef printArray_h
#define printArray_h

#include <iostream>
using namespace std;

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

#endif
