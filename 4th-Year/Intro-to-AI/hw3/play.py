#!/usr/bin/python

from possible_wins_lower_player import PossibleWinsLowerPlayer
from board_text_ui import BoardTextUI
from network_player_client import NetworkPlayerClient
from network_player_server import NetworkPlayerServer
from random_player import RandomPlayer
from possible_wins_player import PossibleWinsPlayer
from human_player import HumanPlayer
from player import Player
from connect_four_board import ConnectFourBoard
from termcolor import colored
from simple_term_menu import TerminalMenu


def choose_player(number: int) -> Player:
	"""
	Prompts user to choose a player.

	Args:
	    number: The player number to tell the user.
		symbol: The symbol to use for the player's pieces.

	Returns:
	    A new player of the requested type.
	"""

	def get_server():
		server = NetworkPlayerServer()
		print(f"Please connect a client to {server.address}")
		print(f"Connected to {server.connect()}.")
		return server

	def get_client():
		client = NetworkPlayerClient()
		client.connect((input("Server IP address: "), int(input("Port number: "))))
		return client

	players = {
		"Human": lambda: HumanPlayer(),
		"Braniac": lambda: PossibleWinsPlayer(),
		"Jarvis": lambda: PossibleWinsLowerPlayer(),
		"Baby": lambda: RandomPlayer(),
		"Server": get_server,
		"Client": get_client,
	}
	keys = list(players.keys())
	menu = TerminalMenu(keys)
	print("Choose player", number)
	return players[keys[menu.show()]]()


def play_game():
	players = (choose_player(1), choose_player(2))
	board = ConnectFourBoard(players=players)
	ui = BoardTextUI(
		players[0],
		players[1],
		colored("\u2b24", "red", "on_blue"),
		colored("\u2b24", "yellow", "on_blue"),
		empty_symbol=colored(" ", "white", "on_blue", attrs=("bold",)),
		column_separator=colored("|", "white", "on_blue", attrs=("bold",)),
	)

	ui.render(board)
	while not board.is_game_over():
		board = board.advance()
		ui.render(board)


if __name__ == "__main__":
	play_game()
