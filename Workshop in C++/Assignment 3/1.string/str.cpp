/*
 * File Name:				str.cpp
 * Program Description:		Implementation of a string class
 * Course Name:				Workshop in C++
 * Assignment Number:		3
 * Question Number:			1
 * Author:					Abraham Murciano
 */

#include "str.h"
#include <iostream>
using namespace std;

// Constructor to create a str object from a string literal
str::str(const char* s) {
	int l = 0;  // Length of string literal
	while (s[l] != '\0') {
		l++;
	}

	capacity = l + 1;
	len = l;

	array = new char[capacity];  // Allocate memory
	for (int i = 0; i < capacity; i++) {
		array[i] = s[i];
	}
}

// Constructor to make a string of he same character, eg 'aaaaa'
str::str(const char c, const int l) {
	capacity = l + 1;
	len = l;
	for (int i = 0; i < l; i++) {
		array[i] = c;
	}
	array[l] = '\0';
}

// Copy constructor
str::str(const str& s) {
	capacity = s.capacity;
	len = s.len;
	array = new char[capacity];
	for (int i = 0; i < capacity; i++) {
		array[i] = s[i];
	}
}

// Method to extend the memory allocated to the string by l characters
void str::extend(const int l) {
	if (l > 0) {
		char* tempPtr = array;
		array = new char[capacity += l];
		for (int i = 0; i < len; i++) {
			array[i] = tempPtr[i];
		}
		array[len] = '\0';
		delete[] tempPtr;
	}
}

// Get number of characters in string
int str::length() const {
	return len;
}

// Get number of characters in string
int str::size() const {
	return length();
}

// Print the string to the console (optionally followed by a new line)
void str::print(const bool newLine) const {
	cout << array;
	if (newLine) {
		cout << endl;
	}
}

// Prompt a user for input, then read in a string until a delimiter (\n by default) is read
void str::input(const str prompt, const char delim) {

	// Overwrite the old string
	delete[] array;
	array = new char[4];
	len = 0;
	capacity = 4;

	// Prompt for input
	if (prompt.len) {
		prompt.print(true);
	}

	// Read in first character that is not white space
	char c = delim;
	cin >> c;
	cin >> noskipws;  // Read whitespace

	// Read in character at a time
	while (true) {
		if (c != delim) {
			// If running low on space, double capacity
			if (len >= capacity - 1) {
				extend(capacity);
			}
			array[len++] = c;
			array[len] = '\0';
			cin >> c;
		} else {
			if (len != 0) {
				array[len] = '\0';
				break;
			}
		}
	}
	cin >> skipws;
}

// Insert string s into string at position i
str& str::insert(const str& s, int i) {
	if (i <= len && i >= 0) {  // Check if not out of bounds of the string

		// If no space for both strings, allocate more memory
		if (capacity < len + s.len + 1) {
			extend(len + s.len + 1 - capacity);
		}

		// Copy second part of string to make space for s
		for (int j = len; j >= i; j--) {
			array[j + s.len] = array[j];
		}

		// Copy s into position i
		for (int j = 0; j < s.len; j++) {
			array[i + j] = s[j];
		}
	}
	return *this;
}

// Return a lowercase copy of the string
str str::lower() const {
	str lowerCase = *this;
	for (int i = 0; lowerCase[i] != '\0'; i++) {
		if (lowerCase[i] >= 'A' && lowerCase[i] <= 'Z') {
			lowerCase[i] -= 'A' - 'a';
		}
	}
	return lowerCase;
}

// Return an uppercase copy of the string
str str::upper() const {
	str upperCase = *this;
	for (int i = 0; upperCase[i] != '\0'; i++) {
		if (upperCase[i] >= 'a' && upperCase[i] <= 'z') {
			upperCase[i] -= 'a' - 'A';
		}
	}
	return upperCase;
}

// Subscript operator to get letters at specific locations of string
char& str::operator[](const int i) const {
	return array[i];
}

str& str::operator=(const str& s) {
	if (this != &s) {
		capacity = s.capacity;
		len = s.len;
		delete[] array;
		array = new char[capacity];
		for (int i = 0; i < capacity; i++) {
			array[i] = s[i];
		}
	}
}

// Append a string to current string
str& str::operator+=(const str& s) {
	if (capacity < len + s.len + 1) {
		extend(len + s.len + 1 - capacity);
	}
	for (int i = 0; i < s.len; i++) {
		array[len + i] = s[i];
	}
	len += s.len;
	return *this;
}

// Concatenate two strings
str str::operator+(const str& s) const {
	str temp = *this;
	temp += s;
	return temp;
}

// Check if two strings are identical
bool str::operator==(const str& s) const {
	str left = (*this).lower();
	str right = s.lower();

	if (left != right.len) {
		return false;
	}

	for (int i = 0; i < len; i++) {
		if (left[i] != right[i]) {
			return false;
		}
	}

	return true;
}

// Check if two strings are different
bool str::operator!=(const str& s) const {
	return !(*this == s);
}

// Check if string is before s in lexicographical order
bool str::operator<(const str& s) const {
	str left = (*this).lower();
	str right = s.lower();

	int minLen = (left.len < right.len) ? left.len : right.len;

	for (int i = 0; i < minLen; i++) {
		if (left[i] < right[i]) {
			return true;
		} else if (left[i] > right[i]) {
			return false;
		}
	}

	return left.len < right.len;
}

// Check if string is before s in lexicographical order or they are equal
bool str::operator<=(const str& s) const {
	str left = (*this).lower();
	str right = s.lower();

	int minLen = (left.len < right.len) ? left.len : right.len;

	for (int i = 0; i < minLen; i++) {
		if (left[i] < right[i]) {
			return true;
		} else if (left[i] > right[i]) {
			return false;
		}
	}

	return left.len <= right.len;
}

// Check if string is after s in lexicographical order
bool str::operator>(const str& s) const {
	return !(*this <= s);
}

// Check if string is after s in lexicographical order or they are equal
bool str::operator>=(const str& s) const {
	return !(*this < s);
}