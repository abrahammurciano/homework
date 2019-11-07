/*
 * File Name:				main.cpp
 * Program Description:		Decision trees
 * Course Name:				Data Structures 2
 * Assignment Number:		1
 * Question Number:			1
 * Author:					Abraham Murciano
 */

#include "decision_tree.h"
#include <iostream>
using namespace std;

int main() {
	decision_tree t;
	string value, answer, next;
	char c;
	cout << endl;
	cout << "DECISION TREE" << endl;
	cout << "Choose one of the following:" << endl;
	cout << "n: New decision tree" << endl;
	cout << "s: Add a new option for a question" << endl;
	cout << "d: Delete a subtree" << endl;
	cout << "p: Print all tree" << endl;
	cout << "w: Print the path to a decision or a question" << endl;
	cout << "r: Run a process of questions" << endl;
	cout << "e: exit:" << endl;
	do {
		cin >> c;
		if (c == 'n') {
			cout << "enter the main question (with no space) ";
			cin >> value;
			t = decision_tree(value);
		} else if (c == 's') {
			cout << "enter the question (with no space) ";
			cin >> value;
			cout << "enter the new ValidAnswer (with no space) ";
			cin >> answer;
			cout << "enter the new solution(possible a new question, with no space) ";
			cin >> next;
			if (t.add_node(value, answer, next)) {
				cout << "success" << endl;
			} else {
				cout << "ERROR" << endl;
			}
		} else if (c == 'd') {
			cout << "enter value of subtree to delete (with no space) ";
			cin >> value;
			t.remove_subtree(value);
		} else if (c == 'p') {
			t.print();
		} else if (c == 'w') {
			cout << "enter a value (with no space) ";
			cin >> value;
			t.print_path(value);
			cout << endl;
		} else if (c == 'r') {
			t.run();
			cout << endl;
		} else if (c == 'e') {
			cout << "bye" << endl;
		} else {
			cout << "ERROR" << endl;
		}
	} while (c != 'e');
}