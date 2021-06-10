#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "colour.h"
#include "split.h"
#include "process.h"

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

// Given an array of commands, this function executes them, piping each one to the next, then returns the exit code of the last one.
int execute_piped(char** commands, int count) {
	struct process* children = malloc(count * sizeof(struct process));
	children[count - 1].in_file = 0;
	children[0].out_file = 1;

	for (int i = 0; i < count - 1; ++i) {
		pipe(&children[i].in_file);
	}

	for (int i = count - 1; i >= 0; --i) {
		char** argv = split(commands[count - i - 1], " \t\r\n", NULL);
		children[i].pid = fork();
		if (children[i].pid == 0) {
			route_pipes(children[i]);
			execvp(argv[0], argv);
			colour_print(RED, 1, "seashell: Program not found\n");
			children[i].exit_code = 0;
		} else {
			close_pipes(children[i]);
			waitpid(children[i].pid, &children[i].exit_code, 0);
		}
	}

	int exit_code = children[0].exit_code;
	free(children);
	return exit_code;
}

// Given a string representing a command, it executes the command and returns the exit code.
int execute(char* command) {
	int count;
	char** commands = split(command, "|", &count);
	return execute_piped(commands, count);
}

int main() {
	welcome();
	while (1) {
		prompt();
		char* command = NULL;
		size_t size = 0;
		getline(&command, &size, stdin);
		if (command[0] == '\n') {
			return 0;
		}
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
