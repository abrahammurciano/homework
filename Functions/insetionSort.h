#ifndef insetionSort_h
#define insetionSort_h

// Function that performs insertion sort on given array
void insetionSort(int array[], int size) {
	int notSorted = 1;
	while (notSorted < size) {
		int val = array[notSorted];

		// Perform binary search to find the index that val should be moved to within the sorted
		// section of the array
		int min = 0, max = notSorted;
		int mid;  // mid is the average of min and max

		do {
			mid = (min + max) / 2;   // mid is the average of min and max
			if (val < array[mid]) {  // If val is between positions 0 and mid-1
				max = mid;			 // max is the value of mid
			} else {				 // If val is between positions mid and max
				min = mid;			 // min is now mid
			}
		} while (max - min > 1);  // When max and min have a difference of 1, the search is over

		int index = max;  // The index to place val is max

		for (int i = notSorted++; i > index; i--) {
			array[i] = array[i - 1];
		}
		array[index] = val;
	}
}

#endif