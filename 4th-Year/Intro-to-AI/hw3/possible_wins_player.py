from status import Status
from typing import Sequence
from heuristic_player import HeuristicPlayer
from connect_four_board import Cell, ConnectFourBoard


class PossibleWinsPlayer(HeuristicPlayer):
	def __init__(self, symbol: str):
		super().__init__(symbol)

	def heuristic(self, board: ConnectFourBoard) -> float:
		"""This connect four heuristic counts the number of possible ways a player can win and weights them according to how many of the pieces have already been placed.

		Args:
			board (ConnectFourBoard): The current state of the board to evaluate.

		Returns:
			float: A heuristic value that indicates how close player one is to winning. Positive means very closer than player two, negative means further.
		"""
		value = [0]

		def add_sequence_value(cells: Sequence[Cell]):
			piece_count = 0
			player = None
			for cell in [cell for cell in cells if cell is not None]:
				if player is None:
					player = cell
				elif player != cell:
					# there are two different pieces in this sequence, so no one can win here
					return
				piece_count += 1
			piece_count = piece_count ** piece_count
			value[0] += piece_count if player == self else -piece_count

		board.for_each_sequence(add_sequence_value)
		return value[0]