/*
 * File Name:				3.gradesAverage.cpp
 * Program Description:		Reads 4 files containing grades and determines the one with the highest
 * average
 * Course Name:				Introduction to Computer Science Assignment
 * Number:					12
 * Question Number:			3
 * Author:					Abraham Murciano
 *
 * Created on:				Wed Jan 16 2019
 * Last Modified on:		Wed Jan 16 2019
 */

#include <fstream>
#include <iostream>
using namespace std;

// Object to hold a file of grades
struct gradesFile {
	int id;
	fstream stream;
	float avg;  // Average grade
};

// Function that calculates the average grade of the grades in file
float gradeAvg(fstream& file) {
	int sum = 0;
	int count = 0;
	while (!file.eof()) {
		int grade;
		file >> grade;  // Read in the next grade from file
		sum += grade;   // Add it to sum
		count++;
	}
	return (float)sum / count;  // Return average
}

// Function that reads a file and returns a file object with the info about the file
gradesFile read(int id, const char path[]) {
	gradesFile f;
	f.id = id;
	f.stream.open(path, ios::in);  // Open the file
	f.avg = gradeAvg(f.stream);	// Work out the average
	f.stream.close();
	return f;  // Return the object
}

int main() {

	const int nFiles = 4;

	// Array of file objets
	gradesFile files[nFiles] = {
		read(1, "grades1.txt"),
		read(2, "grades2.txt"),
		read(3, "grades3.txt"),
		read(4, "grades4.txt"),
	};

	// Work out which has the highest average
	int highestIndex = 0;
	for (int i = 1; i < nFiles; i++) {
		// If the ith file has a higher average, overwrite highest index with i
		if (files[i].avg > files[highestIndex].avg) {
			highestIndex = i;
		}
	}

	cout << "highest average found in file " << files[highestIndex].id << endl;

	return 0;
}