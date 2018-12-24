/*
 * File Name:				1.buses.cpp
 * Program Description:		Bus line management system for Bus Lev company
 * less than 500
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		8
 * Question Number:			1
 * Author:					Abraham Murciano
 *
 * Created on:				Tue Dec 18 2018
 * Last Modified on:		Mon Dec 24 2018
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

	return strict ? -1 : 0;  // Return -1 if strict is true, if not, then return 0
}

// Function that resizes a dynamic array from size to newSize
void resize(int**& arr, int size, int newSize) {
	int** newArr = new int*[newSize];			// Declare new array
	int n = (size < newSize) ? size : newSize;  // Get smallest of the two sizes
	memcpy(newArr, arr, n * sizeof(int*));		// Copy n elements from old to new array
	delete[] arr;								// Delete old array
	arr = newArr;								// Update pointer of arr
}

// Function that adds a line to the system
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

// Function that removes a line from the system
void deleteLine(int**& buses, int& size, int lineId) {
	// Get the position of the line to delete
	int pos = search(buses, size, lineId);
	if (pos >= 0) {  // If it isn't there, dont do anything
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

// Function that lists all the bus lines and their data
void print(int** buses, int size) {
	// Loop through every line
	for (int** pLine = buses; pLine < buses + size; pLine++) {
		// Loop through each field of the line
		for (int* pElem = *pLine; pElem < *pLine + 3; pElem++) {
			cout << *pElem << ' ';
		}
		cout << endl;
	}
}

// Function that calculates the average travel time of all the bus lines
float averageTravel(int** buses, int size) {
	int sum = 0;									// Initialise sum to 0
	for (int** p = buses; p < buses + size; p++) {  // Loop through all the lines
		sum += *(*p + 2);							// Add the travel time to sum
	}
	return (size) ? (float)sum / size : 0;  // Return sum/size, or 0 if size is 0
}

// Function that calculates the average number of stops of all the bus lines
int averageStops(int** buses, int size) {
	int sum = 0;									// Initialise sum to 0
	for (int** p = buses; p < buses + size; p++) {  // Loop through all the lines
		sum += *(*p + 1);							// Add the travel time to sum
	}
	// Return sum/size, rounded to the nearest integer or 0 if size is 0
	return (size) ? sum / size + (sum % size >= (float)size / 2) : 0;
}

// Function that returns the bus line with the shortest travel time
int shortest(int** buses, int size) {
	int line = -1;				 // Set line to -1 in case there are no lines in the system
	int shortestTime = INT_MAX;  // Set time to the largest integer
	for (int** p = buses; p < buses + size; p++) {  // Loop through bus lines
		if (*(*p + 2) < shortestTime) {  // If the bus line is shorter than the shortest so far
			shortestTime = *(*p + 2);	// Update shortest
			line = **p;					 // Update line
		}
	}
	return line;
}

int main() {

	int** buses = 0;  // Matrix to hold all buses' data
	int nBuses = 0;   // Store the number of buses in the system
	int choice;		  // Keep track of user's action choice

	do {

		cout << "enter 0-7" << endl;  // Prompt for input
		cin >> choice;

		// Check for invalid choice
		if (choice < 0 || choice > 7) {
			cout << "ERROR" << endl;
		}

		// Add a bus line
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

		// Delete a bus line
		else if (choice == 2) {
			int lineId;
			cout << "enter the line to delete" << endl;
			cin >> lineId;

			deleteLine(buses, nBuses, lineId);
		}

		// Print all data in the system
		else if (choice == 3) {
			print(buses, nBuses);
		}

		// Search for a bus line
		else if (choice == 4) {
			int lineId;
			cout << "enter the line to search for" << endl;
			cin >> lineId;
			cout << search(buses, nBuses, lineId) << endl;
		}

		// Print average travel time
		else if (choice == 5) {
			cout << averageTravel(buses, nBuses) << endl;
		}

		// Print average number of stops
		else if (choice == 6) {
			cout << averageStops(buses, nBuses) << endl;
		}

		// Print the shortest travel time
		else if (choice == 7) {
			cout << shortest(buses, nBuses) << endl;
		}

	} while (choice);

	return 0;
}

/*
========== Sample Run - start ==========
enter 0-7
1
enter the line to add
39
enter the number of stops
36
enter the duration of the ride
56
enter 0-7
1
enter the line to add
6
enter the number of stops
22
enter the duration of the ride
42
enter 0-7
1
enter the line to add
52
enter the number of stops
19
enter the duration of the ride
35
enter 0-7
2
enter the line to delete
6
enter 0-7
3
39 36 56
52 19 35
enter 0-7
4
enter the line to search for
39
0
enter 0-7
4
enter the line to search for
52
1
enter 0-7
4
enter the line to search for
6
-1
enter 0-7
5
45.5
enter 0-7
6
28
enter 0-7
7
52
enter 0-7
0
=========== Sample Run - end ===========
----------------------------------------
*/
