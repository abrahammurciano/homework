/*
 * File Name:				student.h
 * Program Description:		Polymorphism
 * Course Name:				Workshop in C++
 * Assignment Number:		7
 * Author:					Abraham Murciano
 */

#ifndef student_h
#define student_h

#include <stdlib.h>
#include <string>
using namespace std;

class student {
  protected:
	// Data
	int id;
	string name;
	string surname;
	int nCourses;

  public:
	// Constructors
	student();
	student(int id, string name, string surname, int nCourses);
	virtual ~student() = 0;

	// Methods
	virtual bool entitled() const = 0;
	virtual void print() const;
};

#endif
