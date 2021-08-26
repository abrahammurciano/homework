from node import Node
from exceptions import ColumnFullException, ColumnOutOfBoundsException
from status import Status
from player import Player
from cell import Cell
from typing import Callable, Iterable, Sequence, List, Optional, Tuple
from itertools import product
import random


class ConnectFourBoard(Node):
	"""
	Class representing the state of the game including
	the board, active player, and value.
	"""

	def __init__(
		self,
		players: Tuple[Player, Player],
		rows: int = 6,
		columns: int = 7,
		active_player: int = 0,
		win_length: int = 4,
		last_play: Optional[int] = None,
		grid: Optional[List[List[Cell]]] = None,
	):
		"""
		Create a new instance of a board

		Args:
			players (Tuple[Player, Player]): A tuple containing the 2 players
			rows (int, optional): The number of rows in the board. Defaults to 6.
			columns (int, optional): The number of columns in the board. Defaults to 7.
			active_player (int, optional): Index of the active player in the tuple `players`. Defaults to 0.
			win_length (int, optional): The length of winning sequence. Defaults to 4.
			column_separator (string, optional): A string to print between each column of the board. Defaults to "|".
			empty_symbol (string, optional): A string to print wherever there is no piece. Defaults to " ".
			last_play (int, optional): The column where the last piece was played. Defaults to None, indicating no pieces have been played.
			grid (List[List[Cell]]): 2D list marking where and whose pieces are on the board. Defaults to an empty board.
		"""
		self.__grid = grid or [
			[Cell(row, column) for column in range(columns)] for row in range(rows)
		]
		self.__rows = rows
		self.__columns = columns
		self.__players = players
		self.__active_player = active_player
		self.__win_length = win_length
		self.__last_play = last_play

	@property
	def rows(self) -> int:
		"""The number of rows in the board."""
		return self.__rows

	@property
	def columns(self) -> int:
		"""The number of columns in the board."""
		return self.__columns

	@property
	def active_player(self) -> Player["ConnectFourBoard"]:
		"""The player whose turn it is."""
		return self.players[self.__active_player]

	@property
	def inactive_player(self) -> Player["ConnectFourBoard"]:
		"""The player whose turn it isn't."""
		return self.players[1 - self.__active_player]

	@property
	def players(self) -> Tuple[Player["ConnectFourBoard"], Player["ConnectFourBoard"]]:
		return self.__players

	@property
	def last_play(self) -> Optional[int]:
		"""The column where the last piece was placed (starting from 0), or None if no pieces were played."""
		return self.__last_play

	def cell(self, row: int, column: int) -> Cell:
		"""Get the contents of the cell at the given row and column.

		Args:
			row (int): The row index. 0 is the top row.
			column (int): The column index. 0 is the left column.

		Returns:
			Cell: The player whose piece is in the cell, or None if there is no piece in the cell.
		"""
		return self.__grid[row][column]

	def is_game_over(self) -> bool:
		"""Returns True if the game is over, False otherwise."""
		return self.status().game_over

	def is_terminal(self) -> bool:
		return self.is_game_over()

	def place_piece(self, column: int) -> "ConnectFourBoard":
		"""
		Creates a new board with a piece of the current player placed in the given column, and with the turn toggled to the other player.

		Args:
			column: The column to place the piece.

		Raises:
			ColumnFullError if the column is full.
		"""
		if column < 0 or column >= self.__columns:
			raise ColumnOutOfBoundsException(column)
		row = self.__next_open_row(column)
		if row is None:
			raise ColumnFullException(column)
		board = self.__copy()
		board.__grid[row][column] = Cell(row, column, self.active_player)
		board.__active_player = 1 - board.__active_player
		board.__last_play = column
		return board

	def children(self) -> Iterable["ConnectFourBoard"]:
		"""
		Find next states for the current board

		Returns:
			Set of board states that can be created by placing a piece
		"""
		children = [
			self.place_piece(col)
			for col in range(self.__columns)
			if not self.__column_is_full(col)
		]
		random.shuffle(children)
		return children

	def advance(self) -> "ConnectFourBoard":
		"""Play the next move by the active player and return the resulting board.

		Returns:
			The board resulting from the active player's move.
		"""
		return self.active_player.play(self)

	def status(self) -> Status:
		"""
		Checks if the game is won, tied, or ongoing.

		Returns:
			A status indicating if the game is over, and who, if anyone, is the winner.
		"""
		if winner := self.__check_for_win():
			return Status(winner=winner)
		if self.__is_draw():
			return Status(game_over=True, winner=None)
		return Status(game_over=False)

	def for_each_sequence(self, action: Callable[[Sequence[Cell]], None]):
		"""Apply an action to each sequence of `win_length` sequences of cells in a straight line.

		Args:
			action (Callable[[Sequence[Cell]], None]): The function to apply to each sequence of consecutive cells.
		"""
		self.__for_sequence_in_direction(  # vertical down
			(0, self.__rows - self.__win_length + 1),
			(0, self.__columns),
			lambda r, c, i: self.__grid[r + i][c],
			action,
		)
		self.__for_sequence_in_direction(  # horizontal right
			(0, self.__rows),
			(0, self.__columns - self.__win_length + 1),
			lambda r, c, i: self.__grid[r][c + i],
			action,
		)
		self.__for_sequence_in_direction(  # diagonal down right
			(0, self.__rows - self.__win_length + 1),
			(0, self.__columns - self.__win_length + 1),
			lambda r, c, i: self.__grid[r + i][c + i],
			action,
		)
		self.__for_sequence_in_direction(  # diagonal down left
			(0, self.__rows - self.__win_length + 1),
			(self.__win_length - 1, self.__columns),
			lambda r, c, i: self.__grid[r + i][c - i],
			action,
		)

	def __for_sequence_in_direction(
		self,
		row_range: Tuple[int, int],
		column_range: Tuple[int, int],
		get_cell: Callable[[int, int, int], Cell],
		action: Callable[[Sequence[Cell]], None],
	):
		"""Iterate through all sequences of length `win_length` which go in the given direction, and call the given function with the cells in each sequence.

		For example, you might call this function to iterate over all horizontal sequences of four cells to check if someone has won with four pieces placed horizontally.

		Args:
			row_range (Tuple[int, int]): The range of rows [start, end) to start checking for wins.
			column_range (Tuple[int, int]): The range of columns [start, end) to start checking for wins.
			get_cell (Callable[[int, int, int], Cell]): A function which takes a row and column of where a particular check started from, as well as an index i, and returns the contents of the ith cell from the starting cell in some direction.
			action (Callable[[Sequence[Cell]], None]): A function to call for each sequence of consecutive cells. It should take a sequence of cells and not return anything.
		"""
		for row, col in product(range(*row_range), range(*column_range)):
			action(list(get_cell(row, col, i) for i in range(self.__win_length)))

	def __check_for_win(self) -> Optional[Player]:
		"""
		Checks if the board is in a winning state

		Returns:
			The player who has won or None if no one has won
		"""
		winner: List[Optional[Player]] = [None]

		def is_winning_sequence(cells: Sequence[Cell]):
			"""Check if all given cells have a piece of the same player, in which case the winner is placed in `winner[0]`.

			Args:
				cells (Sequence[Cell]): The cells to check.
			"""
			first = next(iter(cells))
			if not first.is_empty and all(
				cell.player == first.player for cell in cells
			):
				winner[0] = first.player

		self.for_each_sequence(is_winning_sequence)
		return winner[0]

	def __copy(self) -> "ConnectFourBoard":
		"""Returns a new board containing a copy of the current one"""
		new_board = ConnectFourBoard(
			rows=self.__rows,
			columns=self.__columns,
			players=self.__players,
			active_player=self.__active_player,
			win_length=self.__win_length,
			last_play=self.__last_play,
			grid=[row.copy() for row in self.__grid],
		)
		return new_board

	def __is_draw(self) -> bool:
		"""Returns True if the game has ended in a draw, False otherwise."""
		return not any(any(cell.is_empty for cell in row) for row in self.__grid)

	def __next_open_row(self, column: int) -> Optional[int]:
		"""
		Finds the next available row to place a piece in a column

		Args:
			column: the column to check for availability

		Returns:
			The last available row or None if the column is full
		"""
		if self.__column_is_full(column):
			return None
		for row in range(self.__rows - 1, -1, -1):
			if self.__grid[row][column].is_empty:
				return row
		return None

	def __column_is_full(self, column: int):
		"""
		Checks if a column is full.

		Args:
			column: the column to check for availability

		Returns:
			True if column is full, False otherwise
		"""
		return not self.__grid[0][column].is_empty
