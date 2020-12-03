package src;

import java.util.Arrays;
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
			// uses wrappers so they can be modified from the lambdas
			Wrapper<Double> min_distance = new Wrapper<>(Double.MAX_VALUE);
			Wrapper<Set<T>> cluster1 = new Wrapper<>();
			Wrapper<Set<T>> cluster2 = new Wrapper<>();

			// for each cluster
			clusters.stream().forEach(cluster -> {
				// for each element in that cluster
				cluster.stream().forEach(element -> {
					// compare it to every other cluster
					clusters.stream().forEach(other_cluster -> {
						// don't compare any cluster to itself
						if (cluster == other_cluster) {
							return;
						}
						// for each element in the other cluster
						other_cluster.stream().forEach(other_element -> {
							// check the distance between the two chosen elements in the two chosen
							// clusters
							double distance = element.distance(other_element);
							// if its smaller than the previously found shortest distance, update
							// the shortest distance, and the two clusters which contain the closest
							// elements
							if (distance < min_distance.get()) {
								min_distance.set(distance);
								cluster1.set(cluster);
								cluster2.set(other_cluster);
							}
						});
					});
				});
			});

			// if the shortest distance found between clusters exceeds the threshold, we're done
			if (min_distance.get() > threshold) {
				return clusters;
			}

			// remove the two closest clusters
			clusters.remove(cluster2.get());
			// must be removed then added, because union will change the hash
			clusters.remove(cluster1.get());
			// union them
			cluster1.get().addAll(cluster2.get());
			// insert the union back into the set
			clusters.add(cluster1.get());
		}

		return clusters;
	}
}
