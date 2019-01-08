/*
 * File Name:				1.ab.cpp
 * Program Description:		Inputs a number and prints that many 'a's followed by that many 'b's
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		11
 * Question Number:			1
 * Author:					Abraham Murciano
 *
 * Created on:				Mon Jan 07 2019
 * Last Modified on:		Mon Jan 07 2019
 */

#include <iostream>
using namespace std;

// Function that prints n 'a's and n 'b's
void printABs(int n) {
	if (n) {  // When n is 0, do nothing
		cout << 'a';
		printABs(n - 1);
		cout << 'b';
	}
}

int main() {
	int num;
	cout << "enter a number:" << endl;
	cin >> num;
	printABs(num);
	cout << endl;
	return 0;
}

/*
========== Sample Run - start ==========
enter a number:
1
ab
=========== Sample Run - end ===========
----------------------------------------
========== Sample Run - start ==========
enter a number:
5
aaaaabbbbb
=========== Sample Run - end ===========
----------------------------------------
========== Sample Run - start ==========
enter a number:
0

=========== Sample Run - end ===========
----------------------------------------
*/