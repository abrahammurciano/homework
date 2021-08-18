#!/usr/bin/python

import sys
from typing import Callable, Optional
from Board import Board
import time
from pygraphsearch import search, State, AStarFrontier
from Move import Move


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


def solved(size: int) -> Board:
	return Board(size, range(size * size))


def solve_random_puzzle(
	size: int, heuristic: Callable[[State[Board, Move]], int]
) -> Optional[State[Board, Move]]:
	start = random_board(size)
	print("Starting state:", start, sep="\n")
	frontier = AStarFrontier[Board, Move](start, heuristic)
	target = solved(size)
	return search(frontier, lambda board: board == target)


def solve_n_puzzles(
	size: int, n_puzzles: int, heuristic: Callable[[State[Board, Move]], int]
):
	start_time = time.time()
	duration: float = 0
	for i in range(1, n_puzzles + 1):
		solution = solve_random_puzzle(size, heuristic)
		print(solution.path if solution is not None else "No solution.")
		old_duration = duration
		duration = time.time() - start_time
		print(
			f"Progress: {i}/100",
			f"Total time: {duration}s",
			f"Time for this solution: {duration - old_duration}s",
			f"Average time per solution: {duration / i}s",
			"\n",
			sep="\n",
		)


def n_tiles_out_of_place(board: Board, target: Board) -> int:
	return sum(tile1 != tile2 for (tile1, tile2) in zip(board.tiles, target.tiles))


def total_manhattan_distance(board: Board, target: Board) -> int:
	def row_index(index: int) -> int:
		return index // board.size

	def column_index(index: int) -> int:
		return index % board.size

	def index_offset(
		actual_index: int, target_index: int, index_function: Callable[[int], int]
	) -> int:
		return index_function(actual_index) - index_function(target_index)

	def manhattan_distance(actual_index: int, desired_index: int) -> int:
		return abs(index_offset(actual_index, desired_index, row_index)) + abs(
			index_offset(actual_index, desired_index, column_index)
		)

	return sum(
		manhattan_distance(board.tiles.index(i), target.tiles.index(i))
		for i in range(board.size * board.size)
	)


def main():
	size = int(sys.argv[1]) if len(sys.argv) > 1 else 3
	heuristic = sys.argv[2] if len(sys.argv) > 2 else "manhattan"
	n_puzzles = int(sys.argv[3]) if len(sys.argv) > 3 else 100

	heuristics = {
		"zero": lambda _: 0,
		"misplaced": lambda state: n_tiles_out_of_place(state.node, target),
		"manhattan": lambda state: total_manhattan_distance(state.node, target),
	}

	target = solved(size)
	solve_n_puzzles(size, n_puzzles, heuristics[heuristic])


if __name__ == "__main__":
	main()