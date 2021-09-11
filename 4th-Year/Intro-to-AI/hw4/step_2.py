from gender import Gender
import statistics
from typing import List, Tuple
from vector import Vector
from distance import Distance
import dataio


def classify(vector: Vector, training: List[Vector], k: int) -> Gender:
	"""Estimate the gender for a given vector based on the k nearest neighbours to said vector in the training set.

	Args:
		vector (Vector): The vector to estimate the gender for.
		training (List[Vector]): The vectors used for training.
		k (int): The number of nearest neighbours to consider.

	Returns:
		Gender: The estimated gender for the given vector.
	"""
	distances = [Distance(vector, v) for v in training]
	distances.sort()
	return statistics.mode([d.vector.gender for d in distances[:k] if d.vector.gender])


def classify_file(
	filename: str, output_file: str, training_file: str, k: int
) -> Tuple[int, int]:
	"""Classify an entire file using training data stored in another file, and write the output to another file.

	Args:
		filename (str): The file containing the vectors to classify.
		output_file (str): Where to put the results of the classification.
		training_file (str): The file containing the training data.
		k (int): The number of nearest neighbours to consider.

	Returns:
		Tuple[int, int]: The number of correctly classified vectors, and the total number of vectors.
	"""
	training, _ = dataio.read(training_file)
	data, headers = dataio.read(filename)
	correct, total = 0, 0
	for vector in data:
		estimate = classify(vector, training, k)
		total += 1
		if estimate == vector.gender:
			correct += 1
		else:
			vector.gender = estimate
	dataio.write(output_file, headers, data)
	return correct, total


def main():
	# Part 1
	# Classify the myFile_test file with k = 3. Save the output to myFile_classified.
	classify_file("myFile_test.csv", "myFile_classified.csv", "myFile.csv", 3)

	# Part 2
	# Browse the mytrain and mytest file. Notice that there are about 200 total records of which 100 exist in the mytrain file, and another 100 in the mytest file.

	# What accuracy do we get with k = 1? Save the tags as a file named mytest1e.
	classify_file("mytest.csv", "mytest1e.csv", "mytrain.csv", 1)

	# What accuracy do we get with k = 7? Save the tags as a file named mytest7e.
	classify_file("mytest.csv", "mytest7e.csv", "mytrain.csv", 7)


if __name__ == "__main__":
	main()