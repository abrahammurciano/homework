from distance import Distance
from vector import Vector
from gender import Gender
import dataio
from scipy.spatial.distance import euclidean
import statistics


def main():

	# Part 1
	# Define point tagged vector and 2 tagged vectors data1, data2
	point = Vector([1, 0, 0], None)
	data1 = Vector([1, 1, 1], Gender.MALE)
	data2 = Vector([1, 2, 0], Gender.FEMALE)

	# Part 2
	# The two vectors data1, data2 must be printed separately from their tags
	print(data1, data2, sep="\n")

	# Part 3
	# You must calculate and print the distance between data1 and data2
	print("The distance between data1 and data2 is", euclidean(data1, data2))

	# Part 4
	# Enter code to read from myFile.csv file into list
	vectors, _ = dataio.read("myFile.csv")

	# Part 4a
	# You must print the first 2 vectors of the file
	print(v1 := vectors[0])
	print(v2 := vectors[1])

	# Part 4b
	# The distance between the above vectors must be calculated and printed
	print("The distance between the first two vectors is", euclidean(v1, v2))

	# Part 5
	# Suppose the first vector is untagged. We'll call him a point. You must
	# create a list called distances, which contains the point-to-point
	# distance for any other vector in the file, along with the tagging of the
	# vector.
	distances = [Distance(point, v) for v in vectors]

	# Part 6
	# You must sort the list you created in the previous section.
	distances.sort()

	# Part 7
	# Print all their vectors and distances from the first point.
	print(*distances, sep="\n")

	# Part 8
	# What is the tag (tag) / category of the first record (point) with k = 1?
	print(f"The test point is categorized as {distances[0].vector.gender} with k = 1")

	# Part 9
	# What is the tag (category) of the first record (point) with k = 3?
	print(
		"The test point is categorized as"
		f" {statistics.mode([d.vector.gender for d in distances[:3]])} with k = 3"
	)


if __name__ == "__main__":
	main()