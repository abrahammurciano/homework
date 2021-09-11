from typing import List, Tuple
from vector import Vector
from gender import Gender
import csv


def read(filename: str) -> Tuple[List[Vector], List[str]]:
	"""Read vectors from a CSV file

	Args:
		filename (str): The name of the file to read.

	Returns:
		Tuple[List[Vector], List[str]]: A list of vectors in the file and the headers of the CSV file.
	"""
	with open(filename, "r") as f:
		rows = list(csv.reader(f))
		return (
			[
				Vector([float(x) for x in line[:-1]], Gender.from_string(line[-1]))
				for line in rows[1:]
			],
			rows[0],
		)


def write(filename: str, headers: List[str], vectors: List[Vector]):
	"""Write a list of vectors to a CSV file.

	Args:
		filename (str): The name of the file to write to.
		headers (List[str]): The headers to use in the CSV file.
		vectors (List[Vector]): The vectors to write in the CSV file.
	"""
	with open(filename, "w") as f:
		writer = csv.writer(f)
		writer.writerow(headers)
		writer.writerows(
			[[str(n) for n in vector.data] + [str(vector.gender)] for vector in vectors]
		)
