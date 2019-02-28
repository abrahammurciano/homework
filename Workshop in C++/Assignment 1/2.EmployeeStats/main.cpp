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

	// Variables to keep track of highest salary so far
	float hiSalary = 0;
	int hiSalaryId;
	string hiSalaryName;

	// Variables to keep track of hardest worker so far
	int hiHours = 0;
	int hiHoursId;
	string hiHoursName;

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

		if (employee.totalHours() > hiHours) {  // Check if new employee is hardest worker so far
			// Update hardest worker
			hiHours = employee.totalHours();
			hiHoursId = employee.getId();
			hiHoursName = employee.getName();
		}

		if (employee.salary() > hiSalary) {  // Check if new employee is highest paid
			// Update highest paid employee
			hiSalary = employee.salary();
			hiSalaryId = employee.getId();
			hiSalaryName = employee.getName();
		}
	}

	// Print employee stats
	cout << "highest salary: " << hiSalaryId << ' ' << hiSalaryName << endl;
	cout << "hardest worker: " << hiHoursId << ' ' << hiHoursName << endl;

	return 0;
}

/*
========== Sample Run - start ==========

=========== Sample Run - end ===========
----------------------------------------
*/