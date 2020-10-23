package Airport;

import java.util.ArrayList;

public class AirportUtil {
    public static final Location[] LOCATIONS = Location.values();
    public static void sortTransport(Comparable[] transport){
        // TODO: implement;
    }
    static String reportAll (Movable[] movables) {
        ArrayList<String> buffer = new ArrayList<>();
        for (Movable m: movables) {
            // TODO: implement;
        }
        return String.join("\n",buffer);
    }
}
