#include "b_tree.h"
#include "date.h"
#include "loan.h"
#include <iostream>
using namespace std;

int main() {
	try {
		b_tree<loan, 5> loans;

		cout << "Choose one of the following" << endl;
		cout << "1: add a new lending" << endl;
		cout << "2: return an item" << endl;
		cout << "3: print all lendings " << endl;
		cout << "4: print all lendings of a date " << endl;
		cout << "5: exit:" << endl;
		cout << "6: print all loans to the same person" << endl;

		char c = '\0';
		while (c != '5') {
			cin >> c;
			if (c == '1') {
				cout << "Enter lending data" << endl;
				loan l;
				try {
					cin >> l;
					loans.insert(l);
				} catch (string e) {
					cout << e << endl;
				}
			} else if (c == '2') {
				cout << "Enter lending data" << endl;
				loan l;
				try {
					cin >> l;
					loans.remove(l);
				} catch (string e) {
					cout << e << endl;
				}
			} else if (c == '3') {
				loans.print();
			} else if (c == '4') {
				cout << "Enter the required date" << endl;
				date d;
				try {
					cin >> d;
					loan min(0, "", d, 0);
					loan max(0, "", d + 1, 0);
					loans.print_between(min, max);
				} catch (string e) {
					cout << e << endl;
				}
			} else if (c == '5') {
				cout << "bye ";
			} else if (c == '6') {
				cout << "Enter the name of the borrower" << endl;
				string name;
				cin >> name;
				loans.for_each([&](loan& l) {
					if (l.name() == name) {
						cout << l << endl;
					}
				});
			} else {
				cout << "error" << endl;
			}
		}
	} catch (string e) {
		cout << e << endl;
	}

	return 0;
}
