class IllegalMoveException(RuntimeError):
	"""Base exception for illegal move exceptions"""


class ColumnFullException(IllegalMoveException):
	"""Exception caused by placing a piece in a full column"""

	def __init__(self, column: int):
		self.__column = column

	def __str__(self):
		return f"You can't place a piece in column {self.__column}. It is full!"


class ColumnOutOfBoundsException(IllegalMoveException):
	"""Exception caused by placing a piece in a column that does not exist"""

	def __init__(self, column: int):
		self.__column = column

	def __str__(self):
		return f"Column {self.__column} is not a valid column!"
