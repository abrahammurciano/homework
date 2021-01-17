package WS1.Observables;

import java.util.ArrayList;

public class AlarmClock {
	public static final int CLOCK_INTERVAL_MILLIS = 100;
	protected static AlarmClock instance = null;
	private ArrayList<AlarmClockRecord> itsAlarmClockRecords = new ArrayList<>();

	protected AlarmClock() {
	}

	public static AlarmClock theInstance() {
		if (null == instance) {
			instance = new AlarmClock();
		}
		return instance;
	}

	protected void tic() {
		for (AlarmClockRecord record : itsAlarmClockRecords) {
			if (record.getRemainingTime() - CLOCK_INTERVAL_MILLIS <= 0) {
				record.getListener().wakeUp();
				record.setRemainingTime(record.getInterval());
			} else {
				record.setRemainingTime(record.getRemainingTime() - CLOCK_INTERVAL_MILLIS);
			}
		}
	}

	public void register(int interval, AlarmListener alarmListener) {
		itsAlarmClockRecords.add(new AlarmClockRecord(interval, alarmListener));
	}

}
