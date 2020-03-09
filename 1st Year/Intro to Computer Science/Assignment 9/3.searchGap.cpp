/*
 * File Name:				3.searchGap.cpp
 * Program Description:		Inputs 2 strings and prints the gap size
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		9
 * Question Number:			3
 * Author:					Abraham Murciano
 *
 * Created on:				Wed Dec 26 2018
 * Last Modified on:		Wed Dec 26 2018
 */

#include <iostream>
using namespace std;

// Function that resizes a dynamic array from size to newSize
void resize(char*& arr, int size, int newSize) {
	char* newArr = new char[newSize];			// Declare new array
	int n = (size < newSize) ? size : newSize;  // Get smallest of the two sizes
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
	char* str = new char[size];  // Create dynamic string

	while (true) {
		char chtr;
		cin >> noskipws >> chtr;  // Temporarily store input character (could be whitespace)
		if (chtr == terminator || i == 80) {  // Stop at terminator character (or 80)
			str[i] = '\0';
			return str;
		} else {
			if (i >= size) {  // Check if array is too small to hold another character
				// Double size of array
				int newSize = size * 2;
				resize(str, size, newSize);
				size = newSize;
			}
			str[i++] = chtr;  // Put input into array
		}
	}
}

// Function that finds the size of a string
int strSize(char* str) {
	int size;
	for (size = 0; str[size] != '\0'; size++) continue;
	return size;
}

// Function that gets the gap of word in text
int getGap(char* text, char* word) {
	int tSize = strSize(text);  // Get size of text
	int wSize = strSize(word);  // Get size of word

	// Loop through text
	for (int i = 0; i < tSize; i++) {
		// Repeat for every gap that will still fit word in text
		for (int gap = 0; i + (wSize - 1) * (gap + 1) < tSize; gap++) {
			// Loop through word
			for (int j = 0; j < wSize; j++) {
				// Check if the letter after the next gap matches the next letter of word
				if (word[j] != text[i + j * (gap + 1)]) {  // If it doesn't match
					break;								   // Break, and check the next gap
				}
				// If everything was a match so far, and we already checked the last letter of word
				if (j == wSize - 1) {
					return gap;  // There is a match of gap size 'gap'
				}
			}
		}
	}

	return -1;  // If there was no match return -1
}

int main() {

	cout << "enter text: " << flush;  // Prompt for input
	char* text = getText();			  // Read in a line until input is \n

	cout << "enter word: " << flush;  // Prompt for input
	char* word = getText();			  // Read in a line until input is \n

	int gap = getGap(text, word);  // Perform search

	cout << "size of jump: " << gap << endl;  // Print output

	return 0;
}

/*
========== Sample Run - start ==========
enter text: yesterday
enter word: sed
size of jump: 1
=========== Sample Run - end ===========
----------------------------------------
========== Sample Run - start ==========
enter text: parallelogram
enter word: pem
size of jump: 5
=========== Sample Run - end ===========
----------------------------------------
*/