/*
 * File Name:				ba.h
 * Program Description:		Standard Library
 * Course Name:				Workshop in C++
 * Assignment Number:		9
 * Author:					Abraham Murciano
 */

#ifndef ba_h
#define ba_h

#include "student.h"
#include <stdlib.h>
#include <vector>
using namespace std;

class ba : public student {
  protected:
	// Data
	vector<int> grades;

  public:
	// Constructors
	ba();
	ba(int id, string name, string surname, int nCourses, vector<int> grades);

	// Methods
	float avgGrade() const;
	virtual bool entitled() const override;
	virtual void print() const override;
	virtual string type() const override;
};

#endif
