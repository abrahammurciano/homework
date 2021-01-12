/*
 * File Name:				1.crypto.cpp
 * Program Description:		Converts each character between a and z (lowercase) in str into the
 * reverse character. For example, a becomes z, z -> a, b -> y, c -> x, etc.
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		9
 * Question Number:			1
 * Author:					Abraham Murciano
 *
 * Created on:				Mon Dec 24 2018
 * Last Modified on:		Tue Dec 25 2018
 */

#include <iostream>
using namespace std;

// Function that resizes a dynamic array from size to newSize
void resize(char*& arr, int size, int newSize) {
	char* newArr = new char[newSize];			// Declare new array
	int n = (size < newSize) ? size : newSize;	// Get smallest of the two sizes
	// Copy n elements from old to new array
	for (int i = 0; i < n; i++) {
		newArr[i] = arr[i];
	}
	delete[] arr;  // Delete old array
	arr = newArr;  // Update pointer of arr
}

// Function that reads text from user until a terminator character (\n by default) is input. It will
// then return a pointer to a dynamic array containing all the input.
char* getText(char terminator = '\n') {
	int i = 0;					 // Keeps track of index to be input
	int size = 4;				 // Keeps track of size of dynamically allocated array
	char* str = new char[size];	 // Create dynamic string

	while (true) {
		char c;
		cin >> noskipws >> c;  // Temporarily store input character (could be whitespace)
		if (i >= size) {	   // Check if array is too small to hold another character
			// Double size of array
			int newSize = size * 2;
			resize(str, size, newSize);
			size = newSize;
		}
		if (c == terminator || i == 80) {  // Stop at terminator character (or 80)
			str[i] = '\0';
			return str;
		}
		str[i++] = c;  // Put input into array
	}
}

// Function that converts each character between a and z (lowercase) in str into the reverse
// character. For example, a becomes z, z -> a, b -> y, c -> x, etc. Then returns a pointer to a new
// array containing the new string
char* crypto(char str[]) {
	int size;
	for (size = 0; str[size] != '\0'; ++size) continue;	 // Get size of str
	++size;												 // Make one extra space for '\0'

	char* newStr = new char[size];	// Make new array of same size
	newStr[size - 1] = '\0';

	for (int i = 0; str[i] != '\0'; i++) {	// Loop until null terminator is found
		// Check if character is between 'a' and 'z' in the ASCII table
		if ('a' <= str[i] && str[i] <= 'z') {
			newStr[i] = 'a' + 'z' - str[i];	 // Calculate reverse character and replace it
		} else {
			newStr[i] = str[i];	 // Else copy character from old string to new string
		}
	}
	return newStr;	// Return the new string
}

int main() {

	cout << "enter a string: " << flush;  // Prompt for input
	char* str = getText();				  // Read in until user presses enter

	char* newStr = crypto(str);	 // Encode str
	delete[] str;

	// Print processes string
	cout << "after crypto:" << endl;
	cout << newStr << endl;

	delete[] newStr;

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