/*
 * File Name:				main.cpp
 * Program Description:		Files - Students' summer classes system
 * Course Name:				Workshop in C++
 * Assignment Number:		10
 * Author:					Abraham Murciano
 */

#include "student.h"
#include <fstream>
#include <iostream>
using namespace std;

void makeFile(fstream& students) {
	student temp;
	for (int i = 0; i < 100; i++) {
		students.write((char*)&temp, sizeof(student));
	}
}

student readStudent(fstream& students, int id) {
	student temp;
	if (id) {
		streamsize size = sizeof(student);
		streampos pos = (id - 1) * size;
		students.seekg(pos);
		students.read((char*)&temp, size);
	}
	return temp;
}

void writeStudent(fstream& students, const student& s) {
	if (s.getId()) {
		streamsize size = sizeof(student);
		streampos pos = (s.getId() - 1) * size;
		students.seekp(pos);
		students.write((char*)&s, size);
	}
}

void inputCourses(student& s) {
	for (int i = 0; i < 5; i++) {
		cout << "Did " << s.getName() << " sign up for course " << i + 1 << "? [Y/N]" << endl
			 << "> ";
		char choice;
		cin >> choice;
		s.setCourse(i, choice == 'Y' || choice == 'y');
	}
}

bool studentExists(fstream& students, int id) {
	student temp = readStudent(students, id);
	return temp.getId() == id;
}

void addStudent(fstream& students) {
	student temp;

	int id;
	cout << "Enter student ID:" << endl << "> ";
	cin >> id;

	if (!studentExists(students, id)) {
		temp.setId(id);

		char name[20], surname[20];
		cout << "Enter student name and surname" << endl << "> ";
		cin >> name >> surname;
		temp.setName(name, surname);

		inputCourses(temp);
		writeStudent(students, temp);
	} else {
		throw string("Error: Student with given ID already exists.");
	}
}

void deleteStudent(fstream& students, int id) {
	streamsize size = sizeof(student);
	streampos pos = (id - 1) * size;
	students.seekp(pos);
	id = 0;
	students.write((char*)&id, sizeof(id));
}

void editStudent(fstream& students, int id) {
	student temp = readStudent(students, id);
	if (temp.getId() == 0) {
		throw string("Error: Student does not exist.");
	}
	inputCourses(temp);
	writeStudent(students, temp);
}

bool registered(fstream& students, int id, int course) {
	student temp = readStudent(students, id);

	if (temp.getId() == 0) {
		throw string("Error: Student does not exist");
	}

	return temp.getCourse(course - 1);
}

void printStudents(fstream& students) {
	for (int i = 1; i <= 100; i++) {
		readStudent(students, i).print();
	}
}

void printStudentsInCourse(fstream& students, int course) {
	for (int i = 1; i <= 100; i++) {
		student temp = readStudent(students, i);
		if (temp.getId() != 0 && temp.getCourse(course - 1)) {
			cout << temp.getName() << endl;
		}
	}
}

int menu() {
	cout << endl;
	cout << "Choose an option" << endl;
	cout << "0 - Exit" << endl;
	cout << "1 - Insert a student" << endl;
	cout << "2 - Remove a student" << endl;
	cout << "3 - Edit a student's courses" << endl;
	cout << "4 - Check a student's registration to a course" << endl;
	cout << "5 - Print all student data" << endl;
	cout << "6 - Print all students in a given course" << endl;
	cout << "> ";
	int choice;
	cin >> choice;
	return choice;
}

int main() {

	fstream students;
	students.open("students.bin", ios::in | ios::out | ios::binary | ios::trunc);
	makeFile(students);

	int choice;
	while (true) {
		try {
			choice = menu();
			// Insert a student
			if (choice == 1) {
				addStudent(students);
			}

			// Remove a student
			else if (choice == 2) {
				cout << "Enter ID of student to delete" << endl << "> ";
				int id;
				cin >> id;
				deleteStudent(students, id);
			}

			// Edit a student's courses
			else if (choice == 3) {
				cout << "Enter ID of student to edit" << endl << "> ";
				int id;
				cin >> id;
				editStudent(students, id);
			}

			// Check a student's registration to a course
			else if (choice == 4) {
				cout << "Enter student ID to check" << endl << "> ";
				int id;
				cin >> id;

				cout << "Enter course number (1-5)" << endl << "> ";
				int course;
				cin >> course;

				cout << (registered(students, id, course) ? "R" : "Not r") << "egistered" << endl;
			}

			// Print all student data
			else if (choice == 5) {
				printStudents(students);
			}

			// Print all students in a given course
			else if (choice == 6) {
				cout << "Enter course number (1-5)" << endl << "> ";
				int course;
				cin >> course;

				printStudentsInCourse(students, course);
			}

			// Exit
			else if (choice == 0) {
				break;
			}

			// Error
			else {
				throw string("Error: Invalid option (0-6).");
			}
		} catch (string e) {
			cout << e << endl;
		}
	}

	students.close();
	return 0;
}

