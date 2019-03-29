/*
 * File Name:				Clock.cpp
 * Program Description:		Program for an ATM machine
 * Course Name:				Workshop in C++
 * Assignment Number:		4
 * Author:					Abraham Murciano
 */

#include "Clock.h"
#include "iostream"
using namespace std;

Clock::Clock() : Clock(0, 0, 0) {}

Clock::Clock(int h, int m, int s) {
	try {
		setTime(h, m, s);
	} catch (char* e) {
		setTime(0, 0, 0);
		throw e;
	}
}

Clock::Clock(const Clock& c) {
	h = c.h;
	m = c.m;
	s = c.s;
}

void Clock::setTime(int h, int m, int s) {
	setHour(h);
	setMinute(m);
	setSecond(s);
}

void Clock::setHour(int h) {
	if (h < 0) {
		throw "Invalid time – negative number of hours.";
	}
	if (h > 23) {
		throw "Invalid time – more than 24 hours.";
	}
	this->h = h;
}

void Clock::setMinute(int m) {
	if (m < 0) {
		throw "Invalid time – negative number of minutes.";
	}
	if (m > 59) {
		throw "Invalid time – more than 60 minutes.";
	}
	this->m = m;
}

void Clock::setSecond(int s) {
	if (s < 0) {
		throw "Invalid time – negative number of seconds.";
	}
	if (s > 59) {
		throw "Invalid time – more than 60 seconds.";
	}
	this->s = s;
}

int Clock::getHour() {
	return h;
}

int Clock::getMinute() {
	return m;
}

int Clock::getSecond() {
	return s;
}

Clock& Clock::operator+=(int s) {
	setSecond((this->s + s) % 60);
	setMinute(((this->s + s) / 60) % 60);
	setHour((((this->s + s) / 60) / 60) % 24);
	return *this;
}

Clock Clock::operator++() {
	Clock temp = *this;
	(*this) += 1;
	return temp;
}

Clock& Clock::operator++(int) {
	return (*this) += 1;
}

ostream& operator<<(ostream& out, const Clock& c) {
	return out << c.h << ':' << c.m << ':' << c.s;
}

istream& operator>>(istream& in, Clock& c) {
	char colon;
	int num;

	in >> num;
	c.setHour(num);

	in >> colon;
	if (colon != ':') {
		throw "Wrong time format.";
	}

	in >> num;
	c.setMinute(num);

	in >> colon;
	if (colon != ':') {
		throw "Wrong time format.";
	}

	in >> num;
	c.setSecond(num);

	return in;
}