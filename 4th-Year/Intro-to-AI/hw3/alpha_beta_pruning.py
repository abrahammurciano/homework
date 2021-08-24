import itertools
from math import inf
from node import Node
from typing import Callable, Optional, Tuple, TypeVar

MAX_DEPTH = 2


__unique_nums = itertools.count(start=1)


def ab_minimax(
	node: Node,
	heuristic: Callable[[Node], float],
	maximizing: bool = True,
	depth: int = MAX_DEPTH,
	alpha: float = -inf,
	beta: float = inf,
) -> Tuple[float, Optional[Node]]:
	"""
	Minimax algorithm with alpha-beta pruning.

	Args:
	    node (N): The starting node.
		heuristic (Function(N) -> float): The heuristic function to apply when a leaf is reached.
	    maximizing (bool, optional): Whether the current board should be maximized and not minimized. Defaults to True.
	    depth (int, optional): The current search depth. Defaults to MAX_DEPTH.
	    alpha (float, optional): The "best" value for the current player found so far. Defaults to negative infinity.
	    beta (float, optional): The "best" value for the opponent found so far. Defaults to positive infinity.

	Returns:
	    Tuple containing the board value and node after the best move is applied or None if there are no moves available.
	"""

	if depth == 0 or node.is_terminal():
		return heuristic(node), node

	best_value, get_best = (-inf, max) if maximizing else (inf, min)
	best_move: Optional[Node] = None
	for child in node.children():
		grandchild_value, grandchild = ab_minimax(
			child, heuristic, not maximizing, depth - 1, beta, alpha
		)
		best_value, _, best_move = get_best(
			(best_value, next(__unique_nums), best_move),
			(grandchild_value, next(__unique_nums), child),
		)
		if get_best(best_value, beta) == best_value:
			break
		alpha = get_best(alpha, best_value)
	return best_value, best_move
