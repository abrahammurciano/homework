/*
 * File Name:				ma.h
 * Program Description:		Polymorphism
 * Course Name:				Workshop in C++
 * Assignment Number:		7
 * Author:					Abraham Murciano
 */

#ifndef ma_h
#define ma_h

#include "ba.h"
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

class ma : public ba {
  protected:
	// Data
	bool research;

  public:
	// Constructors
	ma();
	ma(int id,
	   string name,
	   string surname,
	   int nCourses,
	   const vector<int>& grades,
	   int nGrades,
	   bool research);

	// Methods

	// Operators
	virtual bool entitled() const;
	virtual void print() const;
};

#endif
