package WS1.Observers;

public class MSPressObserver implements Observer<Integer> {

	private MonitoringScreen monitoringScreen;

	public MSPressObserver(MonitoringScreen monitoringScreen) {
		this.monitoringScreen = monitoringScreen;
	}

	@Override
	public void update(Integer data) {
		monitoringScreen.displayPressure(data);
	}

	@Override
	public String getName() {
		return "pressure observer";
	}

}
