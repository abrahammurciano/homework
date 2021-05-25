/*
 * File Name:				main.cpp
 * Program Description:		Stacks, postfix and calculations
 * Course Name:				Workshop in C++
 * Assignment Number:		8
 * Question Number:			1
 * Author:					Abraham Murciano
 */

#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;

string infixToPostfix(string exp) {
	string str;
	stack<char> stack;
	for (auto i = exp.begin(); i != exp.end(); i++) {
		char c = *i;
		if (c == '(') {
			stack.push(c);
		} else if (c == ')') {
			while (!stack.empty()) {
				char temp = stack.top();
				stack.pop();
				if (temp == '(') {
					break;
				}
				(str += temp) += ' ';
			};
		} else if (c == '+' || c == '-') {
			if (i == exp.begin() || *(i - 1) == '+' || *(i - 1) == '-' || *(i - 1) == '*' ||
				*(i - 1) == '/' || *(i - 1) == '(') {
				(str += '0') += ' ';
			} else {
				while (!stack.empty() && (stack.top() == '+' || stack.top() == '-' ||
					stack.top() == '*' || stack.top() == '/')) {
					(str += stack.top()) += ' ';
					stack.pop();
				}
			}
			stack.push(c);
		} else if (c == '*' || c == '/') {
			while (!stack.empty() && (stack.top() == '*' || stack.top() == '/')) {
				(str += stack.top()) += ' ';
				stack.pop();
			}
			stack.push(c);
		} else if (c >= '0' && c <= '9') {
			while (true) {
				str += c;
				c = *(i + 1);
				if (c < '0' || c > '9') {
					break;
				}
				i++;
			}
			str += ' ';
		} else {
			exp.erase(i, i + 1);
			i--;
		}
	}

	while (!stack.empty()) {
		(str += stack.top()) += ' ';
		stack.pop();
	}

	return str;
}

int calcPostfix(const string& exp) {
	stack<float> stack;
	for (auto i = exp.begin(); i != exp.end(); i++) {
		char c = *i;
		if (c >= '0' && c <= '9') {
			string n;
			while (true) {
				n += c;
				c = *(i + 1);
				if (c < '0' || c > '9') {
					break;
				}
				i++;
			}
			stack.push(stof(n));
		} else if (c == '+' || c == '-' || c == '*' || c == '/') {
			float right = stack.top();
			stack.pop();
			float left = stack.top();
			stack.pop();
			stack.push(c == '+' ? left + right
				: c == '-' ? left - right : c == '*' ? left * right : left / right);
		}
	}
	return stack.top();
}

int main() {
	string exp;
	cout << "enter an infix expression as a string" << endl;
	getline(cin, exp);
	string postfix = infixToPostfix(exp);
	cout << postfix << endl;
	cout << calcPostfix(postfix) << endl;
	return 0;
}

/*
========== Sample Run - start ==========
enter an infix expression as a string
5+3*20/10+8-6
5 3 20 * 10 / + 8 + 6 -
13
=========== Sample Run - end ===========
----------------------------------------
========== Sample Run - start ==========
enter an infix expression as a string
(5+3)*((20/10)+(8-6))
5 3 + 20 10 / 8 6 - + *
32
=========== Sample Run - end ===========
----------------------------------------
========== Sample Run - start ==========
enter an infix expression as a string
-5--2
0 5 - 0 2 - -
-3
=========== Sample Run - end ===========
----------------------------------------
*/