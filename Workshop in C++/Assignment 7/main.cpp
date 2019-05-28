/*
 * File Name:				main.cpp
 * Program Description:		Polymorphism
 * Course Name:				Workshop in C++
 * Assignment Number:		7
 * Author:					Abraham Murciano
 */

#include "ba.h"
#include "ma.h"
#include "phd.h"
#include "student.h"
#include <iostream>
using namespace std;

void printEntitled(student** students, int nStudents) {
	for (int i = 0; i < nStudents; i++) {
		if ((*students[i]).entitled()) {
			(*students[i]).print();
			cout << endl;
		}
	}
}

int main() {

	const int nStudents = 7;

	int* grades[] = {
		new int[3],
		new int[10],
		new int[7],
		new int[7],
	};

	grades[0][0] = 90;
	grades[0][1] = 100;
	grades[0][2] = 90;

	grades[1][0] = 100;
	grades[1][1] = 100;
	grades[1][2] = 90;
	grades[1][3] = 100;
	grades[1][4] = 90;
	grades[1][5] = 100;
	grades[1][6] = 90;
	grades[1][7] = 100;
	grades[1][8] = 90;
	grades[1][9] = 100;

	grades[2][0] = 90;
	grades[2][1] = 100;
	grades[2][2] = 90;
	grades[2][3] = 100;
	grades[2][4] = 90;
	grades[2][5] = 100;
	grades[2][6] = 90;

	grades[3][0] = 90;
	grades[3][1] = 100;
	grades[3][2] = 90;
	grades[3][3] = 100;
	grades[3][4] = 90;
	grades[3][5] = 100;
	grades[3][6] = 90;

	student* students[nStudents] = {
		new ba(123, "abe", "avraham", 3, grades[0], 3),
		new ba(234, "yitzhak", "avrahamson", 10, grades[1], 10),
		new ma(345, "yaacov", "jacobson", 7, grades[2], 7, false),
		new ma(456, "sara", "emanu", 7, grades[3], 7, true),
		new phd(567, "rivka", "imanu", 1, 30),
		new phd(678, "rachel", "jacobs", 2, 20),
		new phd(789, "leah", "jacobs", 2, 30),
	};

	printEntitled(students, nStudents);

	return 0;
}

/*
========== Sample Run - start ==========
ID: 234
first name: yitzhak
last name:  avrahamson
num courses: 10
grades: 100 100 90 100 90 100 90 100 90 100

ID: 456
first name: sara
last name:  emanu
num courses: 7
grades: 90 100 90 100 90 100 90
research: yes

ID: 789
first name: leah
last name:  jacobs
num courses: 2
hours: 30

=========== Sample Run - end ===========
----------------------------------------
*/