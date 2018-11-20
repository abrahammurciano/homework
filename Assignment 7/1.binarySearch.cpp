/*
 * File Name:				1.binarySearch.cpp
 * Program Description:		Given a sorted list and a number, it will perform binary search
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		7
 * Question Number:			1
 * Author:					Abraham Murciano
 *
 * Created on:				Tue Nov 20 2018
 * Last Modified on:		Tue Nov 20 2018
 */

#include <climits>
#include <iostream>
using namespace std;

// Function that performs binary search on an array 'arr' and searches for the value of 'search'
int binSearch(int arr[], int size, int search) {

	// min is the lowest index 'search' could be at
	// max is the highest index 'search' could be at
	int min = 0, max = size - 1;

	while (max >= min) {				 // When max and min cross each other, the search is over
		int mid = (min + max) / 2;		 // mid is the average of min and max
		if (search < arr[mid]) {		 // If search number is in the first half of array
			max = mid - 1;				 // max is 1 less than the value at mid
		} else if (search > arr[mid]) {  // If search number is in the second half of array
			min = mid + 1;				 // min is one more than the value at mid
		} else {  // if search isn't more or less than the value at mid, it's the same as the value
				  // at mid
			return mid;
		}
	}

	return -1;  // If the while loop never returns an index, there is no result
}

int main() {
	int const N = 10;  // Size of array
	int array[N];	  // Declare array to store user input

	cout << "enter 10 numbers:" << endl;  // Prompt for input
	while (true) {
		bool sorted = true;  // Flag to store if array is in ascending order or not

		for (int i = 0; i < N; i++) {  // Loop through array
			cin >> array[i];		   // Input a value into position i

			// If loop isn't by the first element or array[i] is less than the previous element
			if (i && (array[i] <= array[i - 1])) {
				sorted = false;  // The array isn't sorted
			}
		}

		if (sorted) {
			break;
		}

		cout << "ERROR" << endl;
	}

	cout << "enter 1 number:" << endl;  // Prompt for input

	int n;
	cin >> n;  // Read in a value to search for

	int index = binSearch(array, N, n);  // Perform binary search and store result in index

	if (index < 0) {  // If it was not found
		cout << "not found" << endl;
	} else {
		cout << "the number " << n << " was found at index " << index << endl;  // Print result
	}

	return 0;
}

/*
Sample Run:
enter 10 numbers:
1 3 5 7 9 11 13 15 17 19
enter 1 number:
9
the number 9 was found at index 4

Sample Run:
enter 10 numbers:
1 3 5 5 9 11 13 15 17 19
ERROR
1 3 5 7 9 11 13 15 17 19
enter 1 number:
12
not found
*/