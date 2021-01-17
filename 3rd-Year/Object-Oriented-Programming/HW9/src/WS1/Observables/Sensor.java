package WS1.Observables;

public abstract class Sensor extends Observable<Integer> {

	private Integer lastReading;
	private int interval;
	private String type;

	protected Sensor(String type, int interval) {
		this.type = type;
		this.interval = interval;
		lastReading = null;
	}

	protected abstract int read();

	public void check() {
		int reading = read();
		if (lastReading == null || reading != lastReading)
			notifyObservers(reading);
		lastReading = reading;
	}

	@Override
	public String getName() {
		return type;
	}

}
