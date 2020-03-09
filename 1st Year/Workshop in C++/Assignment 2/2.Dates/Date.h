/*
 * File Name:				Date.h
 * Program Description:		----
 * Course Name:				Workshop in C++
 * Assignment Number:		#
 * Question Number:			#
 * Author:					Abraham Murciano
 */

#ifndef Date_h
#define Date_h

class Date {
  private:
	int day;
	int month;
	int year;

  public:
	Date(int day = 1, int month = 1, int year = 1970);
	Date(const Date& date);

	Date setDate(int day, int month, int year);
	void print(bool newLine = true);

	Date operator+(const int& d) const;
	Date operator-(const int& d) const;

	Date operator++(int);
	Date operator++();
	Date operator--(int);
	Date operator--();

	Date operator+=(const int& d);
	Date operator-=(const int& d);

	bool operator==(const Date& date);
	bool operator!=(const Date& date);
	bool operator>(const Date& date);
	bool operator<(const Date& date);
};

#endif
