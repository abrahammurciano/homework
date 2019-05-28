/*
 * File Name:				student.cpp
 * Program Description:		Polymorphism
 * Course Name:				Workshop in C++
 * Assignment Number:		7
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

// Prints the student information
void student::print() const {
	cout << "ID: " << id << endl;
	cout << "first name: " << name << endl;
	cout << "last name:  " << surname << endl;
	cout << "num courses: " << nCourses << endl;
}