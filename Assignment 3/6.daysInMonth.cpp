/*
 * File Name:				6.daysInMonth.cpp
 * Program Description:		Prints the number of days in a given month
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		3
 * Question Number:			6
 * Author:					Abraham Murciano
 * 
 * Created on:				Mon Oct 22 2018
 * Last Modified on:		Mon Oct 22 2018
 */

#include <iostream>
using namespace std;

int main() {
	
	cout << "enter a number:" << endl;
	int month;
	cin >> month;
	int days = 28 + (month + month/8)%2 + 2%month + 2*(1/month);
	cout << days << " days in the month" << endl;

	return 0;
}

/*
Output
*/