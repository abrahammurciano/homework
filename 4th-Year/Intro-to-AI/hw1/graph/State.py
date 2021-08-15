from typing import Iterable, List, Optional
from .Node import Node
from .Edge import Edge


class State:
	"""Represents the state of a search.

	A state is made up of the current node and the path taken to get there.
	"""

	def __init__(self, node: Node, path: Optional[List[Edge]] = None):
		"""Construct a state.

		Args:
			node (Node): The current node.
			path (Optional[List[Edge]], optional): The list of edges taken to reach the current node. Defaults to an empty list.
		"""
		self.__node = node
		self.__path = path or []

	@property
	def node(self) -> Node:
		"""The current node in the search."""
		return self.__node

	@property
	def path(self) -> List[Edge]:
		"""The list of edges taken to reach the current node."""
		return self.__path.copy()

	def next_states(self) -> Iterable["State"]:
		"""The states reachable by taking one edge from the current node of this state. This does not include backtracking to the node before the current one.

		Returns:
			Iterable[State]: The states that can be reached from the current node by taking a single edge.
		"""
		return [
			State(edge.node_b, self.__path + [edge])
			for edge in self.node.neighbours()
			if not self.path or edge != self.path[-1]
		]
