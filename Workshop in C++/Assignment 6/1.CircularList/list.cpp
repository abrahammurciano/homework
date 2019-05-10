/*
 * File Name:				list.cpp
 * Program Description:		An implementation of circular linked lists
 * Course Name:				Workshop in C++
 * Assignment Number:		6
 * Question Number:			1
 * Author:					Abraham Murciano
 */

#include "list.h"
#include <stdlib.h>
using namespace std;

// Constructor
list::node::node(int val, node* next) {
	this->val = val;
	this->next = next;
}

// Copy constructor
list::node::node(const node& n) {
	val = n.val;
	next = NULL;
}

// Default constructor
list::list() {
	head = NULL;
}

// Copy constructor
list::list(const list& l) {
	head = NULL;
	node* src = l.head;
	node* tgt = new node(0, head);
	while (src != NULL) {
		tgt->next = new node(src->val);
		src = src->next;
		tgt = tgt->next;
	}
}

// Destructor
list::~list() {
	clear();
}

// Delete all elements from the list
void list::clear() {
	node* next;
	for (node* p = head; p != NULL; p = next) {
		next = p->next;
		delete p;
	}
	head = NULL;
}

// Check if the list is empty
bool list::isEmpty() const {
	return head == NULL;
}

// Add a new value to the front of a linked list
void list::prepend(int val) {
	node* n = new node(val, head);
	if (n == NULL) {
		throw "Error: Memory could not be allocated.";
	}
	head = n;
}

// Return first value in list
int list::firstElement() const {
	if (isEmpty())
		throw "Error: Cannot get first element of an empty list.";
	return head->val;
}

// Delete first value in list
void list::removeFirst() {
	// make sure there is a first element
	if (isEmpty()) {
		throw "Error: Cannot delete first element of an empty list.";
	}
	node* p = head;
	head = head->next;
	delete p;
}