from typing import Generic, TypeVar
from abc import ABC, abstractmethod
from node import Node

N = TypeVar("N", bound="Node")


class Player(Generic[N], ABC):
	"""
	Class representing a player.
	A player has a symbol they play as and can be a human or AI
	"""

	def __init__(self, symbol: str):
		"""Construct a player.

		Args:
			symbol (str): The symbol to use to represent the pieces of this player.
			player_type (PlayerType): The type of player.
		"""
		self.__symbol = symbol

	@abstractmethod
	def play(self, node: N) -> N:
		"""Ask this player to choose the next node from the given node.

		Args:
			node (N): An object that inherits from Node which represents the current node.

		Returns:
			N: The node this player chose.
		"""
		pass

	def __eq__(self, other) -> bool:
		return isinstance(other, Player) and self.__symbol == other.__symbol

	def __hash__(self):
		return hash(self.__symbol)

	def __repr__(self):
		return str(self)

	def __str__(self):
		return self.__symbol
