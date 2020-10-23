package Airport;

public interface Movable {
    String getType();
    int getId();
    Location getSource();
    Location getDestination();
    String getCurrentLocation();
    void move();
}
