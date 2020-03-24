/*
 * File Name:				student.cpp
 * Program Description:		Files - Students' summer classes system
 * Course Name:				Workshop in C++
 * Assignment Number:		10
 * Author:					Abraham Murciano
 */

#include "student.h"
#include "iostream"
using namespace std;

student::student() {
	id = name[0] = surname[0] = courses[0] = courses[1] = courses[2] = courses[3] = courses[4] = 0;
}

student::student(int id, const char* name, const char* surname, bool* courses) {
	this->id = id;

	setName(name, surname);

	for (int i = 0; i < 5; i++) {
		this->courses[i] = courses[i];
	}
}

int student::getId() const {
	return id;
}

string student::getName() const {
	return string(name) + ' ' + string(surname);
}

bool student::getCourse(int i) const {
	return courses[i];
}

void student::setId(int id) {
	this->id = id;
}

void student::setName(const char* name, const char* surname) {
	int i;
	for (i = 0; name[i] != '\0' && i < 20; i++) {
		this->name[i] = name[i];
	}
	this->name[20] = this->name[i] = '\0';

	for (i = 0; surname[i] != '\0' && i < 20; i++) {
		this->surname[i] = surname[i];
	}
	this->surname[20] = this->surname[i] = '\0';
}

void student::setCourse(int i, bool val) {
	courses[i] = val;
}

void student::print() const {
	if (id != 0) {
		cout << name << ' ' << surname << "\t\t";
		for (int i = 0; i < 5; i++) {
			cout << (courses[i] ? "Y " : "N ");
		}
		cout << endl;
	}
}