
/*
 * File Name:				formula.cpp
 * Program Description:		Program that outputs the result of a formula
 * Course Name:				Introduction to Computer Science
 * Exercise Number:			2
 * Question Number:			4
 * Author:					Abraham Murciano
 * 
 * Created on:				Oct 14, 2018, 6:59:07 PM
 * Last Modified on:			----
 */

//#include <cstdlib>
//#include <cstring>
#include <iostream>
//#include <math.h>
using namespace std;

int main () {

	int input1, input2;	//Two variables to be input by the user
	float result;	//A variable to store the result of the formula
	cout << "enter two numbers:" << endl;
	cin >> input1 >> input2;
	result = ((float)input1*5 + 3)/((float)input2*6 + 2);
	cout << "c=" << result;

	return 0;
}

/*
enter two numbers:
2
0
c=6.5
 */