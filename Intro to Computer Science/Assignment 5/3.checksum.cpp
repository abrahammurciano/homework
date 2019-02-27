/*
 * File Name:				3.checksum.cpp
 * Program Description:		Computes the checksum of a social security nubmer
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		5
 * Question Number:			3
 * Author:					Abraham Murciano
 *
 * Created on:				Tue Nov 06 2018
 * Last Modified on:		Wed Nov 07 2018
 */

#include <climits>  // Used to set defaults to the input function
#include <iostream>
using namespace std;

int input(int = INT_MIN, int = INT_MAX);
int sumDigits(int);
int checksum(int);

int main() {

	cout << "enter your ID:" << endl;  // Prompt user for a social security number

	int social = input(10000000, 99999999);  // Variable to store user input

	// Output the full ID number
	cout << "your full ID is:" << endl;
	cout << social << checksum(social) << endl;

	return 0;
}

// Function that takes an input between min and max inclusive, then returns the input.
// Outputs ERROR whenever input is invalid
int input(int min, int max) {
	int input;
	while (true) {
		cin >> input;
		if (input >= min && input <= max) {
			return input;
		}
		cout << "ERROR" << endl;
	}
}

// Function that sums all the digits of parameter n
int sumDigits(int n) {
	int sum = 0;  // Declare sum and initialise it to 0

	// Add the last digit of n to sum, then remove the last digit from n. Repeat until first digit
	// has been added
	do {
		sum += n % 10;
	} while (n /= 10);

	return sum * ((sum > 0) - (sum < 0));  // Takes into account negative numbers
}

// Function that returns the checksum of 8 digit number n. If 8 digits are not provided, return -1
int checksum(int n) {
	int sum = 0;	 // Declare sum and initialise it to 0
	int weight = 2;  // Starts with weight as 2, it will be toggled between 1 and 2 for each digit

	// Loop to go through each digit of n
	do {
		int digit = n % 10;				   // Get the last digit of n
		sum += sumDigits(digit * weight);  // Add the weighted digits to the sum
		weight = 1 + (weight == 1);		   // Toggle weight between 1 and 2
	} while (n /= 10);

	int sumLastDigit = sum % 10;	   // Get the last digit of the sum of the weighted digits
	int checksum = 10 - sumLastDigit;  // Calculate checksum
	checksum %= 10;					   // In case sumLastDigit is 0

	return checksum;
}

/*
enter your ID:
12345678
your full ID is:
123456782
*/