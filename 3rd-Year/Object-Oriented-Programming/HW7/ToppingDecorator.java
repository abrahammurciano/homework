public abstract class ToppingDecorator implements Hamburger {
	Hamburger inner_hamburger;

	ToppingDecorator(Hamburger hamburger) {
		inner_hamburger = hamburger;
	}
}
