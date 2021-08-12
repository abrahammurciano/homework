from typing import Optional
from .Stack import Stack
from .State import State
from .Frontier import Frontier


class IterativeDeepeningFrontier(Frontier):
	"""A frontier for a graph search algorithm that performs DFS up to a limited depth, then if no path is found, increases the depth and starts again."""

	def __init__(self, start: State, initial_depth: int = 1, depth_step: int = 1):
		"""Construct a frontier for an interative deepening search algorithm.

		Args:
			start (State): The state from which to start the search.
			initial_depth (int, optional): The initial depth limit for the search. Defaults to 1.
			depth_step (int, optional): The amount to increase the depth by each time. Defaults to 1.
		"""
		self.__stack = Stack[State]()
		self.__stack.push(start)
		self.__depth = initial_depth
		self.__can_go_deeper = False
		self.__start_state = start
		self.__depth_step = depth_step

	def is_empty(self) -> bool:
		return self.__stack.is_empty() and not self.__can_go_deeper

	def insert(self, state: State):
		if state.path_length <= self.__depth:
			self.__stack.push(state)
			self.__start_state = self.__start_state or state
		else:
			# ignore new state this time because this branch is too deep. But set indicator that there are branches that go deeper than the current depth.
			self.__can_go_deeper = True

	def extract(self):
		if self.__stack.is_empty():
			if self.__can_go_deeper:
				# start over with increased depth
				self.__depth += self.__depth_step
				self.__can_go_deeper = False
				return self.__start_state
			else:
				return None  # There is no path to the target
		return self.__stack.pop()