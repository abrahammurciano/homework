#ifndef date_h
#define date_h

#include <iostream>

class date {
  private:
	// Number of days since 1970-01-01
	int d;
	static const short cumulative_days[12];
	// Given a year, returns the number of days since 1970-01-01 until [year]-01-01
	static int year_to_days(short year);
	// Given a month, returns the number of days since YYYY-01-01 until YYYY-[month]-01, depending on if it's a leap year
	static short month_to_days(short month, bool leap_year = false);
	// Given the number of days since YYYY-01-01, returns the current month depending on if it's a leap year
	static short days_to_month(short days, short min = 0, short max = 12);

  public:
	date();
	date(short day, short month, short year);
	date(int days);

	short day() const;
	short month() const;
	short year() const;

	bool operator==(const date& d) const;
	bool operator!=(const date& d) const;
	bool operator<(const date& d) const;
	bool operator<=(const date& d) const;
	bool operator>(const date& d) const;
	bool operator>=(const date& d) const;
	date operator+(int days) const;
	date operator-(int days) const;
	date& operator+=(int days);
	date& operator-=(int days);
	date& operator++();
	date operator++(int);
	date& operator--();
	date operator--(int);

	static short days_in_month(short month);
	static bool leap_year(short year);
};

// Output the date in format YYYY-MM-DD
std::ostream& operator<<(std::ostream& out, const date& d);
// Input a date in format YYYY-MM-DD
std::istream& operator>>(std::istream& in, date& d);

#endif