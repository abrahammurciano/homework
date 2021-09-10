import statistics
from distance import Distance
import dataio

# Part 1
# Classify the myFile_test file with k = 3. Save the output to myFile_classified.
_, training = dataio.read("myFile.csv")

headers, test_data = dataio.read("myFile_test.csv")

for vector in test_data:
	distances = [Distance(vector, v) for v in training]
	distances.sort()
	vector.gender = statistics.mode([d.vector.gender for d in distances[:3]])

dataio.write("myFile_classified.csv", headers, test_data)