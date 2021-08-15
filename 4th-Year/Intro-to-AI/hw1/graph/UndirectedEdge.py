from .Node import Node
from typing import Any, Collection, Generic
from .Edge import Edge, D


class UndirectedEdge(Generic[D], Edge[D]):
	@property
	def math_repr(self) -> Any:
		return {self.node_a, self.node_b}
