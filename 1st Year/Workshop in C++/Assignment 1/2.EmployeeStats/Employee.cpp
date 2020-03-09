/*
 * File Name:				Employee.cpp
 * Program Description:		Calculates hardest working employee and highest paid employee
 * Course Name:				Workshop in C++
 * Assignment Number:		1
 * Question Number:			2
 * Author:					Abraham Murciano
 */

#ifndef Employee_cpp
#define Employee_cpp

#include "Employee.h"
using namespace std;

// Constructor
Employee::Employee() {
	id = 0;
	name = "";
	wage = 0;
	hours = 0;
	overtime = 0;
}

Employee::Employee(int _id, string _name, float _wage, int _hours, int _overtime) {
	id = _id;
	name = _name;
	wage = _wage;
	hours = _hours;
	overtime = _overtime;
}

int Employee::getId() {
	return id;
}

string Employee::getName() {
	return name;
}

float Employee::getWage() {
	return wage;
}

int Employee::getHours() {
	return hours;
}

int Employee::getOvertime() {
	return overtime;
}

void Employee::setId(int _id) {
	id = _id;
}

void Employee::setName(string _name) {
	name = _name;
}

void Employee::setWage(float _wage) {
	wage = _wage;
}

void Employee::setHours(int _hours) {
	hours = _hours;
}

void Employee::setOvertime(int _overtime) {
	overtime = _overtime;
}

// Calculate the total number of hours worked
int Employee::totalHours() {
	return hours + overtime;
}

// Calculate salary of employee
float Employee::salary() {
	return wage * (hours + overtime * 1.5);
}

#endif