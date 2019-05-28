/*
 * File Name:				ba.h
 * Program Description:		Polymorphism
 * Course Name:				Workshop in C++
 * Assignment Number:		7
 * Author:					Abraham Murciano
 */

#ifndef ba_h
#define ba_h

#include "student.h"
#include <stdlib.h>
using namespace std;

class ba : public student {
  protected:
	// Data
	int* grades;
	int nGrades;

  public:
	// Constructors
	ba();
	ba(int id, string name, string surname, int nCourses, int* grades, int nGrades);
	~ba();

	// Methods
	float avgGrade() const;
	virtual bool entitled() const;
	virtual void print() const;
};

#endif
