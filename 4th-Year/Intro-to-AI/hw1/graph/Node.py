from abc import ABC, abstractmethod
from typing import TYPE_CHECKING

if TYPE_CHECKING:
	from graph.Edge import Edge
from typing import Iterable


class Node(ABC):
	"""An abstract base class for a node in a graph."""

	@abstractmethod
	def neighbours(self) -> Iterable["Edge"]:
		"""Get the edges to all the nodes adjacent to this one.

		Returns:
			Iterable[Edge]: The edges to all the nodes adjacent to this one.
		"""
		pass
