#include "database.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main() {

	database db;

	cout << "Hash Tables" << endl << endl;
	cout << "Choose one of the following" << endl;
	cout << "n: New item" << endl;
	cout << "d: Del an item " << endl;
	cout << "c: New client" << endl;
	cout << "l: Add a Landing " << endl;
	cout << "j: Dell a Landing " << endl;
	cout << "*: Print clients list of an item " << endl;
	cout << "e: Exit" << endl;

	char c;
	std::string item_name;
	int id;
	std::string client_name, phone;
	do {
		cin >> c;
		if (c == 'n') {
			cout << "enter item name" << endl;
			cin >> item_name;
			db.insert(item_name);
		} else if (c == 'd') {
			cout << "enter item name" << endl;
			cin >> item_name;
			try {
				db.remove(item_name);
			} catch (std::runtime_error) {
				cout << "ERROR" << endl;
			}
		} else if (c == 'c') {
			cout << "please enter name id phone" << endl;
			cin >> id >> client_name >> phone;
			db.insert(id, client_name, phone);
		} else if (c == 'l') {
			cout << "enter client id and item name" << endl;
			cin >> id >> item_name;
			try {
				db.borrow_item(id, item_name);
			} catch (std::runtime_error) {
				cout << "ERROR" << endl;
			}
		} else if (c == 'j') {
			cout << "enter client id and item name" << endl;
			cin >> id >> item_name;
			db.return_item(id, item_name);
		} else if (c == '*') {
			cout << "enter item name" << endl;
			cin >> item_name;
			db.print_clients(item_name);
		} else if (c == 'e') {
			cout << "bye" << endl;
		} else {
			cout << "ERROR" << endl;
		}
	} while (c != 'e');

	return 0;
}