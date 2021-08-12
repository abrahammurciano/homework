"""
# יוצר מחסנית ״משוכללת״
[stack, max. depth, init. state, try next level?]
stack - a simple stack as defined at stack.py
max.depth - the current search depth of ID
init.state - the initial state of the problem
try next level - is there a reason to search deeper
"""
from .Stack import Stack
from .State import State
from .Frontier import Frontier


class IterativeDeepeningFrontier(Frontier):
	def __init__(self):
		self.__stack = Stack[State]()
		self.__depth = 1
		self.__can_go_deeper = False

	def is_empty(self) -> bool:
		return self.__stack.is_empty() and not self.__can_go_deeper

	def insert(self, state: State):
		if state.path_length <= self.__depth:
			self.__stack.push(state)
		else:
			self.__can_go_deeper = True

	def extract(self):
		if self.__stack.is_empty():
			pass  # TODO:


def create(x):
	s = stack.create(x)
	return [s, 1, x, False]


def is_empty(s):
	return (
		stack.is_empty(s[0]) and not s[3]
	)  # stack is empty and try next level is false


def insert(s, x):
	if state.path_len(x) <= s[1]:  # check if x is not too deep
		stack.insert(s[0], x)  # insert x to stack
	else:
		s[3] = True  # there is a reason to search deeper if needed


def remove(s):
	if stack.is_empty(s[0]):  # check is there are no states in the stack
		if s[3]:  # check if there is a reason to search deeper
			s[1] += 1  # increase search depth
			s[3] = False  # meanwhile there is no evidence to  a need to search deeper
			return s[2]  # return the initial state
		else:
			return 0
	return stack.remove(s[0])  # if there are items in the stack ...
