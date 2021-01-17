package WS1.Observers;

public interface Observer<T> {

	public void update(T data);

	public String getName();

}
