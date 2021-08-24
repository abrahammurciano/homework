from random_player import RandomPlayer
from possible_wins_player import PossibleWinsPlayer
from human_player import HumanPlayer
from player import Player
from connect_four_board import ConnectFourBoard
from termcolor import colored
from simple_term_menu import TerminalMenu


def choose_player(number: int, symbol: str) -> Player:
	"""
	Prompts user to choose a player.

	Args:
	    number: The player number to tell the user.
		symbol: The symbol to use for the player's pieces.

	Returns:
	    A new player of the requested type.
	"""
	players = {
		"Human": HumanPlayer(symbol),
		"Braniac": PossibleWinsPlayer(symbol),
		"Baby": RandomPlayer(symbol),
	}
	keys = list(players.keys())
	menu = TerminalMenu(keys)
	print("Choose player", number)
	return players[keys[menu.show()]]


def play_game():
	players = (
		choose_player(1, colored("X", "red", "on_blue", attrs=("bold",))),
		choose_player(2, colored("O", "yellow", "on_blue", attrs=("bold",))),
	)
	board = ConnectFourBoard(
		players=players,
		column_separator=colored("|", "white", "on_blue", attrs=("bold",)),
		empty_symbol=colored(" ", "white", "on_blue", attrs=("bold",)),
	)

	while not board.is_game_over():
		print(board)
		board = board.advance()

	# print the end game status (who won)
	print(board)


if __name__ == "__main__":
	play_game()
