from pygraphsearch.Node import Node
from pygraphsearch.IterativeDeepeningFrontier import IterativeDeepeningFrontier


class LoggingIterativeDeepeningFrontier(IterativeDeepeningFrontier):
	def __init__(self, start: Node, initial_depth: int = 1, depth_step: int = 1):
		"""Construct a frontier for an interative deepening search algorithm.

		Args:
			start (State): The state from which to start the search.
			initial_depth (int, optional): The initial depth limit for the search. Defaults to 1.
			depth_step (int, optional): The amount to increase the depth by each time. Defaults to 1.
		"""
		super().__init__(start, initial_depth, depth_step)
		self.__extract_count = 0

	def extract(self):
		self.__extract_count += 1
		return super().extract()

	@property
	def extract_count(self) -> int:
		return self.__extract_count