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

	public BitArray(String str) {
		bits = new ArrayList<>(Arrays.stream(str.split(",")).map(Boolean::parseBoolean)
				.collect(Collectors.toList()));
	}

	public BitArray(Boolean[] bits) {
		this.bits = Arrays.asList(bits);
	}

	public int size() {
		return bits.size();
	}

	@Override
	public double distance(BitArray other) {
		if (bits.size() != other.bits.size()) {
			throw new IllegalArgumentException(
					"Error: Hamming distance is only defined for arrays of equal length.");
		}
		return IntStream.range(0, bits.size()).filter(i -> !bits.get(i).equals(other.bits.get(i)))
				.count();
	}

	@Override
	public String toString() {
		return bits.toString();
	}

	public static Set<BitArray> readBitArrays(String path) throws IOException {
		try (Stream<String> lines = Files.lines(Paths.get(path))) {
			List<BitArray> arrays =
					new ArrayList<>(lines.map(BitArray::new).collect(Collectors.toList()));
			Optional<BitArray> longest = arrays.stream().max(Comparator.comparing(BitArray::size));
			if (longest.isPresent()) {
				return arrays.stream().filter(a -> a.size() == longest.get().size())
						.collect(Collectors.toSet());
			}
		}
		return new HashSet<>();
	}

}
