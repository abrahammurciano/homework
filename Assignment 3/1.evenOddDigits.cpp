/*
 * File Name:				1.evenOddDigits.cpp
 * Program Description:		Takes an integer between 0 and 99 and tells you if the digits are all even, all odd or a mixture of the two
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		3
 * Question Number:			1
 * Author:					Abraham Murciano
 * 
 * Created on:				Sun Oct 21 2018
 * Last Modified on:		Sun Oct 21 2018
 */

#include <iostream>
using namespace std;

int main() {
	
	cout << "enter a number:" << endl;
	int n;
	cin >> n;
	
	if (n >= 100 || n <=0) {
		cout << "ERROR" << endl;
	} else {
		int digit1 = n/10;
		int digit2 = n%10;
		
		if (digit1 % 2 == 0 && digit2 % 2 == 0) {
			cout << "even digits only" << endl;
			cout << digit1 * digit2 << endl;
		} else if (digit1 % 2 == 1 && digit2 % 2 == 1) {
			cout << "odd digits only" << endl;
			cout << digit1 + digit2 << endl;
		} else {
			cout << "mixed number" << endl;
		}
	}

	return 0;
}

/*
Output
*/