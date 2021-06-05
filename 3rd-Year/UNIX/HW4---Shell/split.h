#ifndef SPLIT_H
#define SPLIT_H

// Given a string and some delimiters, return the number of non-empty character sequences which do not contain any of the characters in delim.
int counttok(char* string, const char* delim);

// Given a string, return an array of words in the command delimited by any of the characters in delim. The number of tokens is put in *count.
char** split(char* command, char* delim, int* count);

#endif // !SPLIT_H