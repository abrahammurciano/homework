/*
 * File Name:				main.cpp
 * Program Description:		Implementation of a string class
 * Course Name:				Workshop in C++
 * Assignment Number:		3
 * Question Number:			1
 * Author:					Abraham Murciano
 */

#include "str.h"
#include <iostream>
using namespace std;

int main() {

	str a, b;
	int n;
	a.input();
	b.input();
	cin >> n;

	if (a > b) {
		cout << "a>b" << endl;
	} else if (a < b) {
		cout << "a<b" << endl;
	} else {
		cout << "a=b" << endl;
	}

	if (n > b.length() || n < 0) {
		cout << "ERROR" << endl;
		return 0;
	}
	b.insert(a, n).print(true);

	return 0;
}

/*
========== Sample Run - start ==========
World
Hello
5
a>b
HelloWorld
=========== Sample Run - end ===========
----------------------------------------
========== Sample Run - start ==========
Hello
Hello
2
a=b
HeHellollo
=========== Sample Run - end ===========
----------------------------------------
========== Sample Run - start ==========
Hello
World
2
a<b
WoHellorld
=========== Sample Run - end ===========
----------------------------------------
========== Sample Run - start ==========
Hello
World
0
a<b
HelloWorld
=========== Sample Run - end ===========
----------------------------------------
========== Sample Run - start ==========
Hello
World
8
a<b
ERROR
=========== Sample Run - end ===========
----------------------------------------
*/