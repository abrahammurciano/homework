#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void welcome() {
	printf("                                                      888               888 888\n                                                      888               888 888\n     _.---._                                          888               888 888\n .'\"\".'/|\\`.\"\"'.  .d8888b   .d88b.   8888b.  .d8888b  88888b.   .d88b.  888 888\n:  .' / | \\ `.  : 88K      d8P  Y8b     \"88b 88K      888 \"88b d8P  Y8b 888 888\n'.'  /  |  \\  `.' \"Y8888b. 88888888 .d888888 \"Y8888b. 888  888 88888888 888 888\n `. /   |   \\ .'       X88 Y8b.     888  888      X88 888  888 Y8b.     888 888\n   `-.__|__.-'     88888P'  \"Y8888  \"Y888888  88888P' 888  888  \"Y8888  888 888\n\n");
}

void prompt() {
	printf("seashell >>> ");
	fflush(stdout);
}

void execute(const char* command) {

}

int main() {
	welcome();
	while (1) {
		prompt();
		char* command = NULL;
		size_t size = 0;
		getline(&command, &size, stdin);
		if (strcmp(command, "Quit") == 0) {
			return 0;
		}
		execute(command);
		free(command);
	}
}
