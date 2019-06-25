/*
 * File Name:				main.cpp
 * Program Description:		Implementation of queues using stacks
 * Course Name:				Workshop in C++
 * Assignment Number:		8
 * Question Number:			2
 * Author:					Abraham Murciano
 */

#include "qStack.h"
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
	queue<int>* Q;
	Q = new qStack<int>();
	try {
		for (int i = 0; i < 10; i++) {
			Q->enqueue(i);
		}
	} catch (const char* msg) {
		cout << msg;
	}
	cout << "first on Q is: " << Q->front() << endl;
	cout << "take out 2 elemets:" << endl;
	cout << Q->dequeue() << ' ' << Q->dequeue() << endl;
	cout << "first on Q is: " << Q->front() << endl;
	Q->enqueue(8);
	Q->enqueue(9);
	while (!Q->isEmpty()) {
		cout << Q->dequeue() << " ";
	}
	cout << endl;
	return 0;
}

/*
========== Sample Run - start ==========
first on Q is: 0
take out 2 elemets:
0 1
first on Q is: 2
2 3 4 5 6 7 8 9 8 9
=========== Sample Run - end ===========
----------------------------------------
*/