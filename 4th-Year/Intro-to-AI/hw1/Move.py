from enum import Enum


class Move(Enum):
	"""Represents one of four possible moves. Up, down, right, or left."""

	UP = 1
	DOWN = 2
	LEFT = 3
	RIGHT = 4

	def __str__(self) -> str:
		return self.name