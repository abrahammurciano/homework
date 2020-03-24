#ifndef trie_map_h
#define trie_map_h

#include "trie.h"

template <class T>
class trie_map : public trie {
  private:
	class node : public trie::node {
	  private:
		T* value;  // Value that each key maps to

		node(node* parent, int index);
		~node();
		T& set_terminal(T* value);	// Sets the node terminal to true and sets the data

		using trie::node::append;

	  public:
		T& append(std::string suffix, T* value = 0);  // Append a suffix to this node
	};

	using trie::insert;

  public:
	trie_map();
	void insert(const std::string& s, const T& value);
	T& operator[](std::string s);  // Access elements associatively
};

template <class T>
trie_map<T>::node::node(node* parent, int index) : trie::node(parent, index) {}

template <class T>
trie_map<T>::node::~node() {
	delete value;
}

template <class T>
T& trie_map<T>::node::set_terminal(T* value) {
	if (!terminal) {  // If this node is not the end of a word, make it one
		terminal = true;
		if (!value) {  // If pointer is null, allocate memory for it
			value = new T;
		}
		this->value = value;
	}
	return *(this->value);	// Return new value
}

template <class T>
T& trie_map<T>::node::append(std::string suffix, T* value) {
	// Append the first letter to this node
	int index = char_to_int(suffix[0]);			  // Get the index corresponding to the first character
	if (!children[index]) {						  // If that character doesn't exist
		children[index] = new node(this, index);  // Create a node in that position
	}
	if (suffix.size() == 1) {								   // If the last character is being appended
		return ((node*)children[index])->set_terminal(value);  // Make the node a terminal node
	}
	// If there are more characters to append, recursively append the rest of the characters to the newly appended node
	return ((node*)children[index])->append(suffix.substr(1), value);
}

template <class T>
trie_map<T>::trie_map() : trie() {}

// Insert a new key value pair into the trie
template <class T>
void trie_map<T>::insert(const std::string& s, const T& value) {
	T* pointer = new T(value);			// Allocate a new value
	((node*)root)->append(s, pointer);	// Call append function to insert the data
}

// Access each value by passing the key. associative.
template <class T>
T& trie_map<T>::operator[](std::string s) {
	return ((node*)root)->append(s, 0);
}

#endif
