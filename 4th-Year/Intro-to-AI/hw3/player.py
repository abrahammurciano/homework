from typing import Generic, TypeVar
from abc import ABC, abstractmethod
from node import Node

N = TypeVar("N", bound="Node")


class Player(Generic[N], ABC):
	"""
	Class representing a player.
	A player has a symbol they play as and can be a human or AI
	"""

	@abstractmethod
	def play(self, node: N) -> N:
		"""Ask this player to choose the next node from the given node.

		Args:
			node (N): An object that inherits from Node which represents the current node.

		Returns:
			N: The node this player chose.
		"""
		pass

	def __repr__(self) -> str:
		return str(self)