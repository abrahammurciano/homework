#ifndef getText_h
#define getText_h

#include "resize.h"
#include <iostream>
using namespace std;

// Function that reads text from user until a terminator character (\n by default) is input. It will
// then return a pointer to a dynamic array containing all the input.
char* getText(char terminator = '\n') {
	int i = 0;					 // Keeps track of index to be input
	int size = 4;				 // Keeps track of size of dynamically allocated array
	char* str = new char[size];  // Create dynamic string

	while (true) {
		char chtr;
		cin >> noskipws >> chtr;   // Temporarily store input character (could be whitespace)
		if (chtr == terminator) {  // Stop at terminator character
			if (i == 0) {
				continue;  // If first character is a terminator, ignore it
			}
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

#endif