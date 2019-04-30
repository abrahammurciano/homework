/*
 * File Name:				5.nQueens.cpp
 * Program Description:		Prints out a chess board of size n by n with n queens in a way that no
 * queen is being threatened by another
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		11
 * Question Number:			5
 * Author:					Abraham Murciano
 *
 * Created on:				Tue Jan 08 2019
 * Last Modified on:		Sun Jan 13 2019
 */

#include <iostream>
using namespace std;

struct point {
	int x;
	int y;
};

// Function that returns true if there is a queen on point (x,y)
bool isQueen(int n, point queens[], int x, int y) {
	for (int i = 0; i < n; i++) {
		if (queens[i].x == x && queens[i].y == y) {
			return true;
		}
	}
	return false;
}

// Function that places queens on the board such that no queen threatens another
bool placeQueens(int n, point queens[], int row = 0) {
	if (row >= n) {
		return true;  // If the whole board has been filled, the problem was solved
	}

	bool safe;
	// Loop through all squares on row to check if queen can be placed there
	for (int col = 0; col < n; col++) {
		safe = true;
		// Check if there are any queens on the same column
		for (int i = 0; i < row; i++) {
			if (queens[i].x == col) {
				safe = false;
				break;
			}
		}

		if (!safe) {
			continue;
		}

		// Check if there are any queens in the diagonals
		for (int y = row - 1, x1 = col - 1, x2 = col + 1; y >= 0; y--) {
			for (int i = 0; i < row; i++) {
				if (queens[i].y == y && (queens[i].x == x1 || queens[i].x == x2)) {
					safe = false;
					break;
				}
			}
			if (!safe) {
				break;
			}
			x1--;
			x2++;
		}

		if (safe) {
			// Place the queen on the safe spot
			queens[row].x = col;
			queens[row].y = row;

			// Proceed onto next row
			if (placeQueens(n, queens, row + 1)) {
				return true;
			} else {
				continue;
			}
		}
	}
	return false;
}

// Function that prints the board of queens
void printBoard(int n, point queens[]) {
	for (int i = 0; i < n; i++) {
		cout << " _";
	}
	cout << endl;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cout << '|' << (isQueen(n, queens, x, y) ? 'Q' : '_');
		}
		cout << '|' << endl;
	}
	cout << endl;
}

int main() {
	int n;
	while (true) {
		cout << "enter a number:" << endl;
		cin >> n;
		if (n > 0) {
			break;
		}
		cout << "ERROR" << endl;
	}

	// Array of points where the position of the queens will be stored
	point* queens = new point[n];

	if (placeQueens(n, queens)) {
		printBoard(n, queens);
	} else {
		cout << "This problem cannot be solved when n = " << n << endl;
	}

	return 0;
}

/*
========== Sample Run - start ==========
enter a number:
3
This problem cannot be solved when n = 3
=========== Sample Run - end ===========
----------------------------------------
========== Sample Run - start ==========
enter a number:
4
 _ _ _ _
|_|Q|_|_|
|_|_|_|Q|
|Q|_|_|_|
|_|_|Q|_|
=========== Sample Run - end ===========
----------------------------------------
========== Sample Run - start ==========
enter a number:
22
 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
|Q|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|
|_|_|Q|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|Q|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|
|_|Q|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|
|_|_|_|Q|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|Q|_|_|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|_|_|_|Q|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|Q|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|Q|_|_|
|_|_|_|_|_|_|_|_|_|_|_|_|Q|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|Q|_|_|_|
|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|Q|
|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|Q|_|_|_|_|
|_|_|_|_|_|_|_|Q|_|_|_|_|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|Q|_|
|_|_|_|_|_|_|_|_|_|_|_|Q|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|Q|_|_|_|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|Q|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|Q|_|_|_|_|_|_|
|_|_|_|_|_|_|Q|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|Q|_|_|_|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|_|_|_|_|_|_|Q|_|_|_|_|_|_|_|
=========== Sample Run - end ===========
----------------------------------------
*/