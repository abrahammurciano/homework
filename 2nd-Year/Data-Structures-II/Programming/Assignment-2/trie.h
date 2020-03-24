/*
 * File Name:				main.cpp
 * Program Description:		Tries implementation
 * Course Name:				Data Structures 2
 * Assignment Number:		2
 * Question Number:			1
 * Author:					Abraham Murciano
 */

#include <iostream>

class trie {
  protected:
	// Node class
	class node {
	  protected:
		static const int alphabet_size = 26;  // Number of distinct children a node can have
		node** children;					  // Array of children
		node* parent;						  // Pointer to parent node
		bool terminal;						  // Flag to indicate if this node marks the end of a word
		int index;							  // Stores which index this node is under its parent

		int static char_to_int(char c);		 // Given a character, return the corresponding index
		char static int_to_char(int index);	 // Given an index, return the corresponding character
		bool has_children();				 // Returns weather or not the node has children

	  public:
		node(node* parent, int index);			  // Constructor
		virtual ~node();						  // Destructor
		virtual void append(std::string suffix);  // Append a suffix to this node
		bool remove();							  // Remove the word ending at this node from the trie
		node* find_node(std::string s);			  // Find the node that leads to the given word or prefix
		node* find_terminal(std::string s);		  // Find the node that leads to the given word
		// Print all child paths of this node after printing prefix for each one
		void print_completions(std::string prefix);
	};

	node* root;	 // Pointer to the root node

  public:
	trie();												// Constructor
	virtual void insert(const std::string& s);			// Insert a string into the trie
	bool search(const std::string& s);					// Return true if the requested string is in the trie
	bool remove(const std::string& s);					// Remove a given string from the trie
	bool print_completions(const std::string& prefix);	// Print all words in the trie sharing a given prefix
};
