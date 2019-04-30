/*
 * File Name:				main.cpp
 * Program Description:		An implementation of linked lists
 * Course Name:				Workshop in C++
 * Assignment Number:		5
 * Question Number:			1
 * Author:					Abraham Murciano
 */

#include "list.h"
#include <iostream>
using namespace std;

int main() {
	list l1;
	cout << "Enter a list, terminated by enter." << endl;
	cin >> l1;
	list l2 = l1;
	cout << "Inputted list:\n" << l2 << endl;

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