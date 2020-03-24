/*
 * File Name:				list.h
 * Program Description:		An implementation of circular linked lists
 * Course Name:				Workshop in C++
 * Assignment Number:		6
 * Question Number:			1
 * Author:					Abraham Murciano
 */

#ifndef list_h
#define list_h

#include <stdlib.h>
using namespace std;

class list {
  protected:
	class node {
	  public:
		// Constructors
		node(int val = 0, node* next = NULL);
		node(const node& n);
		// Data
		int val;
		node* next;
	};

	node* head;

  public:
	// Constructors
	list();
	list(const list&);
	~list();

	// Methods
	void prepend(int val);
	int firstElement() const;
	bool isEmpty() const;
	void removeFirst();
	void clear();

  protected:
};

#endif
