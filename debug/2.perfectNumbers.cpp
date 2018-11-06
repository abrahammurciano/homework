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
 * Last Modified on:		Mon Nov 05 2018
 */

#include <cmath>
#include <iostream>
using namespace std;

bool isPrime(long long);
bool perfect(long long);
void printPerfect(long long = 500);

int highestPrime = 2;

int main() {

	cout << "enter a number:" << endl;
	long long n;
	cin >> n;
	printPerfect(n);
	printPerfect();

	return 0;
}

bool isPrime(long long n) {
	if ((n < 2 || n % 2 == 0) && n != 2) {
		return false;
	}

	for (long long i = 3; i * i <= n; i += 2) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}

bool perfect(long long n) {
	long long highestN = pow(2, highestPrime - 1) * (pow(2, highestPrime) - 1);
	long long p = (n >= highestN) ? highestPrime : 0;
	for (long long p = 0; p * p <= n; p++) {
		highestPrime = p;
		if (isPrime(p)) {
			long long mp = pow(2, p) - 1;
			if (isPrime(mp) && n == pow(2, p - 1) * mp) {
				return true;
			}
		}
	}

	return false;
}

void printPerfect(long long max) {
	for (int i = 0; i < max; i += 2) {
		if (perfect(i)) {
			cout << i << endl;
		}
	}
}

/*
Output
*/