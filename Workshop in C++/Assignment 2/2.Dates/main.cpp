/*
 * File Name:				main.cpp
 * Program Description:		----
 * Course Name:				Workshop in C++
 * Assignment Number:		2
 * Question Number:			2
 * Author:					Abraham Murciano
 */

#include "Date.h"
#include <iostream>
using namespace std;

void enterDate(int& d, int& m, int& y) {
	cout << "Enter a date" << endl;
	cin >> d;
	cin.ignore(1, '/');
	cin >> m;
	cin.ignore(1, '/');
	cin >> y;
}

int main() {
	cout << boolalpha;
	int d, m, y;
	enterDate(d, m, y);
	Date date(d, m, y), newDate;
	date.print();

	while (true) {
		cout << "What do you want to do" << endl;
		int code;
		cin >> code;
		if (code < 0) {
			break;
		}

		if (code == 1) {
			enterDate(d, m, y);
			date.setDate(d, m, y).print();
		} else if (code == 2) {
			(++date).print();
		} else if (code == 3) {
			(date++).print();
		} else if (code == 4) {
			cout << "Enter #days" << endl;
			int n;
			cin >> n;
			(date += n).print();
		} else if (code == 5) {
			enterDate(d, m, y);
			newDate = Date(d, m, y);
			cout << ">: " << (date > newDate) << endl;
		} else if (code == 6) {
			enterDate(d, m, y);
			newDate = Date(d, m, y);
			cout << "<: " << (date < newDate) << endl;
		} else if (code == 7) {
			enterDate(d, m, y);
			newDate = Date(d, m, y);
			cout << "==: " << (date == newDate) << endl;
		}
	}

	return 0;
}

/*
========== Sample Run - start ==========

=========== Sample Run - end ===========
----------------------------------------
*/