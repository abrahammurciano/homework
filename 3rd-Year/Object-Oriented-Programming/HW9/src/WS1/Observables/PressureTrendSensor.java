package WS1.Observables;

import WS1.Nimbus1.PressureSensor;
import WS1.Observers.Observer;
import WS1.Observers.Trend;

public class PressureTrendSensor extends Observable<Trend> implements Observer<Integer> {

	private Integer read1;
	private Integer read2;
	private Trend trend1;
	private Trend trend2;

	public PressureTrendSensor(PressureSensor pressureSensor) {
		super();
		pressureSensor.registerObserver(this);
		read1 = null;
	}

	public void check() {
		if (trend1 == null || trend2 == null) {
			return;
		}
		if (trend2 != trend1) {
			notifyObservers(trend2);
		}
	}

	public Trend calc() {
		if (read1 != null) {
			if (read1 < read2) {
				return Trend.RISING;
			} else if (read1 > read2) {
				return Trend.FALLING;
			} else {
				return Trend.STABLE;
			}
		} else {
			return null;
		}
	}

	@Override
	public void update(Integer data) {
		read1 = read2;
		read2 = data;
		trend1 = trend2;
		trend2 = calc();
		check();
	}

	@Override
	public String getName() {
		return "pressure trend";
	}

}
