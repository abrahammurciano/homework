package WS1.Observables;

public class AlarmClockRecord {

	private int interval;
	private int remainingTime;
	private AlarmListener alarmListener;

	public AlarmClockRecord(int interval, AlarmListener alarmListener) {
		this.interval = interval;
		this.alarmListener = alarmListener;
		this.remainingTime = 0;
	}

	public int getRemainingTime() {
		return remainingTime;
	}

	public AlarmListener getListener() {
		return alarmListener;
	}

	public int getInterval() {
		return interval;
	}

	public void setRemainingTime(int remainingTime) {
		this.remainingTime = remainingTime;
	}

}
