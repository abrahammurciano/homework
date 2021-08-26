from exceptions import IllegalMoveException
from connect_four_board import ConnectFourBoard
from player import Player
import random


class RandomPlayer(Player[ConnectFourBoard]):
	def play(self, board: ConnectFourBoard) -> ConnectFourBoard:
		while True:
			try:
				return board.place_piece(random.randint(0, board.columns))
			except (IllegalMoveException, ValueError):
				pass

	def __str__(self) -> str:
		return "Baby"

	def __repr__(self) -> str:
		return str(self)