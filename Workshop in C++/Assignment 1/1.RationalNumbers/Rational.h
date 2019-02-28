/*
 * File Name:				Rational.h
 * Program Description:		Compares two rational numbers
 * Course Name:				Workshop in C++
 * Assignment Number:		1
 * Question Number:			1
 * Author:					Abraham Murciano
 */

#ifndef Rational_h
#define Rational_h

class Rational {
  private:
	int numerator;
	int denominator;
	int hcf(int n, int d);
	Rational reduce();

  public:
	Rational(int num, int denom);
	int getNumerator();
	int getDenominator();
	void setNumerator(int n);
	void setDenominator(int d);
	void print();
	bool equal(Rational n);
};

#endif
