/*
 * File Name:				student.h
 * Program Description:		Files - Students' summer classes system
 * Course Name:				Workshop in C++
 * Assignment Number:		10
 * Author:					Abraham Murciano
 */

#ifndef student_h
#define student_h

#include <iostream>
#include <stdlib.h>
using namespace std;

class student {
  private:
	// Data
	int id;
	char name[21];
	char surname[21];
	bool courses[5];

  public:
	// Constructors
	student();
	student(int id, const char* name, const char* surname, bool* courses);

	// Methods
	int getId() const;
	string getName() const;
	bool getCourse(int i) const;
	void setId(int id);
	void setName(const char* name, const char* surname);
	void setCourse(int i, bool val);
	void print() const;

	// Operators
};

#endif
