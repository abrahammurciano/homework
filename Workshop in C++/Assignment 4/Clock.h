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

	void setTime(int h, int m, int s, bool valid);
	void setHour(int h, bool valid);
	void setMinute(int m, bool valid);
	void setSecond(int s, bool valid);

  public:
	Clock();
	Clock(int h, int m, int s = 0);
	Clock(const Clock& c);

	int getHour();
	int getMinute();
	int getSecond();

	void setTime(int h, int m, int s);
	void setHour(int h);
	void setMinute(int m);
	void setSecond(int s);

	void addHour(int h);
	void addMinute(int m);
	void addSecond(int s);

	Clock operator+(int s) const;
	Clock operator-(int s) const;

	Clock& operator+=(int s);
	Clock operator++(int);
	Clock& operator++();

	Clock& operator-=(int s);
	Clock operator--(int);
	Clock& operator--();
};

#endif
