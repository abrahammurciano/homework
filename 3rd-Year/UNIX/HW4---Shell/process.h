#ifndef PROCESS_H
#define PROCESS_H

#include <unistd.h>

struct process {
	int out_file;
	pid_t pid;
	int exit_code;
	int in_file;
};

#endif // !PROCESS_H