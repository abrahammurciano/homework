/*
 * File Name:				1.grades.cpp
 * Program Description:		This program takes 2 files (names and grades) and creates a 3rd with
 * both the names and grades together
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		12
 * Question Number:			1
 * Author:					Abraham Murciano
 *
 * Created on:				Tue Jan 15 2019
 * Last Modified on:		Tue Jan 15 2019
 */

#include <fstream>
#include <iostream>
using namespace std;

int main() {

	ifstream names_f("names.txt");	// File to read names from
	ifstream grades_f("grades.txt");  // File to read grades from
	ofstream roster_f("roster.txt");  // File to write names and grades to

	char name[50];  // String to store each name
	int grade;		// Integer to store each grade

	// Until one of the files is comletely read
	while (!names_f.eof() && !grades_f.eof()) {
		names_f >> name;						   // Read the next name into name
		grades_f >> grade;						   // Read the next name into grade
		roster_f << name << ' ' << grade << endl;  // Write name and grade to roster
	}

	// If names isn't yet finished
	if (!names_f.eof()) {
		cout << "finished reading grades before names" << endl;
		while (!names_f.eof()) {  // Read the rest of names
			names_f >> name;
			cout << name << endl;  // And write it to the console
		}
	}

	// If grades isn't yet finished
	if (!grades_f.eof()) {
		cout << "finished reading names before grades" << endl;
		while (!grades_f.eof()) {  // Read the rest of grades
			grades_f >> grade;
			cout << grade << endl;  // And write it to the console
		}
	}

	names_f.close();
	grades_f.close();
	roster_f.close();

	return 0;
}