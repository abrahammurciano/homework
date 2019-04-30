/*
 * File Name:				main.cpp
 * Program Description:		An implementation of sorted linked lists
 * Course Name:				Workshop in C++
 * Assignment Number:		5
 * Question Number:			1
 * Author:					Abraham Murciano
 */

#include "list.h"
#include <iostream>
using namespace std;

int main() {
	list l;
	cout << "enter the list values" << endl;
	cin >> l;

	while (true) {
		int choice;
		cout << "choose 0-2" << endl;
		cin >> choice;

		try {
			if (choice == 0) {
				break;
			} else if (choice == 1) {  // Insert a value
				int val;
				cout << "enter a value to insert" << endl;
				cin >> val;
				l.insert(val);
			} else if (choice == 2) {  // Remove a value
				int val;
				cout << "enter a value to remove" << endl;
				cin >> val;
				l.remove(val);
			} else {
				throw "ERROR";
			}
			cout << l << endl;
		} catch (const char* e) {
			cout << e << endl;
		}
	}

	return 0;
}

/*
========== Sample Run - start ==========
Enter a list, terminated by enter.
1, 2, 3, 4, 5
Inputted list:
[1][2][3][4][5]
=========== Sample Run - end ===========
----------------------------------------
========== Sample Run - start ==========
Enter a list, terminated by enter.
5|4|3|2|1
Inputted list:
[5][4][3][2][1]
=========== Sample Run - end ===========
----------------------------------------
*/