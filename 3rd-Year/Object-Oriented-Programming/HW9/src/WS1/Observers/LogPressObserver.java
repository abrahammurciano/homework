package WS1.Observers;

public class LogPressObserver implements Observer<Integer> {

	private Log log;

	public LogPressObserver(Log log) {
		System.out.println("LogPressObserver was created");
		this.log = log;
	}

	@Override
	public void update(Integer data) {
		log.displayPressure(data);
	}

	@Override
	public String getName() {
		return "LogPressObserver";
	}

}
