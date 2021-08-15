from graph.Node import Node
from typing import Optional
from .State import State
from .Frontier import Frontier
from .IterativeDeepeningFrontier import IterativeDeepeningFrontier
import sys


def search(frontier: Frontier, target: Node) -> Optional[State]:
	"""Search for the path to a target.

	Args:
		frontier (Frontier): An object derived from Frontier. It should contain only the start state and will be modified by this function.
		target (Node): The node we seek a path to.

	Returns:
		Optional[State]: The target state, or None if none exists.
	"""
	while not frontier.is_empty():
		state = frontier.extract()
		if state is None or state.node == target:
			return state
		for next_state in state.next_states():
			frontier.insert(next_state)
	return None