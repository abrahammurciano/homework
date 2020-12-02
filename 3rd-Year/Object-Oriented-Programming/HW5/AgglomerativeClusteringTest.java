import java.io.IOException;
import java.util.Set;

import static org.junit.Assert.assertEquals;


public class AgglomerativeClusteringTest {
	// TODO: Set the correct value to the paths and thresholds
	private static final String POINTS_PATH = "points.txt";
	private static final String BITARRAYS_PATH = "bitArrays.txt";
	private static final double TWO_D_POINT_CLUSTERING_THRESHOLD = 0;
	private static final double BIT_ARRAY_CLUSTERING_THRESHOLD = 0;

	public static void main(String[] args) throws IOException {
		Clustering<TwoDPoint> twoDPointClustering =
				new AgglomerativeClustering<>(TWO_D_POINT_CLUSTERING_THRESHOLD);
		Set<TwoDPoint> points = TwoDPoint.readPoints(POINTS_PATH);
		Set<Set<TwoDPoint>> pointsClusterSet = twoDPointClustering.clusterSet(points);
		System.out.println("The number of 2d point clusters is: " + pointsClusterSet.size());
		assertEquals(3, pointsClusterSet.size());

		AgglomerativeClustering<BitArray> bitArrayClustering =
				new AgglomerativeClustering<>(BIT_ARRAY_CLUSTERING_THRESHOLD);
		Set<BitArray> bitArrays = BitArray.readBitArrays(BITARRAYS_PATH);
		Set<Set<BitArray>> bitArrayClusterSet = bitArrayClustering.clusterSet(bitArrays);
		System.out.println("The number of bitArray clusters is: " + bitArrayClusterSet.size());
		assertEquals(2, bitArrayClusterSet.size());
	}

}
