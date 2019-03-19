/*
 * File Name:				Rnl.cpp
 * Program Description:		An implementation of a class for rational numbers with operators
 * Course Name:				Workshop in C++
 * Assignment Number:		2
 * Question Number:			1
 * Author:					Abraham Murciano
 */

#include "Rnl.h"
#include <iostream>
using namespace std;

Rnl::Rnl(int n, int d) {
	this->n = n;
	this->d = d ? d : 1;
	*this = simplify();
}

Rnl::Rnl(const Rnl& r) {
	n = r.n;
	d = r.d;
}

// Calculate Highest Common Factor using Euclid's recursive algorithm
int Rnl::hcf(int n, int d) const {
	return d ? hcf(d, n % d) : n;
}

// simplify the fraction to its simplest form
Rnl& Rnl::simplify() {
	int hcf = this->hcf(n, d);  // Calculate Highest Common Factor

	// Divide numerator and denominator by HCF and return result
	n /= hcf;
	d /= hcf;
	return *this;
}

void Rnl::print() const {
	cout << n;
	if (d != 1 && n != 0) {
		cout << '/' << d;
	}
}

// Relational operators
bool Rnl::operator==(const Rnl& r) const {
	return n == r.n && d == r.d;
}

bool Rnl::operator!=(const Rnl& r) const {
	return !(*this == r);
}

bool Rnl::operator<(const Rnl& r) const {
	return ((d * r.d > 0) && (n * r.d < r.n * d)) || ((d * r.d < 0) && (n * r.d > r.n * d));
}

bool Rnl::operator>(const Rnl& r) const {
	return ((d * r.d > 0) && (n * r.d > r.n * d)) || ((d * r.d < 0) && (n * r.d < r.n * d));
}

bool Rnl::operator<=(const Rnl& r) const {
	return !(*this > r);
}

bool Rnl::operator>=(const Rnl& r) const {
	return !(*this < r);
}

// Arithmetic operators
Rnl Rnl::operator+(const Rnl& r) const {
	return Rnl(n * r.d + r.n * d, d * r.d).simplify();
}

Rnl Rnl::operator-(const Rnl& r) const {
	return Rnl(n * r.d - r.n * d, d * r.d).simplify();
}

Rnl Rnl::operator*(const Rnl& r) const {
	return Rnl(n * r.n, d * r.d).simplify();
}

Rnl Rnl::operator/(const Rnl& r) const {
	return Rnl(n * r.d, d * r.n).simplify();
}

// Assignment operators
Rnl& Rnl::operator+=(const Rnl& r) {
	return *this = *this + r;
}

Rnl& Rnl::operator-=(const Rnl& r) {
	return *this = *this - r;
}

Rnl& Rnl::operator*=(const Rnl& r) {
	return *this = *this * r;
}

Rnl& Rnl::operator/=(const Rnl& r) {
	return *this = *this / r;
}

// Increment operators
Rnl& Rnl::operator++() {
	n += d;
	return *this;
}

Rnl Rnl::operator++(int) {
	Rnl tmp = *this;
	n += d;
	return tmp;
}

// Decrement operators
Rnl& Rnl::operator--() {
	n -= d;
	return *this;
}

Rnl Rnl::operator--(int) {
	Rnl tmp = *this;
	n -= d;
	return tmp;
}