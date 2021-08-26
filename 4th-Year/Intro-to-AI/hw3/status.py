from typing import Optional
from player import Player


class Status:
	"""Class representing the status of the game."""

	def __init__(self, *, game_over: bool = True, winner: Optional[Player] = None):
		self.__game_over = game_over
		self.__winner = winner

	@property
	def game_over(self) -> bool:
		"""Whether the game is over or not."""
		return self.__game_over

	@property
	def winner(self) -> Optional[Player]:
		"""The winner of the game, if any."""
		return self.__winner

	def __eq__(self, other) -> bool:
		return (
			isinstance(other, Status)
			and self.__game_over == other.__game_over
			and self.__winner == other.__winner
		)