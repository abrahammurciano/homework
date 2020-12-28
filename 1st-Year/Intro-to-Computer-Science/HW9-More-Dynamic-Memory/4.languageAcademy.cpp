/*
 * File Name:				4.languageAcademy.cpp
 * Program Description:		Dictionary system for the Language Academy
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		9
 * Question Number:			4
 * Author:					Abraham Murciano
 *
 * Created on:				Wed Dec 26 2018
 * Last Modified on:		Wed Dec 26 2018
 */

#include <climits>
#include <iostream>
using namespace std;

// Function that resizes a dynamic array from size to newSize
void resize(char*& arr, int size, int newSize) {
	char* newArr = new char[newSize];			// Declare new array
	int n = (size < newSize) ? size : newSize;  // Get smallest of the two sizes
	// Copy n elements from old to new array
	for (int i = 0; i < n; i++) {
		newArr[i] = arr[i];
	}
	delete[] arr;  // Delete old array
	arr = newArr;  // Update pointer of arr
}

// Function that resizes a dynamic array from size to newSize
void resize(char**& arr, int size, int newSize) {
	char** newArr = new char*[newSize];			// Declare new array
	int n = (size < newSize) ? size : newSize;  // Get smallest of the two sizes
	// Copy n elements from old to new array
	for (int i = 0; i < n; i++) {
		newArr[i] = arr[i];
	}
	delete[] arr;  // Delete old array
	arr = newArr;  // Update pointer of arr
}

// Function that reads text from user until a terminator character (space by default) is input. It
// will then return a pointer to a dynamic array containing all the input.
char* getText(char terminator = '\n') {
	int i = 0;					 // Keeps track of index to be input
	int size = 4;				 // Keeps track of size of dynamically allocated array
	char* str = new char[size];  // Create dynamic string

	while (true) {
		// Temporarily store input character (could be whitespace)
		char chtr = terminator;
		cin >> noskipws >> chtr >> skipws;
		if (chtr == terminator) {  // Stop at terminator character
			if (i == 0) {
				continue;  // If first character is a terminator, ignore it
			}
			str[i] = '\0';
			return str;
		} else {
			if (i >= size) {  // Check if array is too small to hold another character
				// Double size of array
				int newSize = size * 2;
				resize(str, size, newSize);
				size = newSize;
			}
			str[i++] = chtr;  // Put input into array
		}
	}
}

// Function that given 2 words, will return 1 if the first word comes first in lexicographic order,
// -1 if it comes second and 0 if they're the same
int strComp(char* str1, char* str2) {

	// Repeat until the end of one string is reached
	int i = 0;
	do {
		if (str1[i] < str2[i]) {
			return 1;  // If str1's ith letter is first, str1 comes first
		} else if (str1[i] > str2[i]) {
			return -1;  // If str2's ith letter is first, str2 comes first
		}
		i++;
	} while (str1[i - 1] != '\0' && str2[i - 1] != '\0');

	return 0;  // If neither 1 or -1 has been returned yet, the words are the same
}

// Function that will return the position of a string if it exists, or -1 if it doesn't.
// If 'strict' is set to false, the next string's position is returned instead of -1.
int search(char** strings, int size, char* str, bool strict = true) {

	// min is the lowest index 'str' could be at
	// max is the highest index 'str' could be at
	int min = 0, max = size - 1;

	while (max >= min) {			// When max and min cross each other, the search is over
		int mid = (min + max) / 2;  // mid is the average of min and max
		if (strComp(str, strings[mid]) == 1) {  // If str is in the first half of array
			max = mid - 1;						// max is 1 less than the word at mid
			// If str is more than the word at max
			if (max < min || strComp(str, strings[max]) == 1) {
				return strict ? -1 : mid;  // There is no result
			}
		} else if (strComp(str, strings[mid]) == -1) {  // If str is in second half of array
			min = mid + 1;								// min is one more than the value at mid
			// If str is less than the word at min
			if (min > max || strComp(str, strings[max]) == 1) {
				return strict ? -1 : min;  // There is no result
			}
		} else {
			// if str isn't more or less than the word at mid, it's the same as the word at mid
			return mid;
		}
	}

	return strict ? -1 : 0;  // Return -1 if strict is true, if not, then return 0
}

// Function that adds a new word to the dictionary
void newStr(char**& words, int& n, char* str) {
	// Find index to put new word
	int pos = search(words, n, str, false);

	if (pos != n && strComp(str, words[pos]) == 0) {
		return;  // If word already exists, stop
	}

	resize(words, n, n + 1);  // Enlarge dictionary by 1

	// Make space for the new word
	for (int i = n; i > pos; i--) {
		words[i] = words[i - 1];
	}

	words[pos] = str;  // Insert new word

	n++;
}

void delStr(char**& words, int& n, char* str) {
	int pos = search(words, n, str);
	if (pos >= 0) {
		for (int i = pos + 1; i < n; i++) {
			words[i - 1] = words[i];
		}
		resize(words, n, n - 1);
		n--;
	}
}

void printAll(char** words, int n) {
	for (int i = 0; i < n; i++) {
		cout << words[i] << ' ';
	}
	cout << endl;
}

char* searchStr(char** words, int n, char* str) {
	int pos = search(words, n, str);
	return (pos >= 0) ? words[pos] : NULL;
}

int findFirst(char** words, int n, char c) {
	// min is the lowest index the first word starting with c could be at
	// max is the highest index the first word starting with c could be at
	int min = 0, max = n - 1;

	while (max >= min) {			// When max and min cross each other, the search is over
		int mid = (min + max) / 2;  // mid is the average of min and max

		// If the first word starting with c is in the first half of array
		if (c < words[mid][0] || (mid > 0 && c == words[mid][0] && c == words[mid - 1][0])) {
			max = mid - 1;  // max is 1 less than the word at mid
			// If the first word starting with c is after the word at max
			if (max < min || c > words[max][0]) {
				return -1;  // No words starting with c
			}
		}

		// If the first word starting with c is in second half of array
		else if (c > words[mid][0]) {
			min = mid + 1;  // min is one more than the value at mid
			// If str is less than the word at min
			if (min > max || c < words[min][0]) {
				return -1;  // No words starting with c
			}
		} else {
			// if str isn't more or less than the word at mid, it's the same as the word at mid
			return mid;
		}
	}

	return -1;  // No words starting with c
}

int findLast(char** words, int n, char c) {
	// min is the lowest index the last word starting with c could be at
	// max is the highest index the last word starting with c could be at
	int min = 0, max = n - 1;

	while (max >= min) {			// When max and min cross each other, the search is over
		int mid = (min + max) / 2;  // mid is the average of min and max

		// If the last word starting with c is in the first half of array
		if (c < words[mid][0]) {
			max = mid - 1;  // max is 1 less than the word at mid
			// If the last word starting with c is after the word at max
			if (max < min || c > words[max][0]) {
				return -1;  // No words starting with c
			}
		}

		// If the last word starting with c is in second half of array
		else if (c > words[mid][0] ||
				 (mid < n - 1 && c == words[mid][0] && c == words[mid + 1][0])) {
			min = mid + 1;  // min is one more than the value at mid
			// If str is less than the word at min
			if (min > max || c < words[min][0]) {
				return -1;  // No words starting with c
			}
		} else {
			// if str isn't more or less than the word at mid, it's the same as the word at mid
			return mid;
		}
	}

	return -1;  // No words starting with c
}

void printChar(char** words, int n, char c) {
	int first = findFirst(words, n, c);
	if (first < 0) {
		return;
	}
	int last = findLast(words, n, c);
	for (int i = first; i <= last; i++) {
		cout << words[i] << ' ' << flush;
	}
	cout << endl;
}

int main() {

	char** lexicon = new char*[0];
	int nWords = 0;
	int choice = 5;

	do {

		cout << "enter 0-5: " << endl;
		cin >> choice;

		if (!cin || choice < 0 || choice > 5) {
			cout << "ERROR" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}

		// Enter a new word
		else if (choice == 0) {
			cout << "enter the word: " << endl;
			char* word = getText();
			newStr(lexicon, nWords, word);
			printAll(lexicon, nWords);
		}

		// Delete a word
		else if (choice == 1) {
			cout << "enter the word to delete: " << endl;
			char* word = getText();
			delStr(lexicon, nWords, word);
			printAll(lexicon, nWords);
		}

		// Search for a word
		else if (choice == 2) {
			cout << "enter the word to search for: " << endl;
			char* word = getText();
			char* p = searchStr(lexicon, nWords, word);
			cout << (p == NULL ? "not " : "") << "found" << endl;
		}

		// Print all words begining with a letter
		else if (choice == 3) {
			cout << "enter the char: " << endl;
			char letter;
			cin >> letter;
			printChar(lexicon, nWords, letter);
		}

		// Print all the words
		else if (choice == 4) {
			printAll(lexicon, nWords);
		}

	} while (choice != 5);

	return 0;
}

/*
========== Sample Run - start ==========
enter 0-5:
0
enter the word:
good
good
enter 0-5:
0
enter the word:
hello
good hello
enter 0-5:
0
enter the word:
shalom
good hello shalom
enter 0-5:
0
enter the word:
today
good hello shalom today
enter 0-5:
2
enter the word to search for:
what
not found
enter 0-5:
2
enter the word to search for:
hello
found
enter 0-5:
1
enter the word to delete:
hello
good shalom today
enter 0-5:
1
enter the word to delete:
toda
good shalom today
enter 0-5:
3
enter the char:
s
shalom
enter 0-5:
0
enter the word:
toda
good shalom toda today
enter 0-5:
3
enter the char:
t
toda today
enter 0-5:
5
=========== Sample Run - end ===========
----------------------------------------
*/