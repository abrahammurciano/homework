/*
 * File Name:				ba.cpp
 * Program Description:		Standard Library
 * Course Name:				Workshop in C++
 * Assignment Number:		9
 * Author:					Abraham Murciano
 */

#include "ba.h"
#include "iostream"
using namespace std;

// Default constructor
ba::ba() {}

// Constructor
ba::ba(int id, string name, string surname, int nCourses, vector<int> grades)
	: student(id, name, surname, nCourses) {
	this->grades = grades;
}

// Calculates the average grade of the student
float ba::avgGrade() const {
	int sum = 0;
	for (auto grade = grades.begin(); grade != grades.end(); grade++) {
		sum += *grade;
	}
	return (float)sum / grades.size();
}

// Returns whether or not the student is entitled to a scholarship
bool ba::entitled() const {
	return nCourses >= 10 && avgGrade() > 95;
}

// Prints the student information
void ba::print() const {
	student::print();
	cout << "grades: ";
	for (auto grade = grades.begin(); grade != grades.end(); grade++) {
		cout << *grade << ' ';
	}
	cout << endl;
}

// Returns the level of the student's education
string ba::type() const {
	return string("BA");
}