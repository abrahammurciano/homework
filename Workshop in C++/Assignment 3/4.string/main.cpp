/*
 * File Name:				main.cpp
 * Program Description:		A program that uses the string class
 * Course Name:				Workshop in C++
 * Assignment Number:		3
 * Question Number:			4
 * Author:					Abraham Murciano
 */

#include <iostream>
using namespace std;

int main() {

	int space[3];  // Indices of the spaces separating each word

	// Read in 4 words separated by a space
	string word, str;
	for (int i = 0; i < 4; i++) {
		cin >> word;
		str += word;
		if (i < 3) {
			str += ' ';
		}
	}

	// Replace the spaces with an asterisk
	for (int i = 0, j = 0; str[i] != '\0'; i++) {
		if (str[i] == ' ') {
			str[i] = '*';
			space[j++] = i;
		}
	}
	cout << str << endl;  // Print the string

	// Reaplace the last word with "#!!@1234"
	str.replace(space[2] + 1, str.length() - (space[2] + 1), "#!!@1234");
	cout << str << endl;  // Print the string

	// Delete first word from string
	for (int i = 0; i < 3; i++) {
		str = str.substr(space[0] + 1);
		cout << str << endl;  // Print the string
		for (int j = 0; j < 2; j++) {
			space[j] = space[j + 1] - space[0] - 1;
		}
	}

	return 0;
}

/*
========== Sample Run - start ==========

=========== Sample Run - end ===========
----------------------------------------
*/