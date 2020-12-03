package src;

import java.nio.file.Paths;
import java.io.IOException;
import java.nio.file.Files;
import java.util.Set;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class TwoDPoint implements Clusterable<TwoDPoint> {
	double x;
	double y;

	public TwoDPoint(String str) {
		String[] arr = str.split(",");
		x = Double.parseDouble(arr[0]);
		y = Double.parseDouble(arr[1]);
	}

	public TwoDPoint(double x, double y) {
		this.x = x;
		this.y = y;
	}

	@Override
	public double distance(TwoDPoint other) {
		return Math.sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
	}

	@Override
	public String toString() {
		return x + ", " + y;
	}

	public static Set<TwoDPoint> readPoints(String path) throws IOException {
		try (Stream<String> lines = Files.lines(Paths.get(path));) {
			return lines.map(TwoDPoint::new).collect(Collectors.toSet());
		}
	}

	@Override
	public boolean equals(Object other) {
		if (other == null) {
			return false;
		}

		if (getClass() != other.getClass()) {
			return false;
		}

		TwoDPoint otherP = (TwoDPoint) other;
		return (otherP.x == x && otherP.y == y);
	}

	@Override
	public int hashCode() {
		return Double.hashCode(x) ^ Double.hashCode(y);
	}
}
