#ifndef graph_h
#define graph_h

#include "trie_map.h"
#include <algorithm>
#include <exception>
#include <iostream>
#include <list>
#include <map>

class graph {

  private:
	enum state { UNVISITED, VISITED, COMPLETED };

	class edge;
	class vertex;

	typedef std::map<std::string, vertex*> map;				   // Map from string to vertex pointer
	typedef map::iterator map_iter;							   // Map iterator
	typedef map::const_iterator map_const_iter;				   // Map const interator
	typedef std::list<std::string> list;					   // List of strings
	typedef std::pair<std::string, vertex*> map_pair;		   // Pairs of strings and vertex pointers, derived from map
	typedef std::list<map_pair> list_pairs;					   // List of pairs
	typedef list_pairs::iterator list_pairs_iter;			   // List of pairs iterator
	typedef list_pairs::const_iterator list_pairs_const_iter;  // List of pairs const interator

	struct vertex {
		// The correct data structure to use here would be unordered_set<std::string>, but Moodle doesn't support C++11 for some reason, so I instead used list which is slower for checking if an edge already exists.
		list_pairs neighbours;
		vertex();
	};

	// The correct data structure to use here would be unordered_map<std::string, vertex*> since the order of the edges is not important, and access time is O(1) instead of O(lg n). But Moodle doesn't support it.
	map vertices;  // A map from strings to vertex pointers

	// Function to help topological_sort
	void topological_helper(const map_pair& v, trie_map<state>& visited, list& result) const;

  public:
	graph();														  // Constructor
	~graph();														  // Destructor
	void insert(const std::string& key);							  // Insert a string into the graph
	void link(const std::string& source, const std::string& target);  // Link vertex source to target
	void print() const;												  // Print the adjacency list of the graph
	list topological_sort() const;									  // Perform topological sort on the graph
};

#endif
