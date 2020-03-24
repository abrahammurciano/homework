/*
 * File Name:				ba.cpp
 * Program Description:		Polymorphism
 * Course Name:				Workshop in C++
 * Assignment Number:		7
 * Author:					Abraham Murciano
 */

#include "ba.h"
#include "iostream"
using namespace std;

// Default constructor
ba::ba() {
	nGrades = 0;
}

// Constructor
ba::ba(int id, string name, string surname, int nCourses, const vector<int>& grades, int nGrades)
	: student(id, name, surname, nCourses) {
	this->grades = grades;
	this->nGrades = nGrades;
}

// Calculates the average grade of the student
float ba::avgGrade() const {
	int sum = 0;
	for (int i = 0; i < nGrades; i++) {
		sum += grades[i];
	}
	return (float)sum / nGrades;
}

// Returns whether or not the student is entitled to a scholarship
bool ba::entitled() const {
	return nGrades >= 10 && avgGrade() > 95;
}

// Prints the student information
void ba::print() const {
	student::print();
	cout << "grades: ";
	for (int i = 0; i < nGrades; i++) {
		cout << grades[i] << ' ';
	}
	cout << endl;
}