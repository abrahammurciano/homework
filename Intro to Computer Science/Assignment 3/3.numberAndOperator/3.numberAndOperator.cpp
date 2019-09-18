/*
 * File Name:				3.numberAndOperator.cpp
 * Program Description:		Takes 2 numbers and an operator, then displays
 * output
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		3
 * Question Number:			3
 * Author:					Abraham Murciano
 *
 * Created on:				Mon Oct 22 2018
 * Last Modified on:		Mon Oct 22 2018
 */

#include <iostream>
using namespace std;

int main() {

	cout << "enter 2 numbers:" << endl;
	int a, b;
	float ans;
	cin >> a >> b;
	cout << "enter an operator:" << endl;
	char op;
	cin >> op;
	
	switch (op) {
		case '+':
			ans = a + b;
			break;
		case '-':
			ans = a - b;
			break;
		case '*':
			ans = a * b;
			break;
		case '/':
			ans = (float)a / b;
			break;
		default:
			cout << "ERROR";
			return 0;
	}
	cout << a << ' ' << op << ' ' << b << " = " << ans << endl;

	return 0;
}

/*
enter 2 numbers:
2 10
enter an operator:
*
2 * 10 = 20
*/