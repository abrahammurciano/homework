from typing import Any, Callable
from pygraphsearch import AStarFrontier, State
from Move import Move
from Board import Board


class LoggingAStarFrontier(AStarFrontier[Board, Move]):
	def __init__(self, start: Board, heuristic: Callable[[State[Board, Move]], Any]):
		self.__total_inserts = 0
		super().__init__(start, heuristic)

	def insert(self, state: State[Board, Move]):
		super().insert(state)
		self.__total_inserts += 1

	@property
	def total_inserts(self) -> int:
		return self.__total_inserts