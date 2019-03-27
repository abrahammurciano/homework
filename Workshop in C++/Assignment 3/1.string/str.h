/*
 * File Name:				str.h
 * Program Description:		Implementation of a string class
 * Course Name:				Workshop in C++
 * Assignment Number:		3
 * Question Number:			1
 * Author:					Abraham Murciano
 */

#ifndef str_h
#define str_h

//#include <...>
// using namespace std;

class str {
  private:
	char* array;
	int capacity;
	int len;
	void extend(const int l);

  public:
	// Constructors
	str(const char* s = "");
	str(const char c, const int l = 1);
	str(const str& s);

	// Methods
	int length() const;
	int size() const;
	void print(const bool newLine = false) const;
	void input(const str prompt = "", const char delim = '\n');
	str& insert(const str& s, int i);
	str lower() const;
	str upper() const;

	// Operators
	char& operator[](const int i) const;

	str& operator=(const str& s);
	str& operator+=(const str& s);
	str operator+(const str& s) const;

	bool operator==(const str& s) const;
	bool operator!=(const str& s) const;
	bool operator<(const str& s) const;
	bool operator<=(const str& s) const;
	bool operator>(const str& s) const;
	bool operator>=(const str& s) const;
};

#endif
