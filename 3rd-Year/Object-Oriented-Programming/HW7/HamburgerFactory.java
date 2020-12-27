
public class HamburgerFactory {

	private HamburgerFactory() {
		throw new IllegalStateException("Utility class");
	}

	public static Hamburger createHamburger(String code) {
		switch (code) {
			case "cl":
				return new ClassicHamburger();
			case "sp":
				return new SpicyHamburger();
			case "la":
				return new LambHamburger();
			case "hm":
				return new HomemadeHamburger();
			default:
				throw new RuntimeException("wrong Hamburger");
		}
	}
}