/*
========== Sample Run - start ==========
Choose an option
0 - Exit
1 - Insert a student
2 - Remove a student
3 - Edit a student's courses
4 - Check a student's registration to a course
5 - Print all student data
6 - Print all students in a given course
> 1
Enter student ID:
> 10
Enter student name and surname
> Johnny Depp
Did Johnny Depp sign up for course 1? [Y/N]
> y
Did Johnny Depp sign up for course 2? [Y/N]
> n
Did Johnny Depp sign up for course 3? [Y/N]
> n
Did Johnny Depp sign up for course 4? [Y/N]
> y
Did Johnny Depp sign up for course 5? [Y/N]
> y

Choose an option
0 - Exit
1 - Insert a student
2 - Remove a student
3 - Edit a student's courses
4 - Check a student's registration to a course
5 - Print all student data
6 - Print all students in a given course
> 1
Enter student ID:
> 5
Enter student name and surname
> Ralph Smith
Did Ralph Smith sign up for course 1? [Y/N]
> n
Did Ralph Smith sign up for course 2? [Y/N]
> y
Did Ralph Smith sign up for course 3? [Y/N]
> y
Did Ralph Smith sign up for course 4? [Y/N]
> n
Did Ralph Smith sign up for course 5? [Y/N]
> y

Choose an option
0 - Exit
1 - Insert a student
2 - Remove a student
3 - Edit a student's courses
4 - Check a student's registration to a course
5 - Print all student data
6 - Print all students in a given course
> 1
Enter student ID:
> 20
Enter student name and surname
> Samwise Gamgee
Did Samwise Gamgee sign up for course 1? [Y/N]
> n
Did Samwise Gamgee sign up for course 2? [Y/N]
> y
Did Samwise Gamgee sign up for course 3? [Y/N]
> y
Did Samwise Gamgee sign up for course 4? [Y/N]
> y
Did Samwise Gamgee sign up for course 5? [Y/N]
> y

Choose an option
0 - Exit
1 - Insert a student
2 - Remove a student
3 - Edit a student's courses
4 - Check a student's registration to a course
5 - Print all student data
6 - Print all students in a given course
> 1
Enter student ID:
> 20
Error: Student with given ID already exists.

Choose an option
0 - Exit
1 - Insert a student
2 - Remove a student
3 - Edit a student's courses
4 - Check a student's registration to a course
5 - Print all student data
6 - Print all students in a given course
> 5
Ralph Smith             N Y Y N Y
Johnny Depp             Y N N Y Y
Samwise Gamgee          N Y Y Y Y

Choose an option
0 - Exit
1 - Insert a student
2 - Remove a student
3 - Edit a student's courses
4 - Check a student's registration to a course
5 - Print all student data
6 - Print all students in a given course
> 4
Enter student ID to check
> 5
Enter course number (1-5)
> 4
Not registered

Choose an option
0 - Exit
1 - Insert a student
2 - Remove a student
3 - Edit a student's courses
4 - Check a student's registration to a course
5 - Print all student data
6 - Print all students in a given course
> 4
Enter student ID to check
> 10
Enter course number (1-5)
> 4
Registered

Choose an option
0 - Exit
1 - Insert a student
2 - Remove a student
3 - Edit a student's courses
4 - Check a student's registration to a course
5 - Print all student data
6 - Print all students in a given course
> 4
Enter student ID to check
> 20
Enter course number (1-5)
> 4
Registered

Choose an option
0 - Exit
1 - Insert a student
2 - Remove a student
3 - Edit a student's courses
4 - Check a student's registration to a course
5 - Print all student data
6 - Print all students in a given course
> 6
Enter course number (1-5)
> 4
Johnny Depp
Samwise Gamgee

Choose an option
0 - Exit
1 - Insert a student
2 - Remove a student
3 - Edit a student's courses
4 - Check a student's registration to a course
5 - Print all student data
6 - Print all students in a given course
> 3
Enter ID of student to edit
> 5
Did Ralph Smith sign up for course 1? [Y/N]
> n
Did Ralph Smith sign up for course 2? [Y/N]
> y
Did Ralph Smith sign up for course 3? [Y/N]
> y
Did Ralph Smith sign up for course 4? [Y/N]
> y
Did Ralph Smith sign up for course 5? [Y/N]
> y

Choose an option
0 - Exit
1 - Insert a student
2 - Remove a student
3 - Edit a student's courses
4 - Check a student's registration to a course
5 - Print all student data
6 - Print all students in a given course
> 5
Ralph Smith             N Y Y Y Y
Johnny Depp             Y N N Y Y
Samwise Gamgee          N Y Y Y Y

Choose an option
0 - Exit
1 - Insert a student
2 - Remove a student
3 - Edit a student's courses
4 - Check a student's registration to a course
5 - Print all student data
6 - Print all students in a given course
> 6
Enter course number (1-5)
> 4
Ralph Smith
Johnny Depp
Samwise Gamgee

Choose an option
0 - Exit
1 - Insert a student
2 - Remove a student
3 - Edit a student's courses
4 - Check a student's registration to a course
5 - Print all student data
6 - Print all students in a given course
> 2
Enter ID of student to delete
> 5

Choose an option
0 - Exit
1 - Insert a student
2 - Remove a student
3 - Edit a student's courses
4 - Check a student's registration to a course
5 - Print all student data
6 - Print all students in a given course
> 5
Johnny Depp             Y N N Y Y
Samwise Gamgee          N Y Y Y Y

Choose an option
0 - Exit
1 - Insert a student
2 - Remove a student
3 - Edit a student's courses
4 - Check a student's registration to a course
5 - Print all student data
6 - Print all students in a given course
> 2
Enter ID of student to delete
> 10

Choose an option
0 - Exit
1 - Insert a student
2 - Remove a student
3 - Edit a student's courses
4 - Check a student's registration to a course
5 - Print all student data
6 - Print all students in a given course
> 2
Enter ID of student to delete
> 20

Choose an option
0 - Exit
1 - Insert a student
2 - Remove a student
3 - Edit a student's courses
4 - Check a student's registration to a course
5 - Print all student data
6 - Print all students in a given course
> 5

Choose an option
0 - Exit
1 - Insert a student
2 - Remove a student
3 - Edit a student's courses
4 - Check a student's registration to a course
5 - Print all student data
6 - Print all students in a given course
> 0
=========== Sample Run - end ===========
----------------------------------------
*/