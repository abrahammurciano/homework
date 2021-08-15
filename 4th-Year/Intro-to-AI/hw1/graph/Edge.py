from typing import Any, Generic, Optional, TypeVar
from .Node import Node
from abc import ABC, abstractmethod


D = TypeVar("D")


class Edge(Generic[D], ABC):
	"""Represents a way to reach one node from another.

	Args:
		Generic (D): Data to be contained by an edge. For example if the edge represents getting from one chess board position to another, the data might be "Be5".
	"""

	def __init__(self, node_a: Node, node_b: Node, data: Optional[D] = None):
		"""Construct a node.

		Args:
			node_a (Node): One of the endpoints of the edge
			node_b (Node): The other endpoint of the edge.
			data (D, optional): Data to be stored by the node. Defaults to None.
		"""
		self.__node_a = node_a
		self.__node_b = node_b
		self.__data = data

	@property
	def node_a(self) -> Node:
		"""The first node of the edge."""
		return self.__node_a

	@property
	def node_b(self) -> Node:
		"""The second node of the edge."""
		return self.__node_b

	@property
	def data(self) -> Optional[D]:
		"""The data stored in this edge."""
		return self.__data

	@property
	@abstractmethod
	def math_repr(self) -> Any:
		"""A mathematical representation of the edge to be used for comparison. For example for an undirected edge this might be a set containing the two nodes. For a directed edge it might be a tuple containing the same. For a weighted edge, this may include the weight.

		Returns:
			Any: A mathematical representation of the node.
		"""
		pass

	def __eq__(self, other):
		return isinstance(other, Edge) and self.math_repr == other.math_repr

	def __str__(self) -> str:
		return str(self.data) if self.data is not None else str(self.math_repr())

	def __repr__(self) -> str:
		return str(self)