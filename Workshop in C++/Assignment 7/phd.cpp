/*
 * File Name:				phd.cpp
 * Program Description:		Polymorphism
 * Course Name:				Workshop in C++
 * Assignment Number:		7
 * Author:					Abraham Murciano
 */

#include "phd.h"
#include "iostream"
using namespace std;

// Default constructor
phd::phd() {
	hours = 0;
}

// Constructor
phd::phd(int id, string name, string surname, int nCourses, float hours)
	: student(id, name, surname, nCourses) {
	this->hours = hours;
}

// Returns whether or not the student is entitled to a scholarship
bool phd::entitled() const {
	return nCourses >= 2 && hours > 25;
}

// Prints the student information
void phd::print() const {
	student::print();
	cout << "hours: " << hours << endl;
}