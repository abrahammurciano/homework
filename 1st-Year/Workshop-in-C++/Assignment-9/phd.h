/*
 * File Name:				phd.h
 * Program Description:		Standard Library
 * Course Name:				Workshop in C++
 * Assignment Number:		9
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
	float getHours() const;
	virtual bool entitled() const override;
	virtual void print() const override;
	virtual string type() const override;
};

#endif
