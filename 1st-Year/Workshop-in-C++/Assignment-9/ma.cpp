/*
 * File Name:				ma.cpp
 * Program Description:		Standard Library
 * Course Name:				Workshop in C++
 * Assignment Number:		9
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
ma::ma(int id, string name, string surname, int nCourses, vector<int> grades, bool research)
	: ba(id, name, surname, nCourses, grades) {
	this->research = research;
}

// Returns whether the student conducts research
bool ma::getResearch() const {
	return research;
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

// Returns the level of the student's education
string ma::type() const {
	return string("MA");
}