/*
 * File Name:				Rnl.h
 * Program Description:		An implementation of a class for rational numbers with operators
 * Course Name:				Workshop in C++
 * Assignment Number:		2
 * Question Number:			1
 * Author:					Abraham Murciano
 */

#ifndef Rnl_h
#define Rnl_h

class Rnl {
  private:
	int n;
	int d;

  public:
	Rnl(int n = 0, int d = 1);
	Rnl(const Rnl& r);
	void print() const;
	int hcf(int n, int d) const;
	Rnl simplify() const;

	// Relational operators
	bool operator==(const Rnl& r) const;
	bool operator!=(const Rnl& r) const;
	bool operator<(const Rnl& r) const;
	bool operator>(const Rnl& r) const;
	bool operator<=(const Rnl& r) const;
	bool operator>=(const Rnl& r) const;

	// Arithmetic operators
	Rnl operator+(const Rnl& r) const;
	Rnl operator-(const Rnl& r) const;
	Rnl operator*(const Rnl& r) const;
	Rnl operator/(const Rnl& r) const;

	// Assignment operators
	Rnl operator+=(const Rnl& r);
	Rnl operator-=(const Rnl& r);
	Rnl operator*=(const Rnl& r);
	Rnl operator/=(const Rnl& r);

	// Increment operators
	Rnl operator++();
	Rnl operator++(int);

	// Decrement operators
	Rnl operator--();
	Rnl operator--(int);
};

#endif
