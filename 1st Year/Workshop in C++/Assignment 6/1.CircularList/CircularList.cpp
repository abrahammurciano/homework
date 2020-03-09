/*
 * File Name:				CircularList.cpp
 * Program Description:		An implementation of circular linked lists
 * Course Name:				Workshop in C++
 * Assignment Number:		6
 * Question Number:			1
 * Author:					Abraham Murciano
 */

#include "CircularList.h"
//#include "iostream"
// using namespace std;

// Default Constructor
CircularList::CircularList() {
	head = tail = NULL;
}

// Copy constructor
CircularList::CircularList(const CircularList& l) {
	head = tail = NULL;
	tail = new node(0, head);
	node* src = l.head;
	if (!l.isEmpty()) {
		do {
			tail->next = new node(src->val);
			src = src->next;
			tail = tail->next;
		} while (src != l.head);
	}
}

CircularList::~CircularList() {
	clear();
}

// Delete all elements from the list
void CircularList::clear() {
	if (!isEmpty()) {
		node* next;
		node* headCpy = head;
		node* p = head;
		do {
			next = p->next;
			delete p;
			p = next;
		} while (p != headCpy);
		head = tail = NULL;
	}
}

// Add a new value to the front of a linked list
void CircularList::prepend(int val) {
	bool wasEmpty = isEmpty();
	list::prepend(val);
	(wasEmpty ? tail : tail->next) = head;
}

// Add a new value to the back of a linked list
void CircularList::append(int val) {
	node* n = new node(val, head);
	if (n == NULL) {
		throw "Error: Memory could not be allocated.";
	}
	if (isEmpty()) {
		head = tail = n;
		tail->next = n;
	} else {
		tail = tail->next = n;
	}
}

// Delete first value in list
void CircularList::removeFirst() {
	node* headCpy = head;
	list::removeFirst();
	if (head == headCpy) {  // If there was only one element
		head = tail = NULL;
	} else {
		tail->next = head;
	}
}

// Returns element at position index (with overflow)
int CircularList::search(int index) {
	node* p = head;
	for (int i = 0; i < index; i++) {
		p = p->next;
	}
	return p->val;
}

ostream& operator<<(ostream& out, const CircularList& l) {
	if (!l.isEmpty()) {
		CircularList::node* p = l.head;
		do {
			out << '[' << p->val << ']';
			p = p->next;
		} while (p != l.head);
	}
	return out;
}