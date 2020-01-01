#include "date.h"
using namespace std;

const short date::cumulative_days[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

int date::year_to_days(short year) {
	short years = year - 1970;
	return years * 365 + (years + 1) / 4 - (years + 69) / 100 + (years + 369) / 400;
}

short date::month_to_days(short month, bool leap_year) {
	return cumulative_days[month - 1] + (leap_year && month > 2);
}

short date::days_to_month(short days, short min, short max) {
	if (min == max) {
		return min;
	}
	int mid = (min + max) / 2;
	if (days < cumulative_days[mid]) {
		return days_to_month(days, min, mid);
	} else {
		return days_to_month(days, mid + 1, max);
	}
}

date::date()
	: d(0) {}

date::date(short day, short month, short year) {
	if (day < 1 || month < 1 || year < 1970 || month > 12 || (day > days_in_month(month) && (day != 29 || !leap_year(year)))) {
		throw string("Error: Could not construct invalid date ") + to_string(day) + '-' + to_string(month) + '-' + to_string(year) + '.';
	}
	d = year_to_days(year);
	d += month_to_days(month, leap_year(year));
	d += day - 1;
}

date::date(int days) {
	if (days < 0) {
		throw string("Error: Cannot create a date before 1/1/1970.");
	}
	d = days;
}

short date::day() const {
	short _year = year();
	return d - year_to_days(_year) - month_to_days(month(), leap_year(_year)) + 1;
}

short date::month() const {
	short _year = year();
	short remaining_days = d - year_to_days(_year);
	if (leap_year(_year) && remaining_days >= 59) {
		--remaining_days;
	}
	return days_to_month(remaining_days);
}

short date::year() const {
	short num_4_leaps = (d + 365) / (4 * 365 + ((d + 365) % (4 * 365) != 0));
	short num_100_leaps = (d + 69 * 365 + 17) / (100 * 365 + 25);
	short num_400_leaps = (d + 369 * 365 + 89) / (400 * 365 + 100);
	return 1970 + (d - num_4_leaps + num_100_leaps - num_400_leaps) / 365;
}

bool date::operator==(const date& d) const {
	return this->d == d.d;
}

bool date::operator!=(const date& d) const {
	return !(*this == d);
}

bool date::operator<(const date& d) const {
	return this->d < d.d;
}

bool date::operator<=(const date& d) const {
	return (*this < d || *this == d);
}

bool date::operator>(const date& d) const {
	return !(*this <= d);
}

bool date::operator>=(const date& d) const {
	return !(*this < d);
}

date date::operator+(int days) const {
	return date(d + days);
}

date date::operator-(int days) const {
	return *this + (-days);
}

date& date::operator+=(int days) {
	*this = *this + days;
	return *this;
}

date& date::operator-=(int days) {
	*this = *this - days;
	return *this;
}

date& date::operator++() {
	*this += 1;
	return *this;
}

date date::operator++(int) {
	return ++*this - 1;
}

date& date::operator--() {
	*this -= 1;
	return *this;
}

date date::operator--(int) {
	return --*this + 1;
}

short date::days_in_month(short month) {
	int days = cumulative_days[month] - cumulative_days[month - 1];
	return days;
}

bool date::leap_year(short year) {
	return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}

ostream& operator<<(ostream& out, const date& d) {
	short day = d.day(), month = d.month(), year = d.year();
	return out << year << '-' << (month < 10 ? "0" : "") << month << '-' << (day < 10 ? "0" : "") << day;
}

istream& operator>>(istream& in, date& d) {
	char dash_1, dash_2;
	short day, month, year;
	if (!(in >> year >> dash_1 >> month >> dash_2 >> day) || dash_1 != '-' || dash_2 != '-') {
		cin.clear();
		throw string("Error: Expected a date in YYYY-MM-DD format.");
	}
	d = date(day, month, year);
	return in;
}
