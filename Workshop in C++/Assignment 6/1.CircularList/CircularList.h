/*
 * File Name:				CircularList.h
 * Program Description:		An implementation of circular linked lists
 * Course Name:				Workshop in C++
 * Assignment Number:		6
 * Question Number:			1
 * Author:					Abraham Murciano
 */

#ifndef CircularList_h
#define CircularList_h

#include "list.h"
#include <iostream>
using namespace std;

class CircularList : public list {
	friend ostream& operator<<(ostream& out, const CircularList& l);

  protected:
	node* tail;

  public:
	// Constructors
	CircularList();
	CircularList(const CircularList&);
	~CircularList();

	// Methods
	void clear();
	void prepend(int val);
	void append(int val);
	void removeFirst();
	int search(int i);
};

ostream& operator<<(ostream& out, const CircularList& l);

#endif
