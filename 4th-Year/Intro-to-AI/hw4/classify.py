from gender import Gender
from typing import List, Tuple
from vector import Vector
from distance import Distance, DistanceFunction
import statistics
import dataio


def classify(
	vector: Vector, training: List[Vector], k: int, distance_func: DistanceFunction
) -> Gender:
	"""Estimate the gender for a given vector based on the k nearest neighbours to said vector in the training set.

	Args:
		vector (Vector): The vector to estimate the gender for.
		training (List[Vector]): The vectors used for training.
		k (int): The number of nearest neighbours to consider.
		distance_func (DistanceFunction): A function which takes two Sequences and returns some distance metric between them.

	Returns:
		Gender: The estimated gender for the given vector.
	"""
	distances = [Distance(vector, v, distance_func) for v in training]
	distances.sort()
	return statistics.mode([d.vector.gender for d in distances[:k] if d.vector.gender])


def classify_file(
	filename: str,
	output_file: str,
	training_file: str,
	k: int,
	distance_func: DistanceFunction,
) -> Tuple[int, int]:
	"""Classify an entire file using training data stored in another file, and write the output to another file.

	Args:
		filename (str): The file containing the vectors to classify.
		output_file (str): Where to put the results of the classification.
		training_file (str): The file containing the training data.
		k (int): The number of nearest neighbours to consider.
		distance_func (DistanceFunction): A function which takes two Sequences and returns some distance metric between them.

	Returns:
		Tuple[int, int]: The number of correctly classified vectors, and the total number of vectors.
	"""
	training, _ = dataio.read(training_file)
	data, headers = dataio.read(filename)
	correct, total = 0, 0
	for vector in data:
		estimate = classify(vector, training, k, distance_func)
		total += 1
		if estimate == vector.gender:
			correct += 1
		else:
			vector.gender = estimate
	dataio.write(output_file, headers, data)
	return correct, total