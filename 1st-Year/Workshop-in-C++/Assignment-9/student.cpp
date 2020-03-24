/*
 * File Name:				student.cpp
 * Program Description:		Standard Library
 * Course Name:				Workshop in C++
 * Assignment Number:		9
 * Author:					Abraham Murciano
 */

#include "student.h"
#include "iostream"
using namespace std;

// Default constructor
student::student() {
	this->nCourses = 0;
}

// Constructor
student::student(int id, string name, string surname, int nCourses) {
	this->id = id;
	this->name = name;
	this->surname = surname;
	this->nCourses = nCourses;
}

// Destructor
student::~student() {}

// Returns the first name of the student
string student::getName() const {
	return name;
}

// Returns the surname of the student
string student::getSurname() const {
	return surname;
}

// Returns the number of courses the student is taking
int student::getNCourses() const {
	return nCourses;
}

// Prints the student information
void student::print() const {
	cout << "ID: " << id << endl;
	cout << "first name: " << name << endl;
	cout << "last name:  " << surname << endl;
	cout << "num courses: " << nCourses << endl;
}