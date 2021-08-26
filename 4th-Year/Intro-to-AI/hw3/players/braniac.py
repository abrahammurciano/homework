from cell import Cell
from typing import Sequence
from heuristic_player import HeuristicPlayer
from connect_four_board import ConnectFourBoard


class Braniac(HeuristicPlayer):
	def heuristic(self, board: ConnectFourBoard) -> float:
		"""This connect four heuristic counts the number of possible ways a player can win and weights them according to how many of the pieces have already been placed.

		Args:
			board (ConnectFourBoard): The current state of the board to evaluate.

		Returns:
			float: A heuristic value that indicates how close player one is to winning. Positive means very closer than player two, negative means further.
		"""
		value = [0.0]

		def add_value(cells: Sequence[Cell]):
			value[0] += self.sequence_value(cells) * self.player_factor(cells)

		board.for_each_sequence(add_value)
		return value[0]

	def sequence_value(self, cells: Sequence[Cell]) -> float:
		piece_count = len([cell for cell in cells if not cell.is_empty])
		return piece_count ** 5

	def player_factor(self, cells: Sequence[Cell]) -> int:
		player = None
		for cell in cells:
			if not cell.is_empty:
				if player is None:
					player = cell.player
				elif player != cell.player:
					return 0
		return 1 if player == self else -1