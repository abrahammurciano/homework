#include "graph.h"
#include <exception>

// =======================
// Vertex member functions
// =======================

// Vertex constructor
graph::vertex::vertex() {}

// ======================
// Graph member functions
// ======================

// Graph constructor
graph::graph() {}

// Graph destructor
graph::~graph() {
	for (map_iter v = vertices.begin(); v != vertices.end(); ++v) {
		delete (*v).second;
	}
}

// Insert a string into the graph
void graph::insert(const std::string& key) {
	if (vertices.count(key) > 0) {	// If the key already exists in vertices
		throw std::runtime_error("Error: Could not insert key. The key provided already exists.");
	}
	// Create a new vertex with the key `key` in the string to vertex* map and assign it a new vertex with no edges
	vertices[key] = new vertex;
}

// Link vertex source to target
void graph::link(const std::string& source, const std::string& target) {
	vertex* s = vertices.at(source);			   // Vertex that `source` corresponds to
	map_iter target_iter = vertices.find(target);  // Vertex iterator for `target`
	if (target_iter == vertices.end()) {		   // If find failed, `target` does not exist
		throw std::runtime_error("Error: Could not create edge. Second key does not exist.");
	}
	const map_pair& target_pair = *target_iter;	 // Dereference the iterator
	if (std::find(s->neighbours.begin(), s->neighbours.end(), target_pair) != s->neighbours.end()) {
		// Find `target` in neighbours. If found, then the link already exists
		throw std::runtime_error("Error: Could not link keys. The keys provided are already linked.");
	}
	s->neighbours.push_back(target_pair);  // Add vertex to `source` neighbours
}

void graph::print() const {
	// For each element in vertices
	for (map::const_iterator i = vertices.begin(); i != vertices.end(); ++i) {
		std::cout << (*i).first << ':';	 // Print the key
		vertex* v = (*i).second;		 // v is pointer to vertex
		for (list_pairs_const_iter pair_i = v->neighbours.begin(); pair_i != v->neighbours.end(); ++pair_i) {
			std::cout << ' ' << (*pair_i).first;  // Print all of its neighbours
		}
		std::cout << std::endl;
	}
}

// Sort the vertices in the graph such that every vertax which points to another comes before the vertices which it points to
graph::list graph::topological_sort() const {
	// An unordered map should be used for the auxiliary data, such as colours. This data is not inherently part of each vertex, so it does not belong as a class member. Since Moodle doesn't support unordered maps, I implemented a trie map inheriting from the trie from assignment 2 for improved time complexity.

	// States are UNVISITED, VISITED and COMPLETED
	trie_map<state> visited;  // Stores the state of each vertex's discovery
	list result;			  // Will hold a list of strings to return in sorted order

	for (map_const_iter v = vertices.begin(); v != vertices.end(); ++v) {
		visited[(*v).first] = UNVISITED;  // Set every vertex to UNVISITED
	}

	for (map_const_iter v = vertices.begin(); v != vertices.end(); ++v) {  // Iterate over vertices
		if (visited[(*v).first] == UNVISITED) {							   // If v is not visited
			// Call the helper function to recursively visit the neighbouring vertices in depth first order
			topological_helper(*v, visited, result);
		}
	}
	return result;	// Return the sorted list
}

// Helper function for `topological_sort`. Given a vertex it will recursively perform DFS to reach all the vertices which have a path from that vertex.
void graph::topological_helper(const map_pair& v, trie_map<state>& visited, list& result) const {
	visited[v.first] = VISITED;	 // Mark vertex as visited

	// Go over each neighbour of v
	for (list_pairs_const_iter p = v.second->neighbours.begin(); p != v.second->neighbours.end(); ++p) {
		if (visited[(*p).first] == UNVISITED) {		  // If v was not visited
			topological_helper(*p, visited, result);  // Recursively call this function on v
		} else if (visited[(*p).first] == VISITED) {
			// Otherwise if it is visited but not completed, there are cycles
			throw std::runtime_error("Error: Topological sort cannot be performed on a cyclic graph.");
		}
	}

	// Once all of v's edges have been traversed, put v at the front of the list
	result.push_front(v.first);
	visited[v.first] = COMPLETED;  // Mark v as completed
}
