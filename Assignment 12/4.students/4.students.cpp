/*
 * File Name:				4.students.cpp
 * Program Description:
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		12
 * Question Number:			4
 * Author:					Abraham Murciano
 *
 * Created on:				Wed Jan 16 2019
 * Last Modified on:		Wed Jan 16 2019
 */

#include <fstream>
#include <iostream>
using namespace std;

struct student {
	int id;
	char name[25];
	int mark;
};

// Function that reads in all the data from path and inserts it into an array, returning the number
// of elements inserted
int read(student students[], int N, const char path[]) {
	ifstream file(path);
	int i = 0;
	while (!file.eof() && i < N) {
		file >> students[i].id;
		file >> students[i].name;
		file >> students[i].mark;
		i++;
	}
	return i;
}

// Function that prints out all the data in the array students
void print(const student students[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "name: " << students[i].name;
		cout << " id: " << students[i].id;
		cout << " mark: " << students[i].mark;
		cout << endl;
	}
}

int main() {

	// Declare an array of students
	const int N = 50;
	student students[N];

	// Read in the path from the user
	cout << "Enter the path of the file containing the students:" << endl;
	char path[25];
	cin >> path;

	// Fill the array with the file then print all the data
	int n = read(students, N, path);
	print(students, n);

	return 0;
}