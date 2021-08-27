from exceptions import IllegalMoveException
from connect_four_board import ConnectFourBoard
from players.abc.player import Player
import random


class Baby(Player[ConnectFourBoard]):
	def play(self, board: ConnectFourBoard) -> ConnectFourBoard:
		while True:
			try:
				return board.place_piece(random.randint(0, board.columns))
			except (IllegalMoveException, ValueError):
				pass