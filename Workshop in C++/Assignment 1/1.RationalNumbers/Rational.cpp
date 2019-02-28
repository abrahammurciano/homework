/*
 * File Name:				Rational.cpp
 * Program Description:		Compares two rational numbers
 * Course Name:				Workshop in C++
 * Assignment Number:		1
 * Question Number:			1
 * Author:					Abraham Murciano
 */

#ifndef Rational_cpp
#define Rational_cpp

#include "Rational.h"
#include <iostream>
using namespace std;

// Constructor
Rational::Rational(int n, int d) {
	numerator = n;
	denominator = d ? d : 1;  // If input was 0, make denominator 1
}

int Rational::getNumerator() {
	return numerator;
}

int Rational::getDenominator() {
	return denominator;
}

void Rational::setNumerator(int n) {
	numerator = n;
}

void Rational::setDenominator(int d) {
	denominator = d;
}

// Print the rational number in the form a/b
void Rational::print() {
	cout << numerator << '/' << denominator;
}

// Compare self to another rational number n
bool Rational::equal(Rational n) {
	// Reduce self to simplest form then compare to n reduced
	Rational reduced = reduce();
	return reduced.getNumerator() == n.reduce().getNumerator() &&
		   reduced.getDenominator() == n.reduce().getDenominator();
}

// Calculate Highest Common Factor using Euclid's recursive algorithm
int Rational::hcf(int n, int d) {
	return d ? hcf(d, n % d) : n;
}

// Reduce the fraction to its simplest form
Rational Rational::reduce() {
	int highestCommonFactor = hcf(numerator, denominator);  // Calculate Highest Common Factor

	// Create rational number reduced with numerator and denominator of self divided by hcf
	Rational reduced(numerator / highestCommonFactor, denominator / highestCommonFactor);
	return reduced;
}

#endif
