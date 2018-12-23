/*
 * File Name:				1.buses.cpp
 * Program Description:		----
 * less than 500
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		8
 * Question Number:			1
 * Author:					Abraham Murciano
 *
 * Created on:				Tue Dec 18 2018
 * Last Modified on:		Tue Dec 18 2018
 */

#include <climits>
#include <cstring>
#include <iostream>
using namespace std;

// Function that will return the row number of a bus line if it exists, or -1 if it doesn't.
// If 'strict' is set to false, the next bus line's position is returned instead of -1.
int search(int** buses, int size, int lineId, bool strict = true) {

	// min is the lowest index 'lineId' could be at
	// max is the highest index 'lineId' could be at
	int min = 0, max = size - 1;

	while (max >= min) {				 // When max and min cross each other, the search is over
		int mid = (min + max) / 2;		 // mid is the average of min and max
		if (lineId < **(buses + mid)) {  // If search number is in the first half of array
			max = mid - 1;				 // max is 1 less than the value at mid
			// If search number is more than the value at max
			if (max < min || lineId > **(buses + max)) {
				return strict ? -1 : mid;  // There is no result
			}
		} else if (lineId > **(buses + mid)) {  // If search number is in the second half of array
			min = mid + 1;						// min is one more than the value at mid
			// If search number is less than the value at min
			if (min > max || lineId < **(buses + min)) {
				return strict ? -1 : min;  // There is no result
			}
		} else {
			// if lineId isn't more or less than the value at mid, it's the same as the value at mid
			return mid;
		}
	}

	return strict ? -1 : 0;
}

void resize(int**& arr, int size, int newSize) {
	int** newArr = new int*[newSize];
	int n = (size < newSize) ? size : newSize;
	memcpy(newArr, arr, n * sizeof(int*));
	delete[] arr;
	arr = newArr;
}

void addLine(int**& buses, int& size, int lineId, int nStops, int duration) {

	// Enlarge buses by 1
	int newSize = size + 1;
	resize(buses, size, newSize);

	// Find position for new line
	int pos = search(buses, size, lineId, false);

	// Make room for the new bus line in the correct location
	for (int** p = buses + size; p > buses + pos; p--) {
		*p = *(p - 1);
	}

	// Insert new bus line
	int* line = new int[3]{lineId, nStops, duration};
	*(buses + pos) = line;

	size = newSize;  // Update size
}

void deleteLine(int**& buses, int& size, int lineId) {
	int pos = search(buses, size, lineId);
	if (pos >= 0) {
		// Shift everything after lineId back one space
		for (int** p = buses + pos; p < buses + size - 1; p++) {
			*p = *(p + 1);
		}

		// Shrink buses by 1
		int newSize = size - 1;
		resize(buses, size, newSize);
		size--;
	}
}

void print(int** buses, int size) {
	for (int** pLine = buses; pLine < buses + size; pLine++) {
		for (int* pElem = *pLine; pElem < *pLine + 3; pElem++) {
			cout << *pElem << ' ';
		}
		cout << endl;
	}
}

float averageTravel(int** buses, int size) {
	int sum = 0;
	for (int** p = buses; p < buses + size; p++) {
		sum += *(*p + 2);
	}
	return (size) ? (float)sum / size : 0;
}

int averageStops(int** buses, int size) {
	int sum = 0;
	for (int** p = buses; p < buses + size; p++) {
		sum += *(*p + 1);
	}
	return (size) ? sum / size + (sum % size >= (float)size / 2) : 0;
}

int shortest(int** buses, int size) {
	int line = -1;
	int shortestTime = INT_MAX;
	for (int** p = buses; p < buses + size; p++) {
		if (*(*p + 2) < shortestTime) {
			shortestTime = *(*p + 2);
			line = **p;
		}
	}
	return line;
}

int main() {

	int** buses = 0;
	int nBuses = 0;
	int choice;

	do {

		cout << "enter 0-7" << endl;
		cin >> choice;

		if (choice < 0 || choice > 7) {
			cout << "ERROR" << endl;
		}

		else if (choice == 1) {
			int lineId;
			cout << "enter the line to add" << endl;
			cin >> lineId;

			int nStops;
			cout << "enter the number of stops" << endl;
			cin >> nStops;

			int duration;
			cout << "enter the duration of the ride" << endl;
			cin >> duration;

			addLine(buses, nBuses, lineId, nStops, duration);
		}

		else if (choice == 2) {
			int lineId;
			cout << "enter the line to delete" << endl;
			cin >> lineId;

			deleteLine(buses, nBuses, lineId);
		}

		else if (choice == 3) {
			print(buses, nBuses);
		}

		else if (choice == 4) {
			int lineId;
			cout << "enter the line to search for" << endl;
			cin >> lineId;
			cout << search(buses, nBuses, lineId) << endl;
		}

		else if (choice == 5) {
			cout << averageTravel(buses, nBuses) << endl;
		}

		else if (choice == 6) {
			cout << averageStops(buses, nBuses) << endl;
		}

		else if (choice == 7) {
			cout << shortest(buses, nBuses) << endl;
		}

	} while (choice);

	return 0;
}

/*
========== Sample Run - start ==========

=========== Sample Run - end ===========
----------------------------------------
*/
