package WS1.Nimbus1;

import WS1.Observables.AlarmClock;

public class Nimbus1Clock extends AlarmClock {
	protected Nimbus1Clock() {
		new Thread("polling Alarm Clock Records") {
			public void run() {
				System.out.println("running clock thread ---");
				for (int i = 0; i < 60; i++) {
					// System.out.println("Thread: " + getName() + " running");
					tic();
					try {
						Thread.sleep(CLOCK_INTERVAL_MILLIS);
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
				}
			}
		}.start();
	}

	public static AlarmClock theInstance() {
		if (null == instance)
			instance = new Nimbus1Clock();
		return instance;
	}
}
