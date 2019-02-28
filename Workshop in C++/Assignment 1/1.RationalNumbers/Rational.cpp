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

Rational::Rational(int n, int d) {
	numerator = n;
	denominator = d ? d : 1;
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

void Rational::print() {
	cout << numerator << '/' << denominator;
}

bool Rational::equal(Rational n) {
	Rational reduced = reduce();
	return reduced.getNumerator() == n.reduce().getNumerator() &&
		   reduced.getDenominator() == n.reduce().getDenominator();
}

int Rational::hcf(int n, int d) {
	return d ? hcf(d, n % d) : n;
}

Rational Rational::reduce() {
	int highestCommonFactor = hcf(numerator, denominator);
	Rational reduced(numerator / highestCommonFactor, denominator / highestCommonFactor);
	return reduced;
}

#endif
