/*
 * File Name:				5.setDifference.cpp
 * Program Description:		Given 2 sets, it will output the difference
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		6
 * Question Number:			5
 * Author:					Abraham Murciano
 *
 * Created on:				Mon Nov 12 2018
 * Last Modified on:		Mon Nov 12 2018
 */

#include <climits>
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

	int const N = 6;			// Size of the arrays
	int s1[N], s2[N], diff[N];  // Declare 2 sets and a difference set for the result
	int d = 0;					// Stores the number of elements in the diff set

	cout << "enter first 6 numbers:" << endl;  // Prompt for input
	input(s1, N, 1);						   // Input N values into s1 between 1 and INT_MAX

	cout << "enter next 6 numbers:" << endl;  // Prompt for input
	input(s2, N, 1);						  // Input N values into s2 between 1 and INT_MAX

	// Loop through s1
	for (int i = 0; i < N; i++) {
		bool isUnique = true;  // The ith element of s1 is unique until proven otherwise

		for (int j = 0; j < N; j++) {  // Loop through every element of
			if (s1[i] == s2[j]) {	  // If a duplicate was found in s2,
				isUnique = false;	  // the ith element of s1 isn't unique
				break;
			}
		}

		if (isUnique) {		  // If s1[i] is unique,
			diff[d] = s1[i];  // Add it to the dth position of diff
			d++;			  // And increment diff
		}
	}

	cout << "set difference is:" << endl;
	if (d) {  // If diff doesn't have zero values
		printArray(diff, d);
	} else {
		cout << "empty";
	}
	cout << endl;

	return 0;
}

/*
Sample Run:
enter first 6 numbers:
1 3 5 7 9 10
enter next 6 numbers:
1 2 3 4 5 6
set difference is:
7 9 10

Sample Run:
enter first 6 numbers:
1 3 5 7 9 10
enter next 6 numbers:
1 3 5 7 9 10
set difference is:
empty
*/