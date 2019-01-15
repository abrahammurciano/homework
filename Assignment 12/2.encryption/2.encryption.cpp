/*
 * File Name:				2.encryption.cpp
 * Program Description:		Encrypts a file
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		12
 * Question Number:			2
 * Author:					Abraham Murciano
 *
 * Created on:				Tue Jan 15 2019
 * Last Modified on:		Tue Jan 15 2019
 */

#include <fstream>
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
		// Temporarily store input character (could be whitespace)
		char chtr = terminator;
		cin >> noskipws >> chtr >> skipws;
		if (chtr == terminator || i == 21) {  // Stop at terminator character
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

int main() {

	cout << "Enter the file name of the file you want to encrypt:" << endl;
	char* path = getText();

	cout << "Enter a file name for the encrypted file:" << endl;
	char* newPath = getText();

	ifstream inFile(path);
	ofstream outFile(newPath);

	delete[] path;
	delete[] newPath;

	while (!inFile.eof()) {
		char c;
		inFile >> c;
		if ('a' <= c && c <= 'z') {
			c = 'a' + 'z' - c;  // Calculate reverse character and replace it
		} else if ('A' <= c && c <= 'Z') {
			c = 'A' + 'Z' - c;  // Calculate reverse character and replace it
		} else if ('0' <= c && c <= '8') {
			c++;
		} else if (c == '9') {
			c = '0';
		}
		outFile << c << endl;
	}

	inFile.close();
	outFile.close();

	return 0;
}