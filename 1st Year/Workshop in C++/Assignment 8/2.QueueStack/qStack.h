/*
 * File Name:				qStack.h
 * Program Description:		Implementation of queues using stacks
 * Course Name:				Workshop in C++
 * Assignment Number:		8
 * Question Number:			2
 * Author:					Abraham Murciano
 */

#ifndef qStack_h
#define qStack_h

#include "queue.h"
#include <stack>
#include <stdlib.h>
using namespace std;

template <class T>
class qStack : public queue<T> {
  private:
	// Data
	mutable stack<T> _front;
	mutable stack<T> _back;

  public:
	// Methods
	void clear() override;
	void enqueue(const T& value) override;
	T dequeue() override;
	T front() const override;
	bool isEmpty() const override;
};

// Clear elements of the queue by emptying the front stack and back stack
template <class T>
void qStack<T>::clear() {
	while (!_front.empty()) {
		_front.pop();
	}
	while (!_back.empty()) {
		_back.pop();
	}
}

// Insert an element into the back of the queue
template <class T>
void qStack<T>::enqueue(const T& value) {
	_back.push(value);
}

// Remove the front element of the queue by popping the front stack
template <class T>
T qStack<T>::dequeue() {
	T temp = front();
	_front.pop();
	return temp;
}

// Return the front element of the queue by getting the topmost element on the front stack. If said
// stack is empty, flip the back stack onto the front stack.
template <class T>
T qStack<T>::front() const {
	if (_front.empty()) {
		if (_back.empty()) {
			throw "Error: Cannot access front of empty queue.";
		}
		while (!_back.empty()) {
			_front.push(_back.top());
			_back.pop();
		}
	}
	return _front.top();
}

// Check if the queue is empty by checking if both stacks are empty
template <class T>
bool qStack<T>::isEmpty() const {
	return _front.empty() && _back.empty();
}

#endif
