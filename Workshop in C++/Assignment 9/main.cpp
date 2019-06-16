/*
 * File Name:				main.cpp
 * Program Description:		Standard Library
 * Course Name:				Workshop in C++
 * Assignment Number:		9
 * Author:					Abraham Murciano
 */

#include "ba.h"
#include "ma.h"
#include "phd.h"
#include "student.h"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void add(vector<student*>& students) {
	cout << "enter 1 to add a BA student" << endl;
	cout << "enter 2 to add a MA student" << endl;
	cout << "enter 3 to add a PHD student" << endl;
	int choice;
	cin >> choice;
	cout << "enter id, first name, last name and number Of Courses" << endl;
	int id, nCourses;
	string name, surname;
	cin >> id >> name >> surname >> nCourses;
	try {
		if (choice == 1 || choice == 2) {
			cout << "enter " << nCourses << " grades" << endl;
			vector<int> grades(nCourses);
			for (auto grade = grades.begin(); grade != grades.end(); grade++) {
				cin >> *grade;
			}
			if (choice == 1) {
				students.push_back(new ba(id, name, surname, nCourses, grades));
			} else {
				cout << "enter 1 if the student does research and 0 if not" << endl;
				bool research;
				cin >> research;
				students.push_back(new ma(id, name, surname, nCourses, grades, research));
			}
		} else if (choice == 3) {
			cout << "enter number of research hours" << endl;
			int hours;
			cin >> hours;
			students.push_back(new phd(id, name, surname, nCourses, hours));
		} else {
			throw string("Error: Must enter 1, 2 or 3 for student type.");
		}
	} catch (string e) {
		cout << e << endl;
		add(students);
	}
}

void printEntitled(const vector<student*>& students) {
	for (auto s = students.begin(); s != students.end(); s++) {
		if ((*s)->entitled()) {
			(*s)->print();
			cout << endl;
		}
	}
}

phd* mostReseachHours(vector<student*> students) {
	phd* most = NULL;
	for (auto s = students.begin(); s != students.end(); s++) {
		if ((*s)->type() == "PhD") {
			if (!most || ((phd*)*s)->getHours() > most->getHours()) {
				most = (phd*)*s;
			}
		}
	}
	return most;
}

int main() {

	vector<student*> students;

	int choice;
	do {
		try {
			cout << "enter 0-7" << endl;
			cin >> choice;
			if (choice == 1) {  // add new student
				add(students);
			} else if (choice == 2) {  // print details of all students eligible for a scholarship
				printEntitled(students);
			} else if (choice == 3) {  // print name of PhD student with most research hours
				phd* student = mostReseachHours(students);
				cout << "PHD studnet with most research hours: " << student->getName() << ' '
					 << student->getSurname() << endl;
			} else if (choice == 4) {  // print number of BA students entitled to a scholarship
				cout << "#BA studnets for milga: ";
				cout << count_if(students.begin(), students.end(), [](student* s) -> bool {
					return s->type() == "BA" && s->entitled();
				});
				cout << endl;
			} else if (choice == 5) {  // print names of all MA students that don't do research
				cout << "list of no research MA students: " << endl;
				cout << for_each(students.begin(), students.end(), [](student* s) {
					cout << (s->type() == "MA" && !((ma*)s)->getResearch()
								 ? s->getName() + ' ' + s->getSurname() + '\n'
								 : "");
				});
			} else if (choice == 6) {  // print message if there are students who takes > 15 courses
				if (count_if(students.begin(), students.end(), [](student* s) {
						return s->getNCourses() > 15;
					}) > 0) {
					cout << "there is a student that takes more than 15 courses" << endl;
				} else {
					cout << "no student takes more than 15 courses" << endl;
				}
			} else if (choice == 7) {  // remove all PhD students that don't take any courses
				students.erase(remove_if(students.begin(),
										 students.end(),
										 [](student* s) {
											 return s->type() == "PhD" && s->getNCourses() == 0;
										 }),
							   students.end());
				for_each(students.begin(), students.end(), [](student* s) { s->print(); });
			} else if (choice != 0) {  // invalid choice
				throw string("Error: Invalid choice.");
			}
		} catch (string e) {
			cout << e << endl;
			continue;
		}
	} while (choice != 0);

	return 0;
}