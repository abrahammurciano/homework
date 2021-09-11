from gender import Gender
from typing import Callable, List, Sequence, Tuple
from vector import Vector
from distance import Distance, DistanceFunction
from scipy.spatial.distance import euclidean, hamming, cityblock
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


def classify_mytest(
	k: int, distance_func: DistanceFunction,
):
	correct, total = classify_file(
		"mytest.csv",
		f"mytest{k}{distance_func.__name__[0].lower()}.csv",
		"mytrain.csv",
		k,
		distance_func,
	)
	print(
		f"Classified {correct} correctly out of {total} using {distance_func.__name__}"
		f" with k = {k}."
	)


def manhattan(*args):
	return cityblock(*args)


def main():
	# Part 1
	# Classify the myFile_test file with k = 3. Save the output to myFile_classified.
	classify_file(
		"myFile_test.csv", "myFile_classified.csv", "myFile.csv", 3, euclidean
	)

	# Part 2
	# Browse the mytrain and mytest file. Notice that there are about 200 total records of which 100 exist in the mytrain file, and another 100 in the mytest file.

	classify_mytest(1, euclidean)
	classify_mytest(7, euclidean)
	classify_mytest(19, euclidean)

	classify_mytest(1, manhattan)
	classify_mytest(7, manhattan)
	classify_mytest(19, manhattan)

	classify_mytest(1, hamming)
	classify_mytest(7, hamming)
	classify_mytest(19, hamming)

	# Which combination of distance / value measure of k brings out the best accuracy?

	# Classified 50 correctly out of 100 using euclidean with k = 1.
	# Classified 74 correctly out of 100 using euclidean with k = 7.
	# Classified 68 correctly out of 100 using euclidean with k = 19.
	# Classified 61 correctly out of 100 using manhattan with k = 1.
	# Classified 63 correctly out of 100 using manhattan with k = 7.
	# Classified 70 correctly out of 100 using manhattan with k = 19.
	# Classified 61 correctly out of 100 using hamming with k = 1.
	# Classified 55 correctly out of 100 using hamming with k = 7.
	# Classified 56 correctly out of 100 using hamming with k = 19.

	# euclidean distance with k = 7 gave the best results


if __name__ == "__main__":
	main()