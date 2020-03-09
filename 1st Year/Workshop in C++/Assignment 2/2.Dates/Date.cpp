/*
 * File Name:				Date.cpp
 * Program Description:		----
 * Course Name:				Workshop in C++
 * Assignment Number:		#
 * Question Number:			#
 * Author:					Abraham Murciano
 */

#include "Date.h"
#include <iostream>
using namespace std;

Date::Date(int day, int month, int year) {
	if (day >= 1 && day <= 30) {
		this->day = day;
	} else {
		cout << "ERROR day" << endl;  // Constructors should not be *printing* errors...
		this->day = 1;
	}

	if (month >= 1 && month <= 12) {
		this->month = month;
	} else {
		cout << "ERROR month" << endl;
		this->month = 1;
	}

	if (year >= 1970 && year <= 2999) {
		this->year = year;
	} else {
		cout << "ERROR year" << endl;
		this->year = 1970;
	}
}

Date::Date(const Date& date) {
	day = date.day;
	month = date.month;
	year = date.year;
}

Date Date::setDate(int day, int month, int year) {
	if ((day >= 1 && day <= 30) && (month >= 1 && month <= 12) && (year >= 1970 && year <= 2999)) {
		*this = Date(day, month, year);
	}
	return *this;
}

void Date::print(bool newLine) {
	cout << day << '/' << month << '/' << year << (newLine ? "\n" : "");
}

Date Date::operator+(const int& d) const {
	Date sum;
	int carry;
	sum.day = (day + d - 1) % 30 + 1;
	carry = (day + d - 1) / 30;
	sum.month = (month + carry - 1) % 12 + 1;
	carry = (month + carry - 1) / 12;
	sum.year = (year + carry - 1970) % (3000 - 1970) + 1970;
	return sum;
}

Date Date::operator-(const int& d) const {
	Date diff;
	int borrow;
	diff.day = (30 + (day - d - 1) % 30) % 30 + 1;
	borrow = (30 - day + d) / 30;
	diff.month = (12 + (month - borrow - 1) % 12) % 12 + 1;
	borrow = (12 - month + borrow) / 12;
	diff.year = ((3000 - 1970) + (year - borrow - 1970) % (3000 - 1970)) % (3000 - 1970) + 1970;
	return diff;
}

Date Date::operator++(int) {
	Date tmp = *this;
	*this = *this + 1;
	return tmp;
}

Date Date::operator++() {
	(*this)++;
	return *this;
}

Date Date::operator--(int) {
	Date tmp = *this;
	*this = *this - 1;
	return tmp;
}

Date Date::operator--() {
	(*this)--;
	return *this;
}

Date Date::operator+=(const int& d) {
	*this = *this + d;
	return *this;
}

Date Date::operator-=(const int& d) {
	*this = *this - d;
	return *this;
}

bool Date::operator==(const Date& date) {
	return day == date.day && month == date.month && year == date.year;
}

bool Date::operator!=(const Date& date) {
	return !(*this == date);
}

bool Date::operator>(const Date& date) {
	return (year > date.year) || ((year == date.year) && (month > date.month)) ||
		   ((year == date.year) && (month == date.month) && (day > date.day));
}

bool Date::operator<(const Date& date) {
	return *this != date && !(*this > date);
}