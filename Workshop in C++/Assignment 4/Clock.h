/*
 * File Name:				Clock.h
 * Program Description:		Program for an ATM machine
 * Course Name:				Workshop in C++
 * Assignment Number:		4
 * Author:					Abraham Murciano
 */

#ifndef clock_h
#define clock_h

#include <iostream>
using namespace std;

class Clock {
	friend ostream& operator<<(ostream& out, const Clock& c);
	friend istream& operator>>(istream& in, Clock& c);

  private:
	int h;
	int m;
	int s;

  public:
	Clock();
	Clock(int h, int m, int s = 0);
	Clock(const Clock& c);

	void setTime(int h, int m, int s);
	void setHour(int h);
	void setMinute(int m);
	void setSecond(int s);

	int getHour();
	int getMinute();
	int getSecond();

	Clock& operator+=(int s);
	Clock operator++();
	Clock& operator++(int);
};

#endif
