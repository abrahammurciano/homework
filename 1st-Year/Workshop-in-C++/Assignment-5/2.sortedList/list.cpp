/*
 * File Name:				list.cpp
 * Program Description:		An implementation of sorted linked lists
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

void list::insert(int val) {
	if (val < head->val) {
		prepend(val);
	} else {
		node* p;
		for (p = head; p->next != NULL && p->next->val <= val; p = p->next) {
			continue;
		}
		if (p->val == val) {
			throw "Error: Tried to insert value that already existed in list";
		}
		insert(val, p);
	}
}

void list::insert(int val, node* pos) {
	node* tmp = pos->next;
	pos->next = new node(val);
	if (tmp == NULL) {
		tail = pos->next;
	}
	pos->next->next = tmp;
}

void list::remove(int val) {
	if (!isEmpty()) {
		if (!isEmpty() && head->val == val) {
			removeFirst();
			return;
		} else {
			for (node* p = head; p->next != NULL && p->next->val <= val; p = p->next) {
				if (p->next->val == val) {
					removeNextNode(p);
					return;
				}
			}
		}
	}
	throw "value not found";
}

void list::removeFirst() {
	if (head == NULL) {
		throw "Error: Unable to delete nonexistent element from list";
	}
	node* tmp = head;
	head = head->next;
	if (head == NULL) {
		tail = NULL;
	}
	delete tmp;
}

void list::removeNextNode(node* n) {
	if (n->next == NULL) {
		throw "Error: Unable to delete nonexistent element from list";
	}
	node* tmp = n->next;
	n->next = n->next->next;
	if (n->next == NULL) {
		tail = n;
	}
	delete tmp;
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
		for (node* p = l.head; p != NULL; p = p->next) {
			append(p->val);
		}
	}
	return *this;
}

ostream& operator<<(ostream& out, const list& l) {
	if (!l.isEmpty()) {
		for (list::node* p = l.head; p->next != NULL; p = p->next) {
			out << p->val << ' ';
		}
		out << l.tail->val;
	}
	return out;
}

istream& operator>>(istream& in, list& l) {
	l.clear();
	int n;
	in >> n;
	l.append(n);
	for (in >> n; n > l.tail->val; in >> n) {
		l.append(n);
	}
	return in;
}