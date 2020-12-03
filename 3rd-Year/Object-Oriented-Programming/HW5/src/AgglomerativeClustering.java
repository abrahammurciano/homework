package src;

import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Set;
import java.util.stream.Collectors;


public class AgglomerativeClustering<T extends Clusterable<T>> implements Clustering<T> {
	double threshold;

	public AgglomerativeClustering(double threshold) {
		this.threshold = threshold;
	}

	// takes a set of elements and partitions them into clusters
	public Set<Set<T>> clusterSet(Set<T> elements) {
		// make each element its own cluster
		Set<Set<T>> clusters = elements.stream().map(e -> new HashSet<>(Arrays.asList(e)))
				.collect(Collectors.toSet());

		// if every element ends up in the same cluster, we're done
		while (clusters.size() != 1) {
			// extract the two most similar clusters, cluster1, cluster2 from clusters

			// map each cluster to its closest cluster
			Pair<Set<T>, Pair<Set<T>, Double>> closest_pair = clusters.stream()
					.map(cluster -> new Pair<Set<T>, Pair<Set<T>, Double>>(cluster,
							clusters.stream() // convert set to stream
									// remove cluster from stream
									.filter(other_cluster -> cluster != other_cluster)
									// convert each cluster to tuple with distance
									.map(other_cluster -> new Pair<Set<T>, Double>(
											// make the other cluster the first value of the pair
											other_cluster,
											// get the distance between cluster and other_cluster
											cluster.stream().map(
													// find shortest distance between element some
													// other_element
													element -> other_cluster.stream()
															.map(other_element -> other_element
																	.distance(element))
															.min(Comparator.naturalOrder()).get())
													.min(Comparator.naturalOrder()).get()))
									.min(Comparator.comparing(pair -> pair.y)).get()))
					.min(Comparator.comparing(pair -> pair.y.y)).get();

			// uses wrappers so they can be modified from the lambdas
			double min_distance = closest_pair.y.y;
			Set<T> cluster1 = closest_pair.x;
			Set<T> cluster2 = closest_pair.y.x;

			// if the shortest distance found between clusters exceeds the threshold, we're done
			if (min_distance > threshold) {
				return clusters;
			}

			// remove the two closest clusters
			clusters.remove(cluster2);
			// must be removed then added, because union will change the hash
			clusters.remove(cluster1);
			// union them
			cluster1.addAll(cluster2);
			// insert the union back into the set
			clusters.add(cluster1);
		}

		return clusters;
	}
}
