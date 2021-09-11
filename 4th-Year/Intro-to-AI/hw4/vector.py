from gender import Gender
from typing import Any, Iterator, Sequence, Optional


class Vector(Sequence[float]):
	def __init__(self, data: Sequence[float], gender: Optional[Gender]):
		"""Constuct a vector.

		Args:
			data (Sequence[float]): The numbers to store in the vector.
			gender (Gender): The gender to associate the data with.
		"""
		self.data = list(data)
		self.gender = gender

	def __getitem__(self, index):
		return self.data[index]

	def __len__(self) -> int:
		return len(self.data)

	def __iter__(self) -> Iterator[float]:
		return iter(self.data)

	def __str__(self) -> str:
		return f"The vector {self.data} has tag {self.gender}"
