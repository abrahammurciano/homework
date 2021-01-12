/*
 * File Name:				2.smallest.cpp
 * Program Description:		Finds the smallest element in an array
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		11
 * Question Number:			2
 * Author:					Abraham Murciano
 *
 * Created on:				Mon Jan 07 2019
 * Last Modified on:		Mon Jan 07 2019
 */

#include <climits>
#include <iostream>
using namespace std;

// Function that finds the index of the lowest element of an array
int smallest(int arr[], int n, int small = 0, int i = 0) {
	if (i >= n) {
		return small;  // When the end of the array is reached, return the smallest index
	}
	// Otherwise check the rest of the array, where small is the index of the the lower value
	// between position small and position i
	return smallest(arr, n, (arr[i] < arr[small] ? i : small), i + 1);
}

int main() {
	int num;
	while (true) {
		cout << "enter a number:" << endl;
		cin >> num;
		if (num > 0) {
			break;
		}
		cout << "ERROR" << endl;
	}
	int* array = new int[num];
	cout << "enter array values: ";
	for (int i = 0; i < num; i++) {
		cin >> array[i];
	}
	cout << "the smallest is: " << array[smallest(array, num)] << endl;

	delete[] array;

	return 0;
}

/*
========== Sample Run - start ==========
enter a number:
3
enter array values: 1 2 3
the smallest is: 1
=========== Sample Run - end ===========
----------------------------------------
========== Sample Run - start ==========
enter a number:
5
enter array values: 5 3 1 2 4
the smallest is: 1
=========== Sample Run - end ===========
----------------------------------------
========== Sample Run - start ==========
enter a number:
4
enter array values: 4 3 2 1
the smallest is: 1
=========== Sample Run - end ===========
----------------------------------------
========== Sample Run - start ==========
enter a number:
0
ERROR
enter a number:
1
enter array values: 3
the smallest is: 3
=========== Sample Run - end ===========
----------------------------------------
*/