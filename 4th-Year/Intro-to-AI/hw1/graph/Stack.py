from typing import Generic, List, TypeVar


T = TypeVar("T")


class Stack(Generic[T]):
	"""A collection of items which can be accessed in a LIFO order.

	Args:
		Generic (T): The type of the items stored in the stack.
	"""

	def __init__(self) -> None:
		"""Construct an empty stack."""
		super().__init__()
		self.__list: List[T] = []

	def is_empty(self) -> bool:
		"""Check if the stack is empty.

		Returns:
			bool: True if the stack is empty, false otherwise.
		"""
		return not bool(self.__list)

	def push(self, value: T):
		"""Push an item onto the stack.

		Args:
			value (T): The item to push onto the stack.
		"""
		self.__list.append(value)

	def pop(self) -> T:
		"""Pop an item from the top of the stack.

		Returns:
			T: The topmost item that was removed from the stack.

		Raises:
			IndexError: If the stack was empty.
		"""
		return self.__list.pop()

	def __len__(self) -> int:
		"""Get the number of items in the stack.

		Returns:
			int: The number of items in the stack.
		"""
		return len(self.__list)