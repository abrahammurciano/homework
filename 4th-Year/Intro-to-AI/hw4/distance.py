from vector import Vector
from scipy.spatial.distance import euclidean


class Distance:
	def __init__(self, start: Vector, vector: Vector):
		"""Construct a distance object for the distance to `vector` from `start`.

		Args:
			start (Vector): The vector to calculate the distance from.
			vector (Vector): The vector to calculate the distance to.
		"""
		self.distance = euclidean(start, vector)
		self.vector = vector

	def __lt__(self, other) -> bool:
		return self.distance < other.distance

	def __str__(self) -> str:
		return f"Vector {self.vector.data} has distance {self.distance} from start"