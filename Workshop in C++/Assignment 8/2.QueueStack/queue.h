/*
 * File Name:				queue.h
 * Program Description:		Implementation of queues using stacks
 * Course Name:				Workshop in C++
 * Assignment Number:		8
 * Question Number:			2
 * Author:					Abraham Murciano
 */

#ifndef queue_h
#define queue_h

template <class T>
class queue {
  public:
	virtual void clear() = 0;
	virtual void enqueue(const T& value) = 0;
	virtual T dequeue() = 0;
	virtual T front() const = 0;
	virtual bool isEmpty() const = 0;
};

#endif
