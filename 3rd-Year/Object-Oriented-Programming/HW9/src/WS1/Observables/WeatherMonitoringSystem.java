package WS1.Observables;

import WS1.Nimbus1.Nimbus1Clock;
import WS1.Nimbus1.PressureSensor;
import WS1.Nimbus1.TemperatureSensor;
import WS1.Observers.Observer;
import WS1.Observers.Trend;

public class WeatherMonitoringSystem {

	private static WeatherMonitoringSystem singleton;

	private TemperatureSensor temperatureSensor;
	private PressureSensor pressureSensor;
	private PressureTrendSensor pressureTrendSensor;

	private WeatherMonitoringSystem() {
		System.out.println("WeatherMonitoringSystem was created");
		Nimbus1Clock.theInstance();
		pressureSensor = new PressureSensor(1100);
		temperatureSensor = new TemperatureSensor(700);
		pressureTrendSensor = new PressureTrendSensor(pressureSensor);
	}

	public static WeatherMonitoringSystem theInstance() {
		if (singleton == null) {
			singleton = new WeatherMonitoringSystem();
		}
		return singleton;
	}

	public void addTemperatureObserver(Observer<Integer> observer) {
		temperatureSensor.registerObserver(observer);
	}

	public void addPressureObserver(Observer<Integer> observer) {
		pressureSensor.registerObserver(observer);
	}

	public void addPressureTrendObserver(Observer<Trend> observer) {
		pressureTrendSensor.registerObserver(observer);
	}

}
