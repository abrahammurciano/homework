/*
 * File Name:				student.h
 * Program Description:		Standard Library
 * Course Name:				Workshop in C++
 * Assignment Number:		9
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
	string getName() const;
	string getSurname() const;
	int getNCourses() const;
	virtual bool entitled() const = 0;
	virtual void print() const;
	virtual string type() const = 0;
};

#endif
