package WS1.Observers;

public class MSTempObserver implements Observer<Integer> {

	private MonitoringScreen monitoringScreen;

	public MSTempObserver(MonitoringScreen monitoringScreen) {
		System.out.println("MSTempObserver was created");
		this.monitoringScreen = monitoringScreen;
	}

	@Override
	public void update(Integer data) {
		monitoringScreen.displayTemperature(data);
	}

	@Override
	public String getName() {
		return "MSTempObserver";
	}

}
