#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "colour.h"

// Print a welcome message.
void welcome() {
	colour_print(YELLOW, 0, "                                                      888               888 888\n                                                      888               888 888\n");
	colour_print(PURPLE, 1, "     _.---._");
	colour_print(YELLOW, 0, "                                          888               888 888\n");
	colour_print(PURPLE, 1, " .'\"\".'/|\\`.\"\"'.");
	colour_print(YELLOW, 0, "  .d8888b   .d88b.   8888b.  .d8888b  88888b.   .d88b.  888 888\n");
	colour_print(PURPLE, 1, ":  .' / | \\ `.  :");
	colour_print(YELLOW, 0, " 88K      d8P  Y8b     \"88b 88K      888 \"88b d8P  Y8b 888 888\n");
	colour_print(PURPLE, 1, "'.'  /  |  \\  `.'");
	colour_print(YELLOW, 0, " \"Y8888b. 88888888 .d888888 \"Y8888b. 888  888 88888888 888 888\n");
	colour_print(PURPLE, 1, " `. /   |   \\ .'");
	colour_print(YELLOW, 0, "       X88 Y8b.     888  888      X88 888  888 Y8b.     888 888\n");
	colour_print(PURPLE, 1, "   `-.__|__.-'");
	colour_print(YELLOW, 0, "     88888P'  \"Y8888  \"Y888888  88888P' 888  888  \"Y8888  888 888\n\n");
}

// Print the prompt.
void prompt() {
	colour_print(PURPLE, 1, "seashell >>> ");
	fflush(stdout);
}

// Given a string and some delimiters, return the number of non-empty character sequences which do not contain any of the characters in delim.
int count_tok(char* string, const char* delim) {
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

// Given a command, return an array of words in the command.
char** split_command(char* command) {
	const char* delim = " \t\r\n";
	int size = count_tok(command, delim) + 1;
	char** words = malloc(size * sizeof(char*));
	words[size - 1] = NULL;

	char* word;
	int i = 0;
	for (word = strtok(command, delim); word; word = strtok(NULL, delim)) {
		words[i++] = word;
	}
	return words;
}

// Given a directory and a filename, return the full path if the directory contains the file, or NULL otherwise. The returned string must be freed with free.
char* file_exists(const char* dir, const char* file) {
	struct stat buffer;
	int size = strlen(dir) + strlen(file) + 2;
	char* path = malloc(size);
	snprintf(path, size, "%s/%s", dir, file);
	if (stat(path, &buffer) == 0) {
		return path;
	} else {
		free(path);
		return NULL;
	};
}

// Given a program name, it searches the path and returns the full path to said program (including the program name at the end). The returned string must be freed with free.
char* find_path(const char* program) {
	int size = strlen(getenv("PATH")) + 1;
	char* path = malloc(size);
	snprintf(path, size, "%s", getenv("PATH"));
	char* full_filename = NULL;
	for (char* dir = strtok(path, ":"); dir; dir = strtok(NULL, ":")) {
		struct stat buffer;
		full_filename = file_exists(dir, program);
		if (full_filename) {
			break;
		}
	}
	free(path);
	return full_filename;
}

// Given a space separated string called command, it searches the path for the program whose name is the first word of command and executes it, passing the rest of the words as arguments.
int execute(char* command) {
	char** argv = split_command(command);
	char* path = find_path(argv[0]);
	int exit_code;

	pid_t child_pid = fork();
	if (child_pid == 0) {
		execv(path, argv);
		colour_print(RED, 1, "seashell: Program not found\n");
		exit_code = 0;
	} else {
		waitpid(child_pid, &exit_code, 0);
	}
	free(path);
	return exit_code;
}

int main() {
	welcome();
	while (1) {
		prompt();
		char* command = NULL;
		size_t size = 0;
		getline(&command, &size, stdin);
		if (strcmp(command, "exit\n") == 0) {
			return 0;
		}
		int status = execute(command);
		if (status) {
			colour_print(RED, 1, "%d :( ", status);
		}
		free(command);
	}
}
