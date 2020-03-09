/*
 * File Name:				main.cpp
 * Program Description:		Implementation of a vector class
 * Course Name:				Workshop in C++
 * Assignment Number:		3
 * Question Number:			2
 * Author:					Abraham Murciano
 */

#include "vec.h"
#include <iostream>
using namespace std;

int main() {
	vec v1(10), v2(10), v3;
	for (int i = 1; i <= 4; i++) {
		v1.insert(i);
		v2.insert(i + 4);
	}
	int choice, val;
	while (true) {
		cout << "enter your choice 0-6" << endl;
		cin >> choice;
		if (choice == 0) {  // Exit
			break;
		} else if (choice == 1) {  // Assignment (=)
			v3 = v1;
		} else if (choice == 2) {  // Check if equal (==)
			cout << "v1" << (v1 == v2 ? '=' : '!') << "=v2 " << endl;
		} else if (choice == 3) {  // Dot product (*)
			cout << "v1*v2=" << v1 * v2 << endl;
		} else if (choice == 4) {  // Concatenation (+)
			v3 = v1 + v2;
		} else if (choice == 5) {  // Clear
			v1.clear();
		} else if (choice == 6) {  // Delete last
			v2.delLast();
		} else {
			cout << "ERROR";
		}
		v1.print();
		v2.print();
		v3.print();
	}
	return 0;
}

/*
========== Sample Run - start ==========
enter your choice 0-6
1
capacity: 10 size: 4 val: 1 2 3 4
capacity: 10 size: 4 val: 5 6 7 8
capacity: 10 size: 4 val: 1 2 3 4
enter your choice 0-6
2
v1!=v2
capacity: 10 size: 4 val: 1 2 3 4
capacity: 10 size: 4 val: 5 6 7 8
capacity: 10 size: 4 val: 1 2 3 4
enter your choice 0-6
3
v1*v2=70
capacity: 10 size: 4 val: 1 2 3 4
capacity: 10 size: 4 val: 5 6 7 8
capacity: 10 size: 4 val: 1 2 3 4
enter your choice 0-6
4
capacity: 10 size: 4 val: 1 2 3 4
capacity: 10 size: 4 val: 5 6 7 8
capacity: 8 size: 8 val: 1 2 3 4 5 6 7 8
enter your choice 0-6
5
capacity: 10 size: 0 val:
capacity: 10 size: 4 val: 5 6 7 8
capacity: 8 size: 8 val: 1 2 3 4 5 6 7 8
enter your choice 0-6
6
capacity: 10 size: 0 val:
capacity: 10 size: 3 val: 5 6 7
capacity: 8 size: 8 val: 1 2 3 4 5 6 7 8
enter your choice 0-6
0
=========== Sample Run - end ===========
----------------------------------------
*/