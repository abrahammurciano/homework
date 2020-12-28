/*
 * File Name:				2.reverseSentence.cpp
 * Program Description:		Reads in a sentence and reverses each word in the sentence
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		9
 * Question Number:			2
 * Author:					Abraham Murciano
 *
 * Created on:				Mon Dec 24 2018
 * Last Modified on:		Mon Dec 24 2018
 */

#include <cstring>
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

// Function that reverses the order of an array of characters starting at location start and ending
// at location end
void reverseWord(char* start, char* end) {
	int size = (end - start) + 1;  // Calculate size
	char* tmp = new char[size];	// Make a temporary array of that size
	for (int i = 0; i < size; i++) {
		tmp[i] = end[-i];  // Copy the array to temp in reverse order
	}
	for (int i = 0; i < size; i++) {
		start[i] = tmp[i];  // Copy the array back, already reversed
	}
	delete[] tmp;  // Delete temporary array
}

// Function that splits a string into substrings, separated by delim (space by default) and then
// sends them into the reverseWord function
char* reverse(char str[], char delim = ' ') {
	int size;
	for (size = 1; str[size] != '\0'; size++) continue;  // Get size of string

	// Make a copy of str
	char* newStr = new char[size];
	memcpy(newStr, str, size);

	int wordStart = 0;		   // Position where each word begins
	int wordEnd = 0;		   // Position where each word ends
	bool strFinished = false;  // Flag to determine if there are any more words

	do {  // Do while the string is not finished

		// Look for start of next word
		for (int i = wordEnd; newStr[i] != '\0'; i++) {
			if (newStr[i] != delim && (newStr[i - 1] == delim || i == 0)) {
				wordStart = i;
				break;
			}
		}

		// Look for the end of the next word
		for (int i = wordStart; newStr[i] != '\0'; i++) {
			if (newStr[i] != delim && (newStr[i + 1] == delim || newStr[i + 1] == '\0')) {
				wordEnd = i;
				break;
			}
		}

		// Reverse the next word
		reverseWord(&newStr[wordStart], &newStr[wordEnd]);

		// Check if there are any more words
		strFinished = true;
		for (int i = wordEnd + 1; newStr[i] != '\0'; i++) {
			if (newStr[i] != delim) {
				strFinished = false;
				break;
			}
		}

	} while (!strFinished);

	return newStr;
}

int main() {

	cout << "enter a string:" << endl;
	char* str = getText();  // Read in until user presses enter

	char* newStr = reverse(str);  // Reverse the words of str
	delete[] str;				  // Delete the old string

	cout << "after reverse: " << newStr << endl;
	delete[] newStr;  // Delete the new string

	return 0;
}

/*
========== Sample Run - start ==========
enter a string:
hello bob supercalifragilisticexpialidocious
after reverse: olleh bob suoicodilaipxecitsiligarfilacrepus
=========== Sample Run - end ===========
----------------------------------------
*/