from exceptions import IllegalMoveException
from connect_four_board import ConnectFourBoard
from player import Player


class Human(Player[ConnectFourBoard]):
	def play(self, board: ConnectFourBoard) -> ConnectFourBoard:
		while True:
			try:
				return board.place_piece(int(input("Enter your move: ")) - 1)
			except (IllegalMoveException, ValueError) as err:
				print(err)