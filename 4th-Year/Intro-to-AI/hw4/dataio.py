from typing import List, Tuple
from vector import Vector
from gender import Gender
import csv


def read(filename: str) -> Tuple[List[str], List[Vector]]:
	"""Read vectors from a CSV file

	Args:
		filename (str): The name of the file to read.

	Returns:
		Tuple[List[str], List[Vector]]: The headers of the CSV file and a list of vectors in the file.
	"""
	with open(filename, "r") as f:
		rows = list(csv.reader(f))
		return (
			rows[0],
			[
				Vector([float(x) for x in line[:-1]], Gender.from_string(line[-1]))
				for line in rows[1:]
			],
		)


def write(filename: str, headers: List[str], vectors: List[Vector]):
	"""Write a list of vectors to a CSV file.

	Args:
		filename (str): The name of the file to write to.
		headers (List[str]): The headers to use in the CSV file.
		vectors (List[Vector]): The vectors to write in the CSV file.
	"""
	raise NotImplementedError()