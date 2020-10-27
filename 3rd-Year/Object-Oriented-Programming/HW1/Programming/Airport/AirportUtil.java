package Airport;

import java.util.ArrayList;
import java.util.Arrays;

public class AirportUtil {
	public static final Location[] LOCATIONS = Location.values();

	public static <T extends Comparable<T>> void sortTransport(T[] transports) {
		Arrays.sort(transports);
	}

	static String reportAll(Movable[] movables) {
		ArrayList<String> buffer = new ArrayList<>();
		for (Movable m : movables) {
			buffer.add(String.format("%s %d going from %s to %s. Currently in %s", m.getType(),
					m.getId(), m.getSource(), m.getDestination(), m.getCurrentLocation()));
		}
		return String.join("\n", buffer);
	}

	private AirportUtil() {
	}
}
