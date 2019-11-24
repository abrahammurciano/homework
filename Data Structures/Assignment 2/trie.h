#include <iostream>
using namespace std;

class trie {
  private:
	// Private members here
	class node {
		static const int alphabet_size = 26;
		node** children;
		node* parent;
		bool terminal;
		int index;

		int static char_to_int(char c);
		char static int_to_char(int index);
		bool has_children();

	  public:
		node(node* parent, int index);
		~node();
		void append(string s);
		bool remove();
		node* find_node(string s);
		node* find_terminal(string s);
		void print_completions(string prefix);
	};

	node* root;

  public:
	trie();
	void insert(string s);
	bool search(string s);
	bool remove(string s);
	bool print_completions(string prefix);
};
