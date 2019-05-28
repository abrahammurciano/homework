/*
 * File Name:				ma.cpp
 * Program Description:		Polymorphism
 * Course Name:				Workshop in C++
 * Assignment Number:		7
 * Author:					Abraham Murciano
 */

#include "ma.h"
#include "iostream"
using namespace std;

// Default constructor
ma::ma() {
	research = false;
}

// Constructor
ma::ma(int id, string name, string surname, int nCourses, int* grades, int nGrades, bool research)
	: ba(id, name, surname, nCourses, grades, nGrades) {
	this->research = research;
}

// Returns whether or not the student is entitled to a scholarship
bool ma::entitled() const {
	return research && nCourses >= 7 && avgGrade() > 90;
}

// Prints the student information
void ma::print() const {
	ba::print();
	cout << "research: " << (research ? "yes" : "no") << endl;
}