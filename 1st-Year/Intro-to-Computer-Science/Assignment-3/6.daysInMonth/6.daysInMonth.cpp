/*
 * File Name:				6.daysInMonth.cpp
 * Program Description:		Prints the number of days in a given month
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		3
 * Question Number:			6
 * Author:					Abraham Murciano
 *
 * Created on:				Mon Oct 22 2018
 * Last Modified on:		Mon Oct 22 2018
 */

#include <iostream>
using namespace std;

int main() {

	cout << "enter a number:" << endl;
	int monthInput;
	cin >> monthInput;

	// Input validation
	if (monthInput < 1 || monthInput > 12) {
		cout << "ERROR" << endl;
		return 0;
	}

	enum month {
		JAN = 1,
		FEB,
		MAR,
		APR,
		MAY,
		JUN,
		JUL,
		AUG,
		SEP,
		OCT,
		NOV,
		DEC
	};
	month m = (month)monthInput;
	int days;

	if (m == FEB) {
		days = 28;
	} else if (m == APR || m == JUN || m == SEP || m == NOV) {
		days = 30;
	} else {
		days = 31;
	}

	cout << days << " days in the month" << endl;

	return 0;

	/*
	This would be another way of acheiving the same. I realised the question
	said explicitly to
	use enumerations, so I commented out the answer below and replaced it with
	the one above.

	int days = 28 + (month + month/8)%2 + 2%month + 2*(1/month);
	*/
}

/*
enter a number:
2
28 days in the month
*/