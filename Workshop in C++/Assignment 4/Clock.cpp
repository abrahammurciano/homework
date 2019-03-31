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

// Default Constructor
Clock::Clock() : Clock(0, 0, 0) {}

// Constructor
Clock::Clock(int h, int m, int s) {
	try {
		setTime(h, m, s);
	} catch (string e) {
		setTime(0, 0, 0);
		throw e;
	}
}

// Copy constructor
Clock::Clock(const Clock& c) {
	h = c.h;
	m = c.m;
	s = c.s;
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

// Takes an hour, minute and second, then sets the time
void Clock::setTime(int h, int m, int s, bool valid) {
	setHour(h, valid);
	setMinute(m, valid);
	setSecond(s, valid);
}

void Clock::setHour(int h, bool valid) {
	if (valid) {
		setHour(h);
	} else {
		this->h = (h >= 0 ? h : 24 + h % 24) % 24;
	}
}

void Clock::setMinute(int m, bool valid) {
	if (valid) {
		setMinute(m);
	} else {
		this->m = (m >= 0 ? m : 60 + m % 60) % 60;
	}
}

void Clock::setTime(int h, int m, int s) {
	setTime(h, m, s, true);
}

void Clock::setSecond(int s, bool valid) {
	if (valid) {
		setSecond(s);
	} else {
		this->s = (s >= 0 ? s : 60 + s % 60) % 60;
	}
}

void Clock::setHour(int h) {
	if (h < 0) {
		throw string("Invalid time – negative number of hours.");
	}
	if (h > 23) {
		throw string("Invalid time – more than 24 hours.");
	}
	this->h = h;
}

void Clock::setMinute(int m) {
	if (m < 0) {
		throw string("Invalid time – negative number of minutes.");
	}
	if (m > 59) {
		throw string("Invalid time – more than 60 minutes.");
	}
	this->m = m;
}

void Clock::setSecond(int s) {
	if (s < 0) {
		throw string("Invalid time – negative number of seconds.");
	}
	if (s > 59) {
		throw string("Invalid time – more than 60 seconds.");
	}
	this->s = s;
}

void Clock::addHour(int h) {
	setHour(this->h + h, false);
}

void Clock::addMinute(int m) {
	int oldM = this->m;
	setMinute(oldM + m, false);
	addHour((oldM + m) / 60 - (oldM < -m));
}

void Clock::addSecond(int s) {
	int oldS = this->s;
	setSecond(oldS + s, false);
	addMinute((oldS + s) / 60 - (oldS < -s));
}

// Add a time and a number of seconds
Clock Clock::operator+(int s) const {
	Clock t = *this;
	t.addSecond(s);
	return t;
}

// Subtract a number of seconds from a time
Clock Clock::operator-(int s) const {
	return *this + -s;
}

// Add s seconds to the time
Clock& Clock::operator+=(int s) {
	return *this = *this + s;
}

// Add 1 second to the time
Clock Clock::operator++(int) {
	Clock temp = *this;
	(*this) += 1;
	return temp;
}

// Add 1 second to the time
Clock& Clock::operator++() {
	return (*this) += 1;
}

// Subtract s seconds from the time
Clock& Clock::operator-=(int s) {
	return *this = *this - s;
}

// Subtract 1 second from the time
Clock Clock::operator--(int) {
	Clock temp = *this;
	(*this) -= 1;
	return temp;
}

// Subtract 1 second from the time
Clock& Clock::operator--() {
	return (*this) -= 1;
}

ostream& operator<<(ostream& out, const Clock& c) {
	return out << (c.h < 10 ? "0" : "") << c.h << ':' << (c.m < 10 ? "0" : "") << c.m << ':'
			   << (c.s < 10 ? "0" : "") << c.s;
}

istream& operator>>(istream& in, Clock& c) {
	char colon;
	int num;

	in >> num;
	c.setHour(num);

	in >> colon;
	if (colon != ':') {
		throw string("Wrong time format.");
	}

	in >> num;
	c.setMinute(num);

	in >> colon;
	if (colon != ':') {
		throw string("Wrong time format.");
	}

	in >> num;
	c.setSecond(num);

	return in;
}