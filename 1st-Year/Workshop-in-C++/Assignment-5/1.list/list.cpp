/*
 * File Name:				list.cpp
 * Program Description:		An implementation of linked lists
 * Course Name:				Workshop in C++
 * Assignment Number:		5
 * Question Number:			1
 * Author:					Abraham Murciano
 */

#include "list.h"

list::node::node(int val) {
	this->val = val;
	next = NULL;
}

list::node::node(const node& n) {
	val = n.val;
	next = NULL;
}

list::list() {
	head = tail = NULL;
}

list::list(int size, int val) {
	head = tail = NULL;
	if (size < 1) {
		throw "Error: Size of list must be positive.";
	}
	for (int i = 0; i < size; i++) {
		append(val);
	}
}

list::list(const list& l) {
	head = tail = NULL;
	for (node* p = l.head; p != NULL; p = p->next) {
		append(p->val);
	}
}

void list::delNodesFrom(node* n) {
	if (n == NULL) {
		return;
	}
	delNodesFrom(n->next);
	delete n;
}

void list::append(int val) {
	if (isEmpty()) {
		tail = head = new node(val);
	} else {
		tail = tail->next = new node(val);
	}
}

void list::prepend(int val) {
	if (isEmpty()) {
		tail = head = new node(val);
	} else {
		node* temp = new node(val);
		temp->next = head;
		head = temp;
	}
}

void list::insert(int val, int pos) {
	if (pos < 0) {
		throw "Error: Unable to insert a value into a negative index of a list.";
	}
	if (pos == 0) {
		prepend(val);
	} else {
		node* p = head;
		for (int i = 1; i < pos; i++) {
			p = p->next;
		}
		insert(val, p);
	}
}

void list::insert(int val, node* pos) {
	node* temp = pos->next;
	pos->next = new node(val);
	pos->next->next = temp;
}

void list::clear() {
	delNodesFrom(head);
	head = tail = NULL;
}

bool list::isEmpty() const {
	return head == NULL;
}

int& list::operator[](int index) const {
	node* p = head;
	for (int i = 0; i < index; i++) {
		p = p->next;
		if (p == NULL) {
			throw "Error: Index is out of bounds of list.";
		}
	}
	return p->val;
}

list& list::operator=(const list& l) {
	if (this != &l) {
		clear();
		for (node* p = l.head; p->next != NULL; p = p->next) {
			append(p->val);
		}
	}
	return *this;
}

ostream& operator<<(ostream& out, const list& l) {
	for (list::node* p = l.head; p != NULL; p = p->next) {
		out << '[' << p->val << ']';
	}
	return out;
}

istream& operator>>(istream& in, list& l) {
	l.clear();
	l.append(0);
	in >> noskipws;
	char c;
	bool newNum = false;
	bool hasInput = false;
	for (in >> c; c != '\n' || !hasInput; in >> c) {
		if (c >= '0' && c <= '9') {
			l.tail->val *= 10;
			l.tail->val += (int)(c - '0');
			newNum = hasInput = true;
		} else if (newNum) {
			l.append(0);
			newNum = false;
		}
	}
	if (!hasInput) {
		l.clear();
	}
	return in;
}