/*
 * File Name:				list.h
 * Program Description:		An implementation of sorted linked lists
 * Course Name:				Workshop in C++
 * Assignment Number:		5
 * Question Number:			1
 * Author:					Abraham Murciano
 */

#ifndef list_h
#define list_h

#include <iostream>
using namespace std;

class list {
	friend ostream& operator<<(ostream& out, const list& l);
	friend istream& operator>>(istream& in, list& l);

  private:
	class node {
		friend class list;
		friend ostream& operator<<(ostream& out, const list& l);
		friend istream& operator>>(istream& in, list& l);

	  private:
		int val;
		node* next;

	  public:
		node(int val = 0);
		node(const node& n);
	};

	node* head;
	node* tail;
	void delNodesFrom(node* n);
	void append(int val);
	void prepend(int val);
	void insert(int val, node* pos);
	void removeFirst();
	void removeNextNode(node* n);

  public:
	list();
	list(const list& l);
	void insert(int val);
	void remove(int val);
	void clear();
	bool isEmpty() const;

	int& operator[](int i) const;
	list& operator=(const list& l);
};

ostream& operator<<(ostream& out, const list& l);
istream& operator>>(istream& in, list& l);

#endif
