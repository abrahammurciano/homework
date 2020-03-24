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
enter the list values
1 2 3 4 5 4
choose 0-2
1
enter a value to insert
7
1 2 3 4 5 7
choose 0-2
1
enter a value to insert
6
1 2 3 4 5 6 7
choose 0-2
1
enter a value to insert
11
1 2 3 4 5 6 7 11
choose 0-2
2
enter a value to remove
3
1 2 4 5 6 7 11
choose 0-2
2
enter a value to remove
1
2 4 5 6 7 11
choose 0-2
2
enter a value to remove
11
2 4 5 6 7
choose 0-2
0
=========== Sample Run - end ===========
----------------------------------------
*/