package Airport;

public class Plane implements Movable, Comparable<Plane>{
	public static final int HEIGHT_LIMIT = 1500;
	int licenceNumber;
	Location source;
	Location destination;
	int maximalHeight;

	public Plane(int id, Location src, Location dst, int maxHeight) {
		licenceNumber = id;
		source = src;
		destination = dst;
		maximalHeight = maxHeight;
	}

	@Override
	public String toString() {
		return String.format("licence = %d, source = %s, destination = %s, maxHeight = %d",
				licenceNumber, source, destination, maximalHeight);
	}

	@Override
	public String getType() {
		return "Plane";
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
		return source.name();
	}

	@Override
	public void move() {
		Location temp = getSource();
		source = getDestination();
		destination = temp;
	}

	@Override
	public int compareTo(Plane that) {
		return Integer.compare(this.maximalHeight, that.maximalHeight);
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
		return Integer.compare(this.maximalHeight, ((Plane)that).maximalHeight) == 0;
	}

	@Override
	public int hashCode() {
		return Integer.valueOf(maximalHeight).hashCode();
	}
}
