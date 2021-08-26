from abc import abstractmethod
from math import inf
from node import Node
from alpha_beta_pruning import ab_minimax
from connect_four_board import ConnectFourBoard
from player import Player


class HeuristicPlayer(Player[ConnectFourBoard]):
	def play(self, board: ConnectFourBoard) -> ConnectFourBoard:
		_, best_board = ab_minimax(board, lambda node: self.__heuristic(node))
		assert isinstance(best_board, ConnectFourBoard)
		return best_board

	def __heuristic(self, board: Node) -> float:
		assert isinstance(board, ConnectFourBoard)
		status = board.status()
		if status.game_over:
			if status.winner is None:
				return 0
			return inf if status.winner == self else -inf
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