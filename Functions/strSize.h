#ifndef strSize_h
#define strSize_h

// Function that finds the size of a string
int strSize(char* str) {
	int size;
	for (size = 0; str[size] != '\0'; size++) continue;
	return size;
}

#endif