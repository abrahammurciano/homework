/*
 * File Name:				2.perfectNumbers.cpp
 * Program Description:		Prints all perfect numbers less than given number, then perfect numbers
 * less than 500
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		5
 * Question Number:			2
 * Author:					Abraham Murciano
 *
 * Created on:				Mon Nov 05 2018
 * Last Modified on:		Wed Nov 07 2018
 */

#include <climits>  // Necessary to detect integer overflow
#include <cmath>	// Necessary for the pow function
#include <iostream>
using namespace std;

long long input(long long = LLONG_MIN, long long = LLONG_MAX);
bool isPrime(long long);
bool perfect(long long);
void printPerfect(long long = 500);

int main() {

	cout << "enter a number:" << endl;  // Prompt the user for input
	long long n = input(1);				// Variable to store the user input

	printPerfect(n);
	printPerfect();

	return 0;
}

// Function that takes an input between min and max inclusive, then returns the input.
// Outputs ERROR whenever input is invalid
long long input(long long min, long long max) {
	long long input;
	while (true) {
		cin >> input;
		if (input >= min && input <= max) {
			return input;
		}
		cout << "ERROR" << endl;
	}
}

// Function that checks if a number n is prime
bool isPrime(long long n) {

	// If n is 1 (or less), or even (except for 2), n is not prime
	if ((n < 2 || n % 2 == 0) && n != 2) {
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
	for (long long i = 3; i * i <= n; i += 2) {
		// If a factor is found, n isn't prime
		if (n % i == 0) {
			return false;
		}
	}

	return true;  // If no factors were found, n is prime
}

// Any number in the form 2^n-1 is called a Mersenne number.
// Any Mersenne number which is also prime is called a Mersenne prime.
// All Mersenne primes are of the form 2^p-1 where p is prime
// All Mersenne primes multiplied by two to the previous power give a perfect number, and all
// perfect numbers are of this form.
// Meaning, that for every Mersenne prime, there is a corresponding perfect number and for every
// perfect number there is a corresponding Mersenne prime.
//
// Therefore:
// ** For all prime number p where 2^p-1 is also prime, (2^(p-1))(2^p-1) is a perfect number, and
// ** all perfect numbers are of this form.

// Variable to store the highest calculated prime number that gives a perfect number
int highestPrime = 2;

// Function that checks if a number is perfect
bool perfect(long long n) {

	// Calculate the highest perfect number known by the program (derived from highestPrime)
	long long highestPerfect = pow(2, highestPrime - 1) * (pow(2, highestPrime) - 1);

	// p will be an iterator to check if any prime number generates a perfect number equal to n.
	// If the number to check (n) is bigger than the highest known perfect number, possible values
	// of p can be checked starting from the next number after the highest known prime that
	// generates a perfect number, else start at 2 (the lowest prime)
	int p = (n > highestPerfect) ? highestPrime + 1 : 2;

	// Loop to iterate through values for p to check if each value of p generates a perfect number
	// equal to n
	while (true) {

		// Only check (2^(p-1))(2^p-1) if p is prime.
		// If it isn't, the generated number is not perfect.
		if (isPrime(p)) {

			// Get the Mersenne number generated from current p
			long long mersenne = pow(2, p) - 1;

			// If the next number generated from p exceeds n, n lies between two consecutive perfect
			// numbers, therefore is not perfect itself
			if (pow(2, p - 1) * mersenne > n) {
				return false;
			}

			// If the Mersenne nubmer generated from p is prime, then (2^(p-1))(2^p-1) is the next
			// perfect number
			if (isPrime(mersenne)) {

				// Update highestPrime to the current p, since we know we can generate a perfect
				// number from p
				highestPrime = p;

				// If the perfect number that was found equals n, n is a perfect number
				if (n == pow(2, p - 1) * mersenne) {
					return true;
				}
			}
		}

		// Increment p to next odd number. (because p must be prime & all primes after 2 are odd)
		// If p == 2, (p + 1) % 2 evaluates 1, so p will be incremented by 2-1, which is 1.
		// Otherwise, p will be incremented by 2-0, which is 2.
		p += (2 - ((p + 1) % 2));
	}
}

// Function that prints all the perfect numbers less than max
void printPerfect(long long max) {

	// If max is less than or equal to 6, skip to the end
	if (max > 6) {

		// All perfect numbers (except 6) are a sum of an even number of consecutive odd cubes
		// beginning at 1^3
		// For example, 496 = 1^3 + 3^3 + 5^3 + 7^3
		// Since 6 isn't a sum of odd cubes, output the first perfect nubmer, 6.
		cout << 6;

		// Set sum of odd cubes to 1^3 + 3^3
		long long sumOddCubes = pow(1, 3) + pow(3, 3);

		// Loop through all odd numbers starting from 3, and add its cube to sumOddCubes
		for (long long i = 5; sumOddCubes < max; i += 2) {

			// All perfect numbers must end in either 6 or 8, so only check if sumOddCubes is
			// perfect when it ends in 6 or 8
			if (sumOddCubes % 10 == 6 || sumOddCubes % 10 == 8) {
				if (perfect(sumOddCubes)) {
					// Output the next perfect number
					cout << ' ' << sumOddCubes;
				}
			}

			// Detect integer overflow
			if (sumOddCubes > LLONG_MAX - (i * i * i)) {
				break;
			}

			// Update sumOddCubes to the sum up to the next 2 odd cubes
			sumOddCubes += i * i * i;
			i += 2;
			sumOddCubes += i * i * i;
		}
	}
	cout << endl;
}

/*
enter a number:
9223372036854775807
6 28 496 8128 33550336 8589869056 137438691328 2305843008139952128
6 28 496
*/

/*
 * Note, in the test run above it took only 0.025s to find all the perfect numbers long long can
 * handle before getting an integer overflow
 */