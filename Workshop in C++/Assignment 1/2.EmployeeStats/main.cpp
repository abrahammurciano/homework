/*
 * File Name:				main.cpp
 * Program Description:		Calculates hardest working employee and highest paid employee
 * Course Name:				Workshop in C++
 * Assignment Number:		1
 * Question Number:			2
 * Author:					Abraham Murciano
 */

#include "Employee.h"
#include <iostream>
using namespace std;

int main() {

	// Variables to store user input
	int id;
	string name;
	float wage;
	int hours;
	int overtime;

	// Variable to keep track of highest salary so far
	Employee hiSalary;

	// Variable to keep track of hardest worker so far
	Employee hiHours;

	cout << "enter details, to end enter 0" << endl;  // Prompt for input
	while (true) {									  // Each iteration inputs 1 employee
		cin >> id;
		if (!id) {  // Exit on 0
			break;
		}

		cin >> name >> wage >> hours >> overtime;

		if (id < 0) {  // Id cannot be negative
			cout << "ERROR" << endl;
			continue;
		}

		if (name.length() > 20) {  // Name cannot be more than 20 characters
			cout << "ERROR" << endl;
			continue;
		}

		if (wage < 0) {  // Wage cannot be negative
			cout << "ERROR" << endl;
			continue;
		}

		if (hours < 0) {  // Hours worked cannot be negative
			cout << "ERROR" << endl;
			continue;
		}

		if (overtime < 0) {  // Overtime hours cannot be negative
			cout << "ERROR" << endl;
		}

		Employee employee(id, name, wage, hours, overtime);  // Create employee from input

		if (employee.totalHours() >
			hiHours.totalHours()) {  // Check if new employee is hardest worker so far
			// Update hardest worker
			hiHours = employee;
		}

		if (employee.salary() > hiSalary.salary()) {  // Check if new employee is highest paid
			// Update highest paid employee
			hiSalary = employee;
		}
	}

	// Print employee stats
	cout << "highest salary: " << hiSalary.getId() << ' ' << hiSalary.getName() << endl;
	cout << "hardest worker: " << hiHours.getId() << ' ' << hiHours.getName() << endl;

	return 0;
}

/*
========== Sample Run - start ==========
enter details, to end enter 0
123456789       abraham         50      40      2
135792468       jack          100     30      0
975312468       sarah    30      45      10
0
highest salary: 135792468 jack
hardest worker: 975312468 sarah
=========== Sample Run - end ===========
----------------------------------------
*/