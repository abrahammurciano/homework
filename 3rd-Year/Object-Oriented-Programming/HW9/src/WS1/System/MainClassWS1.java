package WS1.System;

import WS1.Nimbus1.Nimbus1Clock;
import WS1.Observables.WeatherMonitoringSystem;
import WS1.Observers.Log;
import WS1.Observers.MonitoringScreen;

public class MainClassWS1 {

	public static void main(String[] args) {
		WeatherMonitoringSystem.theInstance();

		new MonitoringScreen();
		new Log();

	}
}
