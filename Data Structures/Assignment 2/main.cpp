#include "trie.h"
#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {

	int choice;
	string word;
	trie t;

	cout << endl;
	cout << "TRIE PROGRAM" << endl;
	cout << endl;
	cout << "Choose one of the following" << endl;
	cout << "1: add a new item" << endl;
	cout << "2: delete an item" << endl;
	cout << "3: check if an item exists " << endl;
	cout << "4: complete the possible item name " << endl;
	cout << "5: exit " << endl;

	do {
		cin >> choice;

		if (choice == 1) {
			cout << "Enter a word to insert" << endl;
			cin >> word;
			t.insert(word);
		} else if (choice == 2) {
			cout << "Enter a word to del" << endl;
			cin >> word;
			if (!t.remove(word)) {
				cout << "ERROR" << endl;
			}
		} else if (choice == 3) {
			cout << "Enter a word to search" << endl;
			cin >> word;
			if (t.search(word)) {
				cout << "exists" << endl;
			} else {
				cout << "does not exist" << endl;
			}
		} else if (choice == 4) {
			cout << "Enter a prefix to complete" << endl;
			cin >> word;
			if (!t.print_completions(word)) {
				cout << "No string exist with this prefix" << endl;
			}
		} else if (choice == 5) {
			cout << "bye" << endl;
		} else {
			cout << "ERROR" << endl;
		}
	} while (choice != 5);

	return 0;
}