#include "process.h"

// If the source and target file descriptors are different, then the source is duplicated to the target and the source is closed.
void move_fd(int source_fd, int target_fd) {
	if (source_fd != target_fd) {
		dup2(source_fd, target_fd);
		close(source_fd);
	}
}

void route_pipes(struct process p) {
	move_fd(p.in_file, 0);
	move_fd(p.out_file, 1);
}

void close_pipes(struct process p) {
	if (p.in_file != 0) {
		close(p.in_file);
	}
	if (p.out_file != 1) {
		close(p.out_file);
	}
}