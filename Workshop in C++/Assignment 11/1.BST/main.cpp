/*
 * File Name:				main.cpp
 * Program Description:		Binary search trees
 * Course Name:				Workshop in C++
 * Assignment Number:		11
 * Question Number:			1
 * Author:					Abraham Murciano
 */

#include "BST.h"
#include "Tree.h"
#include <iostream>
using namespace std;

int main() {
	BST<int> T1;
	cout << "enter 10 numbers\n";
	int x, y;
	for (int i = 0; i < 10; i++) {
		cin >> x;
		T1.insert(x);
	}
	cout << "inorder: ";
	T1.for_each([](int& n) { cout << n << ' '; });
	cout << "\nenter 0-6:\n";
	cin >> x;
	while (x != 0) {
		switch (x) {
			case 1:
				cout << "# of leaves: " << T1.leaves() << endl;
				break;
			case 2:
				cout << "height of tree: " << T1.height() << endl;
				break;
			case 3:
				T1.reflect();

				cout << "reflected tree: ";
				T1.for_each([](int& n) { cout << n << ' '; });
				T1.reflect();
				cout << endl;
				break;
			case 4:
				cout << "# left sons only: " << T1.onlyLeftChild() << endl;
				break;
			case 5:
				cout << "enter a number ";

				cin >> y;
				cout << "level of " << y << " on tree: " << T1.level(y) << endl;
				break;
			case 6:
				cout << "enter a number ";
				cin >> y;
				T1.remove(y);
				cout << "after removing " << y << ": ";
				T1.for_each([](int& n) { cout << n << ' '; });
				cout << endl;
		}
		cout << "enter 0-6:\n";
		cin >> x;
	}
	return 0;
}

/*
========== Sample Run - start ==========
enter 10 numbers
5 7 3 8 4 9 1 3 2 6
inorder: 1 2 3 3 4 5 6 7 8 9
enter 0-6:
1
# of leaves: 4
enter 0-6:
2
height of tree: 5
enter 0-6:
3
reflected tree: 9 8 7 6 5 4 3 3 2 1
enter 0-6:
4
# left sons only: 1
enter 0-6:
5
enter a number 6
level of 6 on tree: 2
enter 0-6:
6
enter a number 7
after removing 7: 1 2 3 3 4 5 6 8 9
enter 0-6:
0
=========== Sample Run - end ===========
----------------------------------------
*/