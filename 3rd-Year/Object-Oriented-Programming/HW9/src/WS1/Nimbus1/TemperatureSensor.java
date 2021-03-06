package WS1.Nimbus1;

import java.util.Random;
import WS1.Observables.Sensor;

public class TemperatureSensor extends Sensor {

	private Random random;

	public TemperatureSensor(int interval) {
		super(interval);
		random = new Random();
	}

	@Override
	protected int read() {
		return random.nextInt(41);
	}

	@Override
	public String getName() {
		return "temperature";
	}

}
