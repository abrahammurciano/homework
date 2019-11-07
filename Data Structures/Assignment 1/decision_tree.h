/*
 * File Name:				decision_tree.h
 * Program Description:		Decision trees
 * Course Name:				Data Structures 2
 * Assignment Number:		1
 * Question Number:			1
 * Author:					Abraham Murciano
 */

#ifndef decision_tree_h
#define decision_tree_h

#include <iostream>
#include <list>
using namespace std;

class decision_tree {
	friend class answer_node;

  private:
	class answer_node;

	// Node to represent either a question or a decision
	class decision_node {
	  private:
		string value;
		list<answer_node*> answers;

	  public:
		decision_node();
		decision_node(string value);
		decision_node(const decision_node& n);

		// Returns the value stored in the node
		string get_value();

		// Recursively look for a decision node containing {value} below this node. Return NULL if not found
		decision_node* find(string value);

		// Adds a possible {answer} to the question, leading to {next}
		void add_answer(string answer, string next);

		void print(int level);

		bool print_path(string value);

		void run();

		bool remove_subtree(string value);

		~decision_node();
	};

	// Node to represent a possible answer to a question
	class answer_node {
	  private:
		string answer;
		decision_node* next;

	  public:
		answer_node();
		answer_node(string answer, string next);
		answer_node(const answer_node& n);

		// Returns the answer in this node
		string get_answer();

		// Returns a pointer to the decision node following this answer
		decision_node* get_next();

		void print(int level);

		~answer_node();
	};

	decision_node* root;

	// Finds a node in the tree containing a specific {question}
	decision_node* find(string question);

  public:
	decision_tree();
	decision_tree(string init);
	decision_tree(const decision_tree& t);

	// Assignment operator
	decision_tree& operator=(const decision_tree& t);

	// Adds a possible {answer} to the question {question} leading to the question or decision {next}
	bool add_node(string question, string answer, string next);

	// Removes the decision node containing {value} along with all its child nodes
	void remove_subtree(string value);

	// Prints the decision tree in hierarchial format
	void print();

	// Prints the path to the node containing {value}
	void print_path(string value);

	// Interactively goes throught the decision tree with the user until a conclusion is reached
	void run();

	~decision_tree();
};

#endif