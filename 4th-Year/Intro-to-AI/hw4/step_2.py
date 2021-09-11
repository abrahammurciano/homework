from distance import DistanceFunction
from scipy.spatial.distance import euclidean, hamming, cityblock
from classify import classify_file


def classify_mytest(
	k: int, distance_func: DistanceFunction,
):
	"""Classify all the vectors in mytest.csv using the given distance function and k.

	The classified data is stored in mytest{k}{f}.csv where k is the value of the given argument k and f is the first letter of the name of the distance function.

	A summary of the quality of the classification is printed.

	Args:
		k (int): The number of nearest neighbours to consider.
		distance_func (DistanceFunction): A function that takes two Sequences and returns some distance metric between them.
	"""
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