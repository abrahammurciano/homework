/*
 * File Name:				main.cpp
 * Program Description:		Tries implementation
 * Course Name:				Data Structures 2
 * Assignment Number:		2
 * Question Number:			1
 * Author:					Abraham Murciano
 */

#include "trie.h"

// Given a character, return the corresponding index
int trie::node::char_to_int(char c) {
	if (c >= 'A' && c <= 'Z') {			// If c is an upper case letter
		return c - 'A';					// Subtract 'A' and return
	} else if (c >= 'a' && c <= 'z') {	// If c is a lower case letter
		return c - 'a';					// Subtract 'a' and return
	} else {							// Otherwise it's not a letter, so throw an error
		throw string("Error: Invalid character '") + c + string("'.");
	}
}

// Given an index, return the corresponding lower case character
char trie::node::int_to_char(int index) {
	return index + 'a';
}

// Returns weather or not the node has children
bool trie::node::has_children() {
	for (int i = 0; i < alphabet_size; ++i) {  // Loop through the children array
		if (children[i]) {					   // If one of the children pointers is not null
			return true;					   // Then the node has at least one child
		}
	}
	return false;  // Otherwise, it has no children
}

// Constructor
trie::node::node(node* parent, int index)
	: parent(parent), index(index), terminal(false) {
	children = new node*[alphabet_size];  // Allocate dynamic array for the children
}

// Destructor
trie::node::~node() {
	for (int i = 0; i < alphabet_size; ++i) {  // Iterate over children array
		delete children[i];					   // Delete each child pointer
	}
	delete[] children;	// Delete the array of children
}

// Append a suffix to this node
void trie::node::append(string suffix) {
	// Append the first letter to this node
	int index = char_to_int(suffix[0]);			  // Get the index corresponding to the first character
	if (!children[index]) {						  // If that character doesn't exist
		children[index] = new node(this, index);  // Create a node in that position
	}
	if (suffix.size() == 1) {			   // If the last character is being appended
		children[index]->terminal = true;  // Make the node a terminal node
		return;
	}
	// If there are more characters to append, recursively append the rest of the characters to the newly appended node
	children[index]->append(suffix.substr(1));
}

// Remove the word ending at this node from the trie
bool trie::node::remove() {
	if (!terminal) {   // If the node isn't a terminal node, the word doesn't exist
		return false;  // If nothing was removed, return false
	}
	terminal = false;  // Mark this node as a non-terminal

	// Make two node pointers. one for the current node, one for the parent node
	node *_node = this, *_parent = parent;
	while (_parent && !_node->has_children() && !_node->terminal) {
		// So long as the current node isn't a terminal and has no children, it is a loose end, so should be deleted
		_parent->children[_node->index] = nullptr;	// Make the parent forget that it has that child
		delete _node;								// Deallocade the current node
		// Go one step up the tree to repeat for the net iteration
		_node = _parent;			// Make the current node equal to the parent
		_parent = _parent->parent;	// And make the parent equal to the grandparent
	}
	return true;  // If something was removed, return true
}

// Find the node that leads to the given word or prefix
trie::node* trie::node::find_node(string s) {
	if (s == "") {	// If there is no string to search, throw an error
		throw "Error: Cannot search for empty string.";
	}
	int index = char_to_int(s[0]);	 // Get the index corresponding to the first character
	if (children[index]) {			 // If the character exists
		if (s.size() == 1) {		 // If it's the last character to search
			return children[index];	 // Return the node at the end of the search string
		}
		// If it's not the last character, search for the rest of the search term under the child node
		return children[index]->find_node(s.substr(1));
	}
	return nullptr;	 // If the path doesn't exist, return null
}

// Find the node that leads to the given word
trie::node* trie::node::find_terminal(string s) {
	node* n = find_node(s);					// Find the node
	return n && n->terminal ? n : nullptr;	// If it's a terminal, return it. Otherwise return null
}

// Print all child paths of this node after printing prefix for each one
void trie::node::print_completions(string prefix) {
	if (terminal) {				 // If this node is an end of word, it must be equal to prefix
		cout << prefix << endl;	 // So print this word
	}
	for (int i = 0; i < alphabet_size; ++i) {			  // Go through all the children of this node
		if (children[i]) {								  // If it's not a null pointer
			string new_prefix = prefix + int_to_char(i);  // Add the current character to the prefix
			children[i]->print_completions(new_prefix);	  // Recursively print from the child node
		}
	}
}

// Constructor
trie::trie() {
	root = new node(nullptr, -1);  // Create a root node with no parent and an invalid index
}

// Insert a string into the trie
void trie::insert(string s) {
	root->append(s);  // Append the string to the root
}

// Return true if the requested string is in the trie
bool trie::search(string s) {
	return root->find_terminal(s);	// Check if the path from the root leads to a terminal node
}

// Remove a given string from the trie
bool trie::remove(string s) {
	return root->find_node(s)->remove();  // Find the node under the root and remove it
}

// Print all words in the trie sharing a given prefix
bool trie::print_completions(string prefix) {
	node* prefix_node = root->find_node(prefix);  // Find the prefix node
	if (!prefix_node) {							  // If it doesn't exist
		return false;							  // Return false
	}
	prefix_node->print_completions(prefix);	 // Print completions under the prefix node
	return true;							 // Return true if the prefix was found
}