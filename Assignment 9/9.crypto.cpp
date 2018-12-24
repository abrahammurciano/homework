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

void crypto(char str[]) {
	for (int i = 0; str[i] != '\0'; i++) {
		if ('a' <= str[i] && str[i] <= 'z') {
			str[i] = 'a' + 'z' - str[i];
		}
	}
}

int main() {

	char str[81];
	cout << "enter a string: ";
	cin >> str;

	crypto(str);

	cout << "after crypto:" << endl;
	cout << str << endl;

	return 0;
}

/*
========== Sample Run - start ==========

=========== Sample Run - end ===========
----------------------------------------
*/