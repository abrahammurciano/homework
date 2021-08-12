#!/usr/bin/python

import sys
from search import Board, IterativeDeepeningFrontier, State, search


def main():
	size = int(sys.argv[1])
	start = State.random_start(size)
	print("Starting state:", "---------------", start.board, sep="\n")
	frontier = IterativeDeepeningFrontier(start)
	target = Board(size, range(size * size))
	end = search(frontier, target)
	print(end.path if end is not None else "No solution.")


if __name__ == "__main__":
	main()