/*
 * File Name:				1.shop.cpp
 * Program Description:		Sales & stock management system for a shop
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		10
 * Question Number:			1
 * Author:					Abraham Murciano
 *
 * Created on:				Sat Dec 29 2018
 * Last Modified on:		Sun Dec 30 2018
 */

#include <climits>
#include <iostream>
using namespace std;

struct item {
	int id;
	char* name;
	int stock;
	int minStock;
	float price;
};

// Function that resizes a dynamic array from size to newSize
void resize(char*& arr, int size, int newSize) {
	char* newArr = new char[newSize];			// Declare new array
	int n = (size < newSize) ? size : newSize;  // Get smallest of the two sizes
	// Copy n elements from old to new array
	for (int i = 0; i < n; i++) {
		newArr[i] = arr[i];
	}
	delete[] arr;  // Delete old array
	arr = newArr;  // Update pointer of arr
}

// Function that reads text from user until a terminator character (\n by default) is input. It will
// then return a pointer to a dynamic array containing all the input.
char* getText(char terminator = '\n') {
	int i = 0;					 // Keeps track of index to be input
	int size = 4;				 // Keeps track of size of dynamically allocated array
	char* str = new char[size];  // Create dynamic string

	while (true) {
		// Temporarily store input character (could be whitespace)
		char chtr = terminator;
		cin >> noskipws >> chtr >> skipws;
		if (chtr == terminator || i == 21) {  // Stop at terminator character
			if (i == 0) {
				continue;  // If first character is a terminator, ignore it
			}
			str[i] = '\0';
			return str;
		} else {
			if (i >= size) {  // Check if array is too small to hold another character
				// Double size of array
				int newSize = size * 2;
				resize(str, size, newSize);
				size = newSize;
			}
			str[i++] = chtr;  // Put input into array
		}
	}
}

// Function that given 2 words, will return 1 if the first word comes first in lexicographic order,
// -1 if it comes second and 0 if they're the same
int strComp(char* str1, char* str2) {

	// Repeat until the end of one string is reached
	int i = 0;
	do {
		if (str1[i] < str2[i]) {
			return 1;  // If str1's ith letter is first, str1 comes first
		} else if (str1[i] > str2[i]) {
			return -1;  // If str2's ith letter is first, str2 comes first
		}
		i++;
	} while (str1[i - 1] != '\0' && str2[i - 1] != '\0');

	return 0;  // If neither 1 or -1 has been returned yet, the words are the same
}

int search(item shop[], int id) {
	for (int i = 0; shop[i].id > 0; i++) {
		if (id == shop[i].id) {
			return i;
		}
	}
	return -1;
}

int findSpace(item shop[]) {
	for (int i = 0; shop[i].id >= 0; i++) {
		if (shop[i].id == 0) {
			return i;
		}
	}
	return -1;
}

void addItem(item shop[]) {

	item newItem;

	while (true) {
		cout << "enter code:" << endl;
		cin >> newItem.id;
		if (newItem.id > 0) {
			break;
		}
		cout << "ERROR" << endl;  // Must be positive integer
	}

	cout << "enter name:" << endl;
	newItem.name = getText();

	while (true) {
		cout << "enter amount:" << endl;
		cin >> newItem.stock;
		if (newItem.stock >= 0) {
			break;
		}
		cout << "ERROR" << endl;  // Must be non-negative integer
	}

	while (true) {
		cout << "enter minimum amount:" << endl;
		cin >> newItem.minStock;
		if (newItem.minStock >= 0) {
			break;
		}
		cout << "ERROR" << endl;  // Must be non-negative integer
	}

	while (true) {
		cout << "enter price:" << endl;
		cin >> newItem.price;
		if (newItem.price >= 0) {
			break;
		}
		cout << "ERROR" << endl;  // Must be non-negative float
	}

	int pos = search(shop, newItem.id);
	if (pos >= 0) {
		if (strComp(shop[pos].name, newItem.name) == 0) {
			shop[pos].stock += newItem.stock;
		} else {
			cout << "ERROR" << endl;  // Item code already taken
		}
		return;
	}

	int space = findSpace(shop);
	if (space < 0) {
		cout << "ERROR" << endl;  // Max number of items reached
		return;
	}

	shop[space] = newItem;
}

