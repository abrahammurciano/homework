package src;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;


public class AgglomerativeClustering<T extends Clusterable<T>> implements Clustering<T> {
	double threshold;

	public AgglomerativeClustering(double threshold) {
		this.threshold = threshold;
	}

	public Set<Set<T>> clusterSet(Set<T> elements) {
		Set<Set<T>> clusters = elements.stream().map(e -> new HashSet<>(Arrays.asList(e)))
				.collect(Collectors.toSet());

		while (clusters.size() != 1) {
			// extract the two most similar clusters, c1,c2 from clusters
			double[] min_distance = {Double.MAX_VALUE};
			List<Set<T>> cluster1 = new ArrayList<>();
			cluster1.add(null);
			List<Set<T>> cluster2 = new ArrayList<>();
			cluster2.add(null);
			clusters.stream().forEach(cluster -> {
				cluster.stream().forEach(element -> {
					clusters.stream().forEach(other_cluster -> {
						if (cluster == other_cluster) {
							return;
						}
						other_cluster.stream().forEach(other_element -> {
							double distance = element.distance(other_element);
							if (distance < min_distance[0]) {
								min_distance[0] = distance;
								cluster1.set(0, cluster);
								cluster2.set(0, other_cluster);
							}
						});
					});
				});
			});
			Set<T> c1 = cluster1.get(0);
			Set<T> c2 = cluster2.get(0);

			if (min_distance[0] > threshold) {
				return clusters;
			}

			clusters.remove(c2);
			clusters.remove(c1);
			c1.addAll(c2);
			clusters.add(c1);
		}

		return clusters;
	}
}
