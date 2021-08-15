#!/usr/bin/python

import sys
from typing import Optional, Tuple
from Board import Board
from LoggingIterativeDeepeningFrontier import LoggingIterativeDeepeningFrontier
import time
from pygraphsearch import search, State


def random_board(size: int) -> Board:
	"""Create a random start state with an n by n board.

	Args:
		size (int): The number of tiles in each row or column of the board.

	Returns:
		State: The randomly generated start state.
	"""
	board = Board(size)
	for _ in range(size * size * size):  # makes n^3 random moves
		board = board.random_move()
	return board


def solve_random_puzzle(size: int) -> Tuple[Optional[State], int]:
	start = random_board(size)
	print("Starting state:", start, sep="\n")
	frontier = LoggingIterativeDeepeningFrontier(start)
	target = Board(size, range(size * size))
	return search(frontier, lambda board: board == target), frontier.extract_count


def main():
	size = int(sys.argv[1])
	n_puzzles = int(sys.argv[2]) if len(sys.argv) > 2 else 100
	start_time = time.time()
	duration = 0
	total_extractions = 0
	total_depth = 0
	for i in range(1, n_puzzles + 1):
		solution, extract_count = solve_random_puzzle(size)
		depth = len(solution.path)
		total_extractions += extract_count
		total_depth += depth
		print(solution.path if solution is not None else "No solution.")
		old_duration = duration
		duration = time.time() - start_time
		print(
			f"Progress: {i}/100",
			f"Total time: {duration}s",
			f"Time for this solution: {duration - old_duration}s",
			f"Average time per solution: {duration / i}s",
			"",
			f"Extractions for this solution: {extract_count}",
			f"Average extractions per solution: {total_extractions / i}",
			"",
			f"Depth for this solution: {depth}",
			f"Average depth per solution: {total_depth / i}",
			"\n",
			sep="\n",
		)


if __name__ == "__main__":
	main()