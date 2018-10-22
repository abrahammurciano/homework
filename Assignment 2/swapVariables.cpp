
/*
 * File Name:				swapVariables.cpp
 * Program Description:		Program that asks the user to input two numbers, reads them into variables x and y, and prints them.
 *							Then swaps the data, and prints the same message again.
 * Course Name:				Introduction to Computer Science
 * Exercise Number:			2
 * Question Number:			5
 * Author:					Abraham Murciano
 * 
 * Created on:				Oct 14, 2018, 8:29:48 PM
 * Last Modified:			Oct 14, 2018, 9:45:57 PM
 */

//#include <cstdlib>
//#include <cstring>
#include <iostream>
//#include <math.h>
using namespace std;

int main () {

	int x, y; //Two variables input by the user
	int swap; //Temporary variable in order to swap the variables x and y
	cout << "enter two numbers:" << endl;
	cin >> x >> y;
	for (int i = 0; i < 2; i++) { //Do this twice
		cout << "x =" << x << ", y =" << y << endl;
		
		//Swaps variables x and y
		swap = x;
		x = y;
		y = swap;
	}
	
	return 0;
}

/*
enter two numbers:
3
5
x =3, y =5
x =5, y =3
 */