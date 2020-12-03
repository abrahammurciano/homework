package src;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.Optional;
import java.util.Set;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.Stream;

public class BitArray implements Clusterable<BitArray> {
	private List<Boolean> bits;

	// construct bit array from comma-separated string of "true" and "false"
	public BitArray(String str) {
		bits = Arrays.stream(str.split(",")) // convert array of strings to stream
				.map(Boolean::parseBoolean) // convert each string to boolean
				.collect(Collectors.toList()); // convert back to list
	}

	public BitArray(Boolean[] bits) {
		this.bits = Arrays.asList(bits);
	}

	public int size() {
		return bits.size();
	}

	// calculate hamming distance
	@Override
	public double distance(BitArray other) {
		if (bits.size() != other.bits.size()) {
			throw new IllegalArgumentException(
					"Error: Hamming distance is only defined for arrays of equal length.");
		}
		return IntStream.range(0, bits.size()) // for i from 0 to size
				.filter(i -> !bits.get(i).equals(other.bits.get(i))) // keep only the indices where
																		// they differ
				.count(); // count them to get the hamming distance
	}

	@Override
	public String toString() {
		return bits.toString();
	}

	// take a filename and parse each line into a bit array
	public static Set<BitArray> readBitArrays(String path) throws IOException {
		try (Stream<String> lines = Files.lines(Paths.get(path))) {
			// convert each line into a bit array
			List<BitArray> arrays =
					new ArrayList<>(lines.map(BitArray::new).collect(Collectors.toList()));
			// find the longest bit array
			Optional<BitArray> longest = arrays.stream().max(Comparator.comparing(BitArray::size));
			if (longest.isPresent()) {
				// remove shorter ones
				return arrays.stream().filter(a -> a.size() == longest.get().size())
						.collect(Collectors.toSet()); // convert to set
			}
			return new HashSet<>();
		}
	}

}
