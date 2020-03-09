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
#include <vector>
using namespace std;

void printEntitled(const vector<student*>& students, int nStudents) {
	for (int i = 0; i < nStudents; i++) {
		if ((*students[i]).entitled()) {
			(*students[i]).print();
			cout << endl;
		}
	}
}

int main() {

	const int nStudents = 7;

	vector<student*> students{
		new ba(123, "abe", "avraham", 3, vector<int>{90, 100, 90}, 3),
		new ba(234,
			   "yitzhak",
			   "avrahamson",
			   10,
			   vector<int>{100, 100, 90, 100, 90, 100, 90, 100, 90, 100},
			   10),
		new ma(345, "yaacov", "jacobson", 7, vector<int>{90, 100, 90, 100, 90, 100, 90}, 7, false),
		new ma(456, "sara", "emanu", 7, vector<int>{90, 100, 90, 100, 90, 100, 90}, 7, true),
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