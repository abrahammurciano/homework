package WS1.Nimbus1;

import java.util.Random;

public class RandomSupplier {
	private static Random rnd = new Random(1);

	private RandomSupplier() {
	}

	public static Random getRnd() {
		return rnd;
	}
}
