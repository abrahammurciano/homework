/*
 * File Name:				Employee.h
 * Program Description:		Calculates hardest working employee and highest paid employee
 * Course Name:				Workshop in C++
 * Assignment Number:		1
 * Question Number:			2
 * Author:					Abraham Murciano
 */

#ifndef Employee_h
#define Employee_h

#include <string>
using namespace std;

class Employee {
  private:
	int id;
	string name;
	float wage;
	int hours;
	int overtime;

  public:
	Employee();
	Employee(int _id, string _name, float _wage, int _hours, int _overtime);
	int getId();
	string getName();
	float getWage();
	int getHours();
	int getOvertime();
	void setId(int _id);
	void setName(string _name);
	void setWage(float _wage);
	void setHours(int _hours);
	void setOvertime(int _overtime);
	int totalHours();
	float salary();
};

#endif
