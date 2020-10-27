package Airport;

public class Train implements Comparable<Train>, Movable {
	public static final int PASSENGER_LIMIT = 500;
	public static final int STATION_LIMIT = 5;
	int licenceNumber;
	Location source;
	Location destination;
	int numberOfStations;
	int currentStation;
	int maximalPassenger;

	public Train(int id, Location src, Location dst, int numOfStations, int maxPassengers) {
		licenceNumber = id;
		source = src;
		destination = dst;
		numberOfStations = numOfStations;
		currentStation = 0;
		maximalPassenger = maxPassengers;
	}

	@Override
	public String toString() {
		return String.format("licence = %d, source = %s, destination = %s, station = %d, maxPassengers = %d",
				licenceNumber, source, destination, currentStation, maximalPassenger);
	}

	@Override
	public String getType() {
		return "Train";
	}

	@Override
	public int getId() {
		return licenceNumber;
	}

	@Override
	public Location getSource() {
		return source;
	}

	@Override
	public Location getDestination() {
		return destination;
	}

	@Override
	public String getCurrentLocation() {
		if (currentStation == 0) {
			return source.name();
		}
		return String.format("station %d between %s and %s.", currentStation, source.name(), destination.name());
	}

	@Override
	public void move() {
		++currentStation;
		if (currentStation == numberOfStations) {
			Location temp = getSource();
			source = getDestination();
			destination = temp;
			currentStation = 0;
		}
	}

	@Override
	public int compareTo(Train that) {
		return Integer.compare(this.maximalPassenger, that.maximalPassenger);
	}

	@Override
	public boolean equals(Object that) {
		if (this == that) {
			return true;
		}
		if (that == null) {
			return false;
		}
		if (this.getClass() != that.getClass()) {
			return false;
		}
		return Integer.compare(this.maximalPassenger, ((Train) that).maximalPassenger) == 0;
	}

	@Override
	public int hashCode() {
		return Integer.valueOf(maximalPassenger).hashCode();
	}
}
