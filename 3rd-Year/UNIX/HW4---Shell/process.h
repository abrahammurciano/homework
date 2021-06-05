#ifndef PROCESS_H
#define PROCESS_H

#include <unistd.h>

struct process {
	int out_file;
	pid_t pid;
	int exit_code;
	int in_file;
};

// Duplicate both in and out file descriptors to stdin and stdout respectively, then close the old file descriptors
void route_pipes(struct process p);

// Close both ends of the pipe of a process.
void close_pipes(struct process p);

#endif // !PROCESS_H