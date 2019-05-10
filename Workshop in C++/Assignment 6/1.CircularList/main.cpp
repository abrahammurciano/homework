/*
 * File Name:				main.cpp
 * Program Description:		An implementation of circular linked lists
 * Course Name:				Workshop in C++
 * Assignment Number:		6
 * Question Number:			1
 * Author:					Abraham Murciano
 */

#include "CircularList.h"
#include <iostream>
using namespace std;

int main() {

	CircularList l;
	int choice;
	do {
		try {
			cout << "Enter your choice: ";
			cin >> choice;
			int num;
			if (choice == 1) {  // Prepend
				cout << "Enter 5 numbers: ";
				for (int i = 0; i < 5; i++) {
					cin >> num;
					l.prepend(num);
				}
			} else if (choice == 2) {  // Append
				cout << "Enter 5 numbers: ";
				for (int i = 0; i < 5; i++) {
					cin >> num;
					l.append(num);
				}
			} else if (choice == 3) {  // Delete first element
				l.removeFirst();
			} else if (choice == 4) {  // Search for value at a position
				cout << "Enter a number: ";
				cin >> num;
				cout << l.search(num) << endl;
			} else if (choice == 5) {  // Clear list
				l.clear();
			} else if (choice == 6) {  // Check if empty
				cout << (l.isEmpty() ? "E" : "Not e") << "mpty" << endl;
			} else if (choice == 7) {  // Print
				cout << l << endl;
			} else if (choice != 0) {  // If the user entered an invalid option
				throw "Error: Must enter a choice between 0 and 7.";
			}
		} catch (char const* e) {
			cout << e << endl;
		}
	} while (choice != 0);
	return 0;
}

/*
========== Sample Run - start ==========
Enter your choice: 1
Enter 5 numbers: 1 2 3 4 5
Enter your choice: 7
[5][4][3][2][1]
Enter your choice: 2
Enter 5 numbers: 6 7 8 9 10
Enter your choice: 7
[5][4][3][2][1][6][7][8][9][10]
Enter your choice: 3
Enter your choice: 7
[4][3][2][1][6][7][8][9][10]
Enter your choice: 4
Enter a number: 2
2
Enter your choice: 4
Enter a number: 8
10
Enter your choice: 4
Enter a number: 9
4
Enter your choice: 5
Enter your choice: 7

Enter your choice: 6
Empty
Enter your choice: 0
=========== Sample Run - end ===========
----------------------------------------
*/