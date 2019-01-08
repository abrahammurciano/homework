/*
 * File Name:				3.selectionSort.cpp
 * Program Description:		Performs selection sort recursively
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		11
 * Question Number:			3
 * Author:					Abraham Murciano
 *
 * Created on:				Tue Jan 08 2019
 * Last Modified on:		Tue Jan 08 2019
 */

#include <climits>
#include <iostream>
using namespace std;

void swap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}

// Function that finds the index of the smallest element in an array
int smallest(int arr[], int n, int s = 0, int i = 0) {
	return i >= n ? s : smallest(arr, n, (arr[s] < arr[i] ? s : i), i + 1);
}

// Function that performs insetion sort on an array
void sort(int arr[], int n) {
	if (n) {
		swap(arr[0], arr[smallest(arr, n)]);
		sort(arr + 1, n - 1);
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

	int num;

	while (true) {
		cout << "enter a number:" << endl;
		cin >> num;
		if (num > 0) {
			break;
		}
		cout << "ERROR" << endl;
	}

	int* arr = new int[num];

	cout << "enter array values:" << endl;
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}

	cout << "before:" << endl;
	printArray(arr, num);

	sort(arr, num);

	cout << "after:" << endl;
	printArray(arr, num);

	delete[] arr;

	return 0;
}

/*
========== Sample Run - start ==========
enter a number:
6
enter array values:
2 5 7 5 3 1
before:
2 5 7 5 3 1
after:
1 2 3 5 5 7
=========== Sample Run - end ===========
----------------------------------------
*/