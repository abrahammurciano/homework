
public class ToppingFactory {

	private ToppingFactory() {
		throw new IllegalStateException("Utility class");
	}

	public static Hamburger addTopping(Hamburger hamburger, String code) {
		switch (code) {
			case "ch":
				return new ChipsDecorator(hamburger);
			case "or":
				return new OnionRingsDecorator(hamburger);
			case "sa":
				return new SaladDecorator(hamburger);
			case "fe":
				return new FriedEggDecorator(hamburger);
			default:
				throw new RuntimeException("wrong Topping");
		}
	}
}
