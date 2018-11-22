#ifndef input_h
#define input_h

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

#endif