#!/usr/bin/python

from players.jarvis import Jarvis
from board_text_ui import BoardTextUI
from players.client import Client
from players.server import Server
from players.baby import Baby
from players.braniac import Braniac
from players.human import Human
from players.abc.player import Player
from connect_four_board import ConnectFourBoard
from termcolor import colored
from simple_term_menu import TerminalMenu
import os


def choose_player(number: int) -> Player:
	"""
	Prompts user to choose a player.

	Args:
	    number: The player number to tell the user.
		symbol: The symbol to use for the player's pieces.

	Returns:
	    A new player of the requested type.
	"""

	def get_ip() -> str:
		return os.getenv("IP") or input("Enter your local IP address")

	def get_server():
		server = Server(get_ip(), 6969)
		print(f"Please connect a client to {server.address}")
		print(f"Connected to {server.connect()}.")
		return server

	def get_client():
		client = Client(get_ip())
		client.connect((input("Server IP address: "), int(input("Port number: "))))
		return client

	players = {
		"Human": lambda: Human(),
		"Braniac": lambda: Braniac(int(input("Choose difficulty level: "))),
		"Jarvis": lambda: Jarvis(int(input("Choose difficulty level: "))),
		"Baby": lambda: Baby(),
		"Server": get_server,
		"Client": get_client,
	}
	keys = list(players.keys())
	menu = TerminalMenu(keys)
	print("Choose player", number)
	key = keys[menu.show()]
	print(key)
	return players[key]()


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
	board.advance()
	ui.render(board)


if __name__ == "__main__":
	play_game()
