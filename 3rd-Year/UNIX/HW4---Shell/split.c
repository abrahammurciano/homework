#include "split.h"
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

int counttok(char* string, const char* delim) {
	int count = 0;
	int is_delim = (strchr(delim, string[0]) == NULL); // is the current char a delimiter

	for (int i = 0; string[i + 1]; ++i) { // loop through all chars except last
		int is_delim_next = (strchr(delim, string[i + 1]) == NULL); // is next char a delimiter
		if (!is_delim && is_delim_next) {
			++count; // if current and next chars form the end of a word, increment num of words
		}
		is_delim = is_delim_next;
	}

	if (!is_delim) { // if last char is not a delimiter, increment for last word
		++count;
	}

	return count;
}

char** split(char* command, char* delim, int* count) {
	int size = counttok(command, delim) + 1;
	if (count != NULL) {
		*count = size;
	}
	char** words = malloc(size * sizeof(char*));
	words[size - 1] = NULL;

	char* word;
	int i = 0;
	for (word = strtok(command, delim); word; word = strtok(NULL, delim)) {
		words[i++] = word;
	}
	return words;
}