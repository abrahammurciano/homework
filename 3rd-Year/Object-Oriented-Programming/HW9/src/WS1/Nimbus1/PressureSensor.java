package WS1.Nimbus1;

import java.util.Random;
import WS1.Observables.Sensor;

public class PressureSensor extends Sensor {
	private Random random;

	public PressureSensor(int interval) {
		super(interval);
		random = new Random();
	}

	@Override
	protected int read() {
		return random.nextInt(101) + 950; // [950, 1050]
	}

	@Override
	public String getName() {
		return "pressure";
	}
}
