/*
 * File Name:				2.mergeArrays.cpp
 * Program Description:		Reads in 3 sorted lists and prints a merged list
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		7
 * Question Number:			2
 * Author:					Abraham Murciano
 *
 * Created on:				Tue Nov 20 2018
 * Last Modified on:		Tue Nov 20 2018
 */

#include <iostream>
using namespace std;

// Function that reads in up to 'maxSize' values into 'arr' until 0 is entered, then it returns the
// number of values that have been input
int input(int arr[], int maxSize) {
	int size = 0;						 // Store number of input values
	for (int i = 0; i < maxSize; i++) {  // Read in up to maxSize elements
		cin >> arr[i];
		if (arr[i]) {
			size++;  // If input was not 0, increment size
		} else {
			break;
		}
	}

	return size;
}

// Function that checks if input list is sorted and positive, if not it will output "ERROR" and
// await input again
int inputDesc(int arr[], int max) {
	while (true) {
		int size = input(arr, max);  // Call input, and store size of input
		if (size == 0) {
			return size;  // If no elements were input, no need to validate
		}

		bool valid = true;  // input is valid until prove otherwise

		if (arr[0] < 0) {
			valid = false;  // If the first element is negative, input is invalid
		}

		// Repeat until input is invalid or all elements have been checked
		// Start from second element because first was already checked
		for (int i = 1; i < size && valid; i++) {
			if (arr[i] >= arr[i - 1] || arr[i] < 0) {  // If negative or bigger than previous one
				valid = false;						   // Input is invalid
			}
		}

		if (valid) {
			return size;  // If after loop, input is still valid, return number of inputs
		}

		cout << "ERROR" << endl;
	}
}

// Merges two sorted arrays, arr1 and arr2, of sizes size1 and size2 respectively
// Stores result in array arr
int mergeDescending(int arr[], const int arr1[], int size1, const int arr2[], int size2) {
	int i1 = 0, i2 = 0;  // Set 2 indices to 0, one for each of arr1 and arr2
	int sizeMerged = 0;  // Keeps track of the size of the merged array arr

	// Repeat until either of arr1 or arr2 have been mereged
	while (i1 < size1 && i2 < size2) {
		// Copy the grater of the next value of arr1 and arr2 into the next position of arr
		// Then increment sizeMerged and i1 or i2, depending on which array was coppied from
		arr[sizeMerged++] = (arr1[i1] > arr2[i2]) ? arr1[i1++] : arr2[i2++];
	}

	// Merge the rest of arr1 (if it exists)
	while (i1 < size1) {
		arr[sizeMerged++] = arr1[i1++];
	}

	// Merge the rest of arr2 (if it exists)
	while (i2 < size2) {
		arr[sizeMerged++] = arr2[i2++];
	}

	return sizeMerged;
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

	const int N = 10;				   // Max size of the lists
	int list1[N], list2[N], list3[N];  // Declare lists
	int size1, size2, size3;		   // Declare sizes

	cout << "enter values for the first vector:" << endl;  // Prompt for list1
	size1 = inputDesc(list1, N);						   // Input & validate list, then get size

	cout << "enter values for the second vector:" << endl;  // Prompt for list2
	size2 = inputDesc(list2, N);							// Input & validate list, then get size

	cout << "enter values for the third vector:" << endl;  // Prompt for list3
	size3 = inputDesc(list3, N);						   // Input & validate list, then get size

	int merged_1_2[size1 + size2];			  // A merged array of list1 and list2
	int merged_1_2_3[size1 + size2 + size3];  // A merged array of list1, list2 and list3

	// Merge list1 and list2 into merged_1_2
	int size_1_2 = mergeDescending(merged_1_2, list1, size1, list2, size2);

	// Merge merged_1_2 and list 3 into merged_1_2_3
	int size_1_2_3 = mergeDescending(merged_1_2_3, merged_1_2, size_1_2, list3, size3);

	cout << "merged vector is:" << endl;
	printArray(merged_1_2_3, size_1_2_3);  // Print the merged array
	cout << endl;

	return 0;
}

/*
Sample Run:
enter values for the first vector:
3 2 1 0
enter values for the second vector:
21 19 17 14 13 12 9 6 3 2
enter values for the third vector:
6 4 2 0
merged vector is:
21 19 17 14 13 12 9 6 6 4 3 3 2 2 2 1

Sample Run:
enter values for the first vector:
4 2 0
enter values for the second vector:
5 4 3 3 0
ERROR
5 23 0
ERROR
4 3 0
enter values for the third vector:
7 6 5 4 3 2 1 0
merged vector is:
7 6 5 4 4 4 3 3 2 2 1
*/