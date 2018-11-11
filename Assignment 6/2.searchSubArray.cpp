/*
 * File Name:				2.searchSubArray.cpp
 * Program Description:		Takes 2 lists as input & outputs the number of times the 2nd one is
 * repeated in the 1st one.
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		6
 * Question Number:			2
 * Author:					Abraham Murciano
 *
 * Created on:				Sun Nov 11 2018
 * Last Modified on:		Sun Nov 11 2018
 */

#include <climits>  // Used to set defaults to the input function
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

// Function that takes length inputs between min and max inclusive, then assigns them to array.
void input(int array[], int length, int min = INT_MIN, int max = INT_MAX) {
	for (int i = 0; i < length; i++) {
		array[i] = input(min, max);
	}
}

int main() {

	int vector1[500], vector2[100];  // Declare the 2 arrays
	int n1, n2;						 // Variables to hold the 2 sizes of the vectors

	cout << "enter size of first array:" << endl;  // Prompt for vactor1 size
	n1 = input(1, 500);							   // Read in vector1 size

	cout << "enter first array values:" << endl;  // Prompt for vector1 values
	input(vector1, n1);							  // Read in vector1 values

	cout << "enter size of second array:" << endl;  // Prompt for vactor2 size
	n2 = input(1, 100);								// Read in vector2 size

	cout << "enter second array values:" << endl;  // Prompt for vector2 values
	input(vector2, n2);							   // Read in vector2 values

	int count = 0;  // Counter for number of matches of vector 2 in vector 1

	// Loops through vector1 until the last value that can fit vector2 after itself
	for (int i = 0; i < (n1 - n2) + 1; i++) {

		// Set match flag to true indicating that vactor1[i] is the beginning of a match, until
		// proven otherwise
		bool match = true;

		// Loop through vector2 to check if each value is the same as the corresponding value after
		// vector1[i]
		for (int j = 0; j < n2; j++) {
			// If any value of vector1 and vector2 dont match, this isn't a match and skip to next
			// value of vector1
			if (vector1[i + j] != vector2[j]) {
				match = false;
				break;
			}
		}

		// If vector1[i] is the begining of a valid match, increment count
		if (match) {
			count++;
		}
	}

	cout << "result: " << count << " times" << endl;  // Output result

	return 0;
}

/*
enter size of first array:
18
enter first array values:
1 2 3 4  5  6 1 2 3 4 5 6 1 2 3 4 5 6
enter size of second array:
4
enter second array values:
2 3 4 5
result: 3 times
*/