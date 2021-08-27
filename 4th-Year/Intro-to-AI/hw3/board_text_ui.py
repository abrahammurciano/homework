from players.abc.player import Player
from connect_four_board import ConnectFourBoard


class BoardTextUI:
	def __init__(
		self,
		player_1: Player,
		player_2: Player,
		symbol_1: str = "X",
		symbol_2: str = "O",
		empty_symbol: str = " ",
		column_separator: str = "|",
	):
		self.__symbols = {
			player_1: symbol_1,
			player_2: symbol_2,
			None: empty_symbol,
		}
		self.__separator = column_separator

	def render(self, board: ConnectFourBoard):
		self.__print_last_play(board)
		self.__print_board(board)
		self.__print_indices(board)
		self.__print_status(board)
		print()

	def __print_last_play(self, board: ConnectFourBoard):
		print(
			f'Player "{self.__symbols[board.inactive_player]}" played column'
			f" {board.last_play + 1}."
			if board.last_play is not None
			else ""
		)

	def __print_board(self, board: ConnectFourBoard):
		for row in range(board.rows):
			print(self.__separator, end="")
			for column in range(board.columns):
				print(
					self.__symbols[board.cell(row, column).player], end=self.__separator
				)
			print()

	def __print_indices(self, board: ConnectFourBoard):
		print("", *range(1, board.columns + 1))

	def __print_status(self, board: ConnectFourBoard):
		if board.is_game_over():
			if winner := board.status().winner:
				print(f"\nPlayer {self.__symbols[winner]} is the winner!")
			else:
				print("\nIt's a tie!")