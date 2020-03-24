/*
 * File Name:				ma.h
 * Program Description:		Standard Library
 * Course Name:				Workshop in C++
 * Assignment Number:		9
 * Author:					Abraham Murciano
 */

#ifndef ma_h
#define ma_h

#include "ba.h"
#include <stdlib.h>
#include <string>
using namespace std;

class ma : public ba {
  protected:
	// Data
	bool research;

  public:
	// Constructors
	ma();
	ma(int id, string name, string surname, int nCourses, vector<int> grades, bool research);

	// Methods
	bool getResearch() const;
	virtual bool entitled() const override;
	virtual void print() const override;
	virtual string type() const override;
};

#endif
