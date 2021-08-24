from exceptions import IllegalMoveException
from connect_four_board import ConnectFourBoard
from player import Player


class HumanPlayer(Player[ConnectFourBoard]):
	def __init__(self, symbol: str):
		super().__init__(symbol)

	def play(self, board: ConnectFourBoard) -> ConnectFourBoard:
		while True:
			try:
				return board.place_piece(int(input("Enter your move: ")))
			except (IllegalMoveException, ValueError) as err:
				print(err)