package src;

public class Wrapper<T> {
	private T obj;

	public Wrapper() {
		obj = null;
	}

	public Wrapper(T other) {
		set(other);
	}

	public void set(T other) {
		obj = other;
	}

	public T get() {
		return obj;
	}
}
