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

list merge(const list& l1, const list& l2) {
	list merged;
	for (int i = 0; i < l1.size(); i++) {
		merged.insert(l1[i]);
	}
	for (int i = 0; i < l2.size(); i++) {
		merged.insert(l2[i]);
	}
	return merged;
}

void makeSet(list& l) {
	for (int i = 1; i < l.size(); i++) {
		if (l[i] == l[i - 1]) {
			l.remove(l[i]);
			i--;
		}
	}
}

int main() {
	list list1, list2, mergedList;

	cout << "enter sorted values for the first list:" << endl;
	cin >> list1;
	cout << "enter sorted values for the second list:" << endl;
	cin >> list2;

	mergedList = merge(list1, list2);
	cout << "the new merged list: " << mergedList << endl;

	makeSet(mergedList);
	cout << "the new merged set: " << mergedList << endl;

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