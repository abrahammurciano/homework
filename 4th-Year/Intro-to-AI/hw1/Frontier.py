from abc import ABC, abstractmethod
from .State import State


class Frontier(ABC):
	@abstractmethod
	def is_empty(self) -> bool:
		"""Check if the frontier is empty or not.

		Returns:
			bool: True if the frontier is empty, false otherwise.
		"""
		pass

	@abstractmethod
	def extract(self) -> State:
		"""Extract a state to expand from the frontier.

		Returns:
			State: The state to expand.
		"""
		pass

	@abstractmethod
	def insert(self, state: State):
		"""Insert a state into the frontier.

		Args:
			state (State): The state to insert.
		"""
		pass