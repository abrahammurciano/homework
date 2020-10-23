package Airport;
import java.util.Random;

import static Airport.AirportUtil.LOCATIONS;
import static Airport.Plane.HEIGHT_LIMIT;
import static Airport.Train.PASSENGER_LIMIT;
import static Airport.Train.STATION_LIMIT;

public class AirportUtilTest {
    static final int TOTAL = 5;
    static final int ID_BOUND = 10000;
    public static void main(String[] args) {
        Random r = new Random(2);
        Train[] trains = initializeTrains(r);
        printTrains(trains);
        Plane[] planes = initializePlanes(r);
        printPlanes(planes);


        System.out.println("---Sorting trains...---\n");
        AirportUtil.sortTransport(trains);
        // prints the reports of all the trains
        System.out.println(AirportUtil.reportAll(trains));

        System.out.println("---Sorting planes...---\n");
        //sort planes
        AirportUtil.sortTransport(planes);
        // prints the reports of all the planes
        System.out.println(AirportUtil.reportAll(planes));


        // Creates an array of Movable objects
        Movable[] movables = new Movable[TOTAL * 2];

        //initializes an array of Movable objects (trains and planes)
        for (int i = 0; i < trains.length; i++) {
            movables[2 * i] = trains[i];
            movables[2 * i + 1] = planes[i];
        }

        System.out.println("---All together...---\n");
        // prints the reports of all the trains and planes
        System.out.println(AirportUtil.reportAll(movables));

        for (int j = 0; j<4; j++) {
            //cause all the planes and trains to move
            for (int i = 0; i < movables.length; i++) {
                movables[i].move();
            }

            System.out.println("---All together after move...---\n");
            // prints the reports of all the trains and planes after move
            System.out.println(AirportUtil.reportAll(movables));
        }
    }

    private static Train[] initializeTrains(Random r) {
        Train[] trains = new Train[TOTAL];
        //Initializes array of trains
        for (int i = 0; i < TOTAL; i++) {
            int id = r.nextInt(ID_BOUND);
            Location src = LOCATIONS[r.nextInt(LOCATIONS.length)];
            Location dst = LOCATIONS[r.nextInt(LOCATIONS.length)];
            int numberOfStations = r.nextInt(STATION_LIMIT);
            int maxPassengers = r.nextInt(PASSENGER_LIMIT);
            trains[i] = new Train(id, src, dst, numberOfStations, maxPassengers);
        }

        return trains;
    }

    private static Plane[] initializePlanes(Random r) {
        Plane[] planes = new Plane[TOTAL];
        //Initializes array of planes
        for (int i = 0; i < TOTAL; i++) {
            int id = r.nextInt(ID_BOUND);
            Location src = LOCATIONS[r.nextInt(LOCATIONS.length)];
            Location dst = LOCATIONS[r.nextInt(LOCATIONS.length)];
            int maxHeight = r.nextInt(HEIGHT_LIMIT);
            planes[i] = new Plane(id, src, dst, maxHeight);
        }

        return planes;
    }

    public static void printTrains(Train [] trains){
        for (int i = 0; i < TOTAL; i++) {
            System.out.println("Details about Train number " + (i + 1));
            System.out.println(trains[i]);
        }
    }

    public static void printPlanes(Plane [] planes){
        for (int i = 0; i < TOTAL; i++) {
            System.out.println("Details about Plane number " + (i + 1));
            System.out.println(planes[i]);
        }
    }

}//close class
