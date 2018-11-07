/*
 * File Name:				flightLandingTime.cpp
 * Program Description:		Program that reads the take-off time of a plane and flight duration then
 * prints landing time.
 * Course Name:				Introduction to Computer Science
 * Exercise Number:			2
 * Question Number:			8
 * Author:					Abraham Murciano
 *
 * Created on:				Oct 14, 2018, 11:23:35 PM
 * Last Modified:			Oct 15, 2018, 12:00:18 AM
 */

#include <complex>
#include <iostream>
using namespace std;

int main() {

	//	Input flight take-off time
	int takeOffHour, takeOffMinute, takeOffSecond;
	cout << "enter flight takeoff:" << endl;
	cin >> takeOffHour >> takeOffMinute >> takeOffSecond;

	//	Input flight duration
	int durationHours, durationMinutes, durationSeconds;
	cout << "enter flight duration:" << endl;
	cin >> durationHours >> durationMinutes >> durationSeconds;

	//	Calculate landing time
	int landingHour, landingMinute, landingSecond;
	landingSecond = takeOffSecond + durationSeconds;
	landingMinute = (takeOffMinute + durationMinutes) + landingSecond / 60;
	landingHour = (takeOffHour + durationHours) + landingMinute / 60;
	landingSecond %= 60;
	landingMinute %= 60;
	landingHour %= 24;

	//	Print the landing time
	cout << "flight arrival is:" << endl;
	cout << landingHour << ":" << landingMinute << ":" << landingSecond << endl;

	return 0;
}

/*
enter flight takeoff:
21
45
33
enter flight duration:
0
55
10
22:40:43
*/