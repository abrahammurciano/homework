package WS1.Observables;

import java.util.ArrayList;
import java.util.List;
import WS1.Observers.Observer;

public abstract class Observable<T> {
	private List<Observer<T>> observers;

	protected Observable() {
		this.observers = new ArrayList<>();
	}

	public void registerObserver(Observer<T> observer) {
		observers.add(observer);
		System.out.println(observer.getName() + " observes " + getName());
	}

	public void notifyObservers(T data) {
		for (Observer<T> observer : observers) {
			observer.update(data);
		}
	}

	public abstract String getName();

}
