public class FriedEggDecorator extends ToppingDecorator {

	FriedEggDecorator(Hamburger hamburger) {
		super(hamburger);
	}

	@Override
	public String serve() {
		return inner_hamburger.serve() + " with fried egg";
	}

}
