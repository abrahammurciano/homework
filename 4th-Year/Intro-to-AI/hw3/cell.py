from typing import Optional, TYPE_CHECKING
from players.abc.player import Player

if TYPE_CHECKING:
	from connect_four_board import ConnectFourBoard


class Cell:
	def __init__(
		self, row: int, column: int, player: Optional[Player["ConnectFourBoard"]] = None
	):
		"""Construct a cell.

		Args:
			row (int): The row index. 0 is the top row.
			column (int): The column index. 0 is the leftmost column.
			player (Player[ConnectFourBoard], optional): The player whose piece is in this cell. Defaults to None for an empty cell.
		"""
		self.__player = player
		self.__row = row
		self.__column = column

	@property
	def is_empty(self) -> bool:
		"""Check if there is no piece in this cell."""
		return self.__player is None

	@property
	def player(self) -> Optional[Player]:
		"""The player whose piece is in this cell."""
		return self.__player

	@property
	def row(self) -> int:
		"""The row index. 0 is the top row."""
		return self.__row

	@property
	def column(self) -> int:
		"""The column index. 0 is the leftmost column."""
		return self.__column

	def __str__(self) -> str:
		return str(self.player)

	def __repr__(self) -> str:
		return str(self)