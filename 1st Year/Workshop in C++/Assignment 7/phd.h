/*
 * File Name:				phd.h
 * Program Description:		Polymorphism
 * Course Name:				Workshop in C++
 * Assignment Number:		7
 * Author:					Abraham Murciano
 */

#ifndef phd_h
#define phd_h

#include "student.h"
#include <stdlib.h>
using namespace std;

class phd : public student {
  protected:
	// Data
	float hours;

  public:
	// Constructors
	phd();
	phd(int id, string name, string surname, int nCourses, float hours);

	// Methods
	virtual bool entitled() const;
	virtual void print() const;
};

#endif
