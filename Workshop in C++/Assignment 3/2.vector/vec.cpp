/*
 * File Name:				vec.cpp
 * Program Description:		Implementation of a vector class
 * Course Name:				Workshop in C++
 * Assignment Number:		3
 * Question Number:			2
 * Author:					Abraham Murciano
 */

#include "vec.h"
#include <iostream>
using namespace std;

vec::vec(const int n) {
	capacity = n;
	size = 0;
	data = new int[capacity];
}

vec::vec(const vec& v) {
	capacity = v.capacity;
	size = v.size;
	data = new int[capacity];
	for (int i = 0; i < size; i++) {
		data[i] = v[i];
	}
}

vec::~vec() {
	delete[] data;
}

int vec::getCapacity() {
	return capacity;
}

int vec::getSize() {
	return size;
}

void vec::clear() {
	size = 0;
}

void vec::insert(const int n) {
	if (size == capacity) {
		cout << "ERROR" << endl;
	} else {
		data[size++] = n;
	}
}

void vec::print() {
	cout << "capacity: " << capacity << " size: " << size << " val:";
	for (int i = 0; i < size; i++) {
		cout << ' ' << data[i];
	}
	cout << endl;
}

void vec::delLast() {
	if (size < 1) {
		cout << "ERROR" << endl;
	} else {
		size--;
	}
}

vec& vec::operator=(const vec& v) {
	capacity = v.capacity;
	size = v.size;
	delete[] data;
	data = new int[size];
	for (int i = 0; i < size; i++) {
		data[i] = v[i];
	}
	return *this;
}

bool vec::operator==(const vec& v) const {
	if (size != v.size) {
		return false;
	}
	for (int i = 0; i < size; i++) {
		if (data[i] != v[i]) {
			return false;
		}
	}
	return true;
}

int& vec::operator[](const int i) const {
	if (i >= size) {
		cout << "ERROR" << endl;
	}
	return data[i];
}

int vec::operator*(const vec& v) const {
	if (size != v.size) {
		cout << "ERROR" << endl;
		return 0;
	}
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += data[i] * v[i];
	}
	return sum;
}

vec vec::operator+(const vec& v) const {
	vec concat(size + v.size);
	concat.size = concat.capacity;
	int index = 0;
	for (int i = 0; i < size; i++) {
		concat[index++] = data[i];
	}
	for (int i = 0; i < v.size; i++) {
		concat[index++] = v[i];
	}
	return concat;
}
