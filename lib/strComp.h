#ifndef strComp_h
#define strComp_h

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

#endif