/*
 * File Name:				9.crypto.cpp
 * Program Description:		----
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		#
 * Question Number:			#
 * Author:					Abraham Murciano
 *
 * Created on:				Mon Dec 24 2018
 * Last Modified on:		Mon Dec 24 2018
 */

#include <iostream>
using namespace std;

// Function that converts each character between a and z (lowercase) in str into the reverse
// character. For example, a becomes z, z -> a, b -> y, c -> x, etc.
void crypto(char str[]) {
	for (int i = 0; str[i] != '\0'; i++) {  // Loop until null terminator is found
		// Check if character is between 'a' and 'z' in the ASCII table
		if ('a' <= str[i] && str[i] <= 'z') {
			str[i] = 'a' + 'z' - str[i];  // Calculate reverse character and replace it
		}
	}
}

int main() {

	int const N = 81;			 // Max length of string
	char str[N];				 // Declare array to hold the string
	cout << "enter a string: ";  // Prompt for input
	cin.getline(str, N);		 // Read in until user presses enter

	crypto(str);

	// Print processes string
	cout << "after crypto:" << endl;
	cout << str << endl;

	return 0;
}

/*
========== Sample Run - start ==========
enter a string: Hello, World!
after crypto:
Hvool, Wliow!
=========== Sample Run - end ===========
----------------------------------------
*/