void findPrice(item shop[]) {
	int id;
	cout << "enter code:" << endl;
	cin >> id;

	int pos = search(shop, id);

	if (pos < 0) {
		cout << "ERROR" << endl;
		return;
	}

	cout << "price: " << shop[pos].price << endl;
}

void sold(item shop[]) {
	int id;
	cout << "enter code:" << endl;
	cin >> id;

	int pos = search(shop, id);
	if (pos < 0) {
		cout << "ERROR" << endl;
		return;
	}

	int n;
	cout << "enter amount:" << endl;
	cin >> n;

	shop[pos].stock -= n;
}

void order(item shop[]) {
	for (int i = 0; shop[i].id > 0; i++) {
		if (shop[i].stock < shop[i].minStock) {
			int nToOrder = (shop[i].minStock - shop[i].stock) + 5;
			cout << "item name: " << shop[i].name << endl;
			cout << "code: " << shop[i].id << endl;
			cout << "amount to order: " << nToOrder << endl;
			shop[i].stock += nToOrder;
		}
	}
}

void print(item shop[]) {
	for (int i = 0; shop[i].id > 0; i++) {
		cout << "name: " << shop[i].name << endl;
		cout << "code: " << shop[i].id << endl;
		cout << "amount: " << shop[i].stock << endl;
		cout << "minimum amount: " << shop[i].minStock << endl;
		cout << "price: " << shop[i].price << endl;
		cout << endl;
	}
}

int main() {

	int max;
	cout << "enter max number of items: " << endl;
	cin >> max;
	item* shop = new item[max + 1];
	shop[max] = {-1};

	int choice;
	do {
		cout << "enter 0-5:" << endl;
		cin >> choice;

		if (!cin || choice < 0 || choice > 5) {
			cout << "ERROR" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}

		// Add item
		if (choice == 1) {
			addItem(shop);
		}

		// Find price of an item
		else if (choice == 2) {
			findPrice(shop);
		}

		// Record a sale
		else if (choice == 3) {
			sold(shop);
		}

		// Update the stock
		else if (choice == 4) {
			order(shop);
		}

		// Print items
		else if (choice == 5) {
			print(shop);
		}

	} while (choice != 0);

	return 0;
}

/*
========== Sample Run - start ==========
enter max number of items:
2
enter 0-5:
1
enter code:
100
enter name:
paper
enter amount:
200
enter minimum amount:
50
enter price:
28.9
enter 0-5:
1
enter code:
101
enter name:
pens
enter amount:
75
enter minimum amount:
80
enter price:
6.9
enter 0-5:
1
enter code:
100
enter name:
paper
enter amount:
50
enter minimum amount:
50
enter price:
28.9
enter 0-5:
1
enter code:
102
enter name:
pencils
enter amount:
300
enter minimum amount:
250
enter price:
1.75
ERROR
enter 0-5:
5
name: paper
code: 100
amount: 250
minimum amount: 50
price: 28.9

name: pens
code: 101
amount: 75
minimum amount: 80
price: 6.9

enter 0-5:
2
enter code:
103
ERROR
enter 0-5:
2
enter code:
101
price: 6.9
enter 0-5:
4
item name: pens
code: 101
amount to order: 10
enter 0-5:
5
name: paper
code: 100
amount: 250
minimum amount: 50
price: 28.9

name: pens
code: 101
amount: 85
minimum amount: 80
price: 6.9

enter 0-5:
3
enter code:
100
enter amount:
200
enter 0-5:
5
name: paper
code: 100
amount: 50
minimum amount: 50
price: 28.9

name: pens
code: 101
amount: 85
minimum amount: 80
price: 6.9

enter 0-5:
0
=========== Sample Run - end ===========
----------------------------------------
*/