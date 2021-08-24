from abc import abstractmethod
from math import inf
from status import Status
from node import Node
from alpha_beta_pruning import ab_minimax
from connect_four_board import ConnectFourBoard
from player import Player


class HeuristicPlayer(Player[ConnectFourBoard]):
	def __init__(self, symbol: str):
		super().__init__(symbol)

	def play(self, board: ConnectFourBoard) -> ConnectFourBoard:
		_, best_board = ab_minimax(board, lambda node: self.__heuristic(node))
		assert isinstance(best_board, ConnectFourBoard)
		return best_board

	def __heuristic(self, board: Node) -> float:
		assert isinstance(board, ConnectFourBoard)
		status = board.status()
		if status == Status.TIE:
			return 0
		elif status == Status.PLAYER_1_WINS:
			return inf if board.players[0] == self else -inf
		elif status == Status.PLAYER_2_WINS:
			return inf if board.players[1] == self else -inf
		else:
			return self.heuristic(board)

	@abstractmethod
	def heuristic(self, board: ConnectFourBoard) -> float:
		"""Calculate a heuristic value for a given board. The implementation of this function can assume that the game is not yet finished, therefore does not need to take into account returning 0 for a draw and positive or negative infinity for a win.

		Args:
			board (Board): The board to calculate the heuristic value for.

		Returns:
			float: The heuristic value for the given board.
		"""
		pass