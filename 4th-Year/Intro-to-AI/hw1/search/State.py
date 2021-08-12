from typing import Collection, List
from .Board import Board
from .Move import Move


class State:
	"""Represents the current state of the board as well as the current path from the start."""

	def __init__(self, board: Board, path: List[Move]):
		"""Construct a state with a board and the path that the empty tile has moved previously.

		Args:
			board (Board): The current position of the tiles.
			path (List[Move]): The sequence of moves that have been applied to the empty tile since the start state.
		"""
		self.__board = board
		self.__path = path

	@classmethod
	def random_start(cls, size: int) -> "State":
		"""Create a random start state with an n by n board.

		Args:
			size (int): The number of tiles in each row or column of the board.

		Returns:
			State: The randomly generated start state.
		"""
		board = Board(size)
		for i in range(size * size * size):  # makes n^3 random moves
			board = board.random_move()
		return State(board, [])

	def next_states(self) -> Collection["State"]:
		"""Get a collection of states reachable from the current state.

		Returns:
			Collection[State]: A collection of states reachable from the current state.
		"""
		return [
			State(self.board.move(move), self.__path + [move])
			for move in Move
			if self.board.can_move(move)
		]

	@property
	def path_length(self) -> int:
		"""The length of the path from the start state to this state."""
		return len(self.__path)

	@property
	def path(self) -> List[Move]:
		"""A copy of the path of this state."""
		return self.__path.copy()

	@property
	def board(self) -> Board:
		"""The board of tiles of this state."""
		return self.__board
