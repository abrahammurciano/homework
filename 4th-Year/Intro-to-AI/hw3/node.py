from abc import ABC, abstractmethod
from typing import Iterable


class Node(ABC):
	@abstractmethod
	def is_terminal(self) -> bool:
		"""Check if the node represents a terminal state.

		Returns:
			bool: True if the node represents a terminal state, False otherwise.
		"""
		pass

	@abstractmethod
	def children(self) -> Iterable["Node"]:
		"""Get the nodes reachable with one step from this node.

		Retruns:
			Iterable[Node]: A collection of nodes reachable from this node with one step.
		"""
		pass