/*
 * File Name:				4.sortWords.cpp
 * Program Description:		Takes 10 5-letter words and sorts them in lexicographic order
 * Course Name:				Introduction to Computer Science
 * Assignment Number:		7
 * Question Number:			4
 * Author:					Abraham Murciano
 *
 * Created on:				Thu Nov 22 2018
 * Last Modified on:		Sat Nov 25 2018
 */

#include <iostream>
using namespace std;

const int n = 10;  // Number of words
const int l = 5;   // Length of words

// Function that given 2 words and their lengths, will return 1 if the first word comes first in
// lexicographic order, -1 if it comes second and 0 if they're the same
int compareWords(char word1[], int l1, char word2[], int l2) {

	// Repeat l1 or l2 times, depending on which is smaller
	for (int i = 0; i < l1 && i < l2; i++) {
		if (word1[i] < word2[i]) {
			return 1;  // If word1's ith letter is first, word1 comes first
		} else if (word1[i] > word2[i]) {
			return -1;  // If word2's ith letter is first, word2 comes first
		}
	}

	// If program reaches here, one of the words starts with the other word (eg foo and foobar)
	// In that case the shorter word comes first
	if (l1 > l2) {
		return 1;
	} else if (l1 < l2) {
		return -1;
	}

	return 0;  // If neither 1 or -1 has been returned yet, the words are the same
}

// Function that swaps two arrays of characters of the same length
void swapArrays(char arr1[], char arr2[], int length) {
	for (int i = 0; i < length; i++) {
		char temp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = temp;
	}
}

// Function that sorts n l-letter words given as a multidimensional array of chars using bubble sort
void bubbleSortWords(char words[][l], int n) {
	for (int i = n; i > 0; i--) {
		for (int j = 1; j < i; j++) {
			if (compareWords(words[j - 1], l, words[j], l) == -1) {  // If words[j] < words[j-1]
				swapArrays(words[j - 1], words[j], l);				 // Swap them
			}
		}
	}
}

int main() {

	cout << "enter 10 words:" << endl;

	char words[n][l];  // Array of words

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < l; j++) {
			cin >> words[i][j];  // Read in n*l letters
		}
	}

	bubbleSortWords(words, n);  // Sort the words

	cout << "after sorting:" << endl;

	for (int i = 0; i < n; i++) {	  // Print n words
		for (int j = 0; j < l; j++) {  // Print an l-letter word
			cout << words[i][j];
		}
		cout << ' ';  // Separate words with a space
	}
	cout << endl;

	return 0;
}

/*
========== Sample Run - start ==========
enter 10 words:
house apple teach array teach books point float apply begin
after sorting:
apple apply array begin books float house point teach teach
=========== Sample Run - end ===========
----------------------------------------
*/