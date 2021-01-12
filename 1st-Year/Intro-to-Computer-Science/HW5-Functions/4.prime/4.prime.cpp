/*
 * File Name:				4.prime.cpp
 * Program Description:		Takes a number and outputs the next prime number
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		5
 * Question Number:			4
 * Author:					Abraham Murciano
 *
 * Created on:				Tue Nov 06 2018
 * Last Modified on:		Wed Nov 07 2018
 */

#include <cstdlib>
#include <iostream>
using namespace std;

bool isPrime(int);
int findPrime(int);

int main() {

	cout << "enter number of values:" << endl;  // Prompt for input
	int n;										// Variable to store input
	cin >> n;									// Read in a value to n

	// If n is negative, assign n a random value between 10 and 100
	if (n < 0) {
		srand(time(NULL));  // Seed
		n = rand() % 91 + 10;
	}
	cout << "table size: " << findPrime(n) << endl;

	return 0;
}

// Function that checks if a number n is prime
bool isPrime(int n) {

	// If n is 1 (or less), or n (past 3) is not a multiple of 6 +/- 1
	// All prime numbers after 3 are one away from a multiple of 6
	if (n < 2 || (n > 3 && n % 6 != 1 && n % 6 != 5)) {
		return false;
	}

	// Iterate through numbers to check if a factor of n is found.
	//
	// Since this only executes if n is odd, and all non-prime odd numbers have at least one odd
	// factor, Only odd numbers need to be checked if they are a factor.
	//
	// Since for every factor and cofactor of a number n, one of the factor or cofactor must be less
	// than or equal to the square root of the number n, and the other must be greater than or equal
	// to n, only numbers up until the square root of n must be checked if they are a factor.
	for (int i = 3; i * i <= n; i += 2) {
		// If a factor is found, n isn't prime
		if (n % i == 0) {
			return false;
		}
	}

	return true;  // If no factors were found, n is prime
}

// Function that finds the closest prime nubmer after n
int findPrime(int n) {

	if (n < 2) {
		return 2;
	}

	if (n == 2) {
		return 3;
	}

	// set n to the next multiple of 6
	n = (n / 6 + 1) * 6;

	// Loop through all odd numbers (or 2) after n until one is prime
	while (true) {
		if (isPrime(n - 1)) {
			return n - 1;
		}
		if (isPrime(n + 1)) {
			return n + 1;
		}

		n += 6;
	}
}

/*
enter number of values:
32
table size: 37
*/