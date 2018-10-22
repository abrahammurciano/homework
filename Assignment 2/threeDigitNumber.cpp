
/*
 * File Name:				threeDigitNumber.cpp
 * Program Description:		Given a three-digit positive number, this program prints the sum of its digits.
 * Course Name:				Introduction to Computer Science
 * Exercise Number:			2
 * Question Number:			7
 * Author:					Abraham Murciano
 * 
 * Created on:				Oct 14, 2018, 10:05:41 PM
 * Last Modified:			Oct 14, 2018, 11:01:16 PM
 */

//#include <cstdlib>
//#include <cstring>
#include <iostream>
#include <math.h>
using namespace std;

//Function to return the digit at the given position of the given number.
//Here, position refers to the position from the right, starting from 0.
int getDigit (int number, int position);

int main () {

	int n; //Three digit number to be input;
	cout << "enter a three digit number:" << endl;
	cin >> n;

	int digit1 = getDigit(n, 2);
	int digit2 = getDigit(n, 1);
	int digit3 = getDigit(n, 0);

	cout << "The sum is: " << digit1 + digit2 + digit3;

	return 0;
}

int getDigit (int number, int position) {
	int digit = (number % (int) pow(10, position + 1)) / pow(10, position);
	return digit;
}

/*
enter a three digit number:
715
The sum is: 13
 */