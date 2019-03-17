/*
 * File Name:				vec.h
 * Program Description:		Implementation of a vector class
 * Course Name:				Workshop in C++
 * Assignment Number:		3
 * Question Number:			2
 * Author:					Abraham Murciano
 */

#ifndef vec_h
#define vec_h

//#include <...>
// using namespace std;

class vec {
  private:
	int* data;
	int capacity;
	int size;

  public:
	vec(const int n = 10);
	vec(const vec& v);
	~vec();

	int getCapacity();
	int getSize();

	void clear();
	void insert(const int n);
	void print();
	void delLast();

	vec& operator=(const vec& v);
	bool operator==(const vec& v) const;
	int& operator[](const int i) const;
	int operator*(const vec& v) const;
	vec operator+(const vec& v) const;
};

#endif
