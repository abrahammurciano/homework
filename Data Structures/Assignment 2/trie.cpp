#include "trie.h"

int trie::node::char_to_int(char c) {
	if (c >= 'A' && c <= 'Z') {
		return c - 'A';
	} else if (c >= 'a' && c <= 'z') {
		return c - 'a';
	} else {
		throw string("Error: Invalid character '") + c + string("'.");
	}
}

char trie::node::int_to_char(int index) {
	return index + 'a';
}

bool trie::node::has_children() {
	for (int i = 0; i < alphabet_size; ++i) {
		if (children[i]) {
			return true;
		}
	}
	return false;
}

trie::node::node(node* parent, int index)
	: parent(parent), index(index), terminal(false) {
	children = new node*[alphabet_size];
	for (int i = 0; i < alphabet_size; ++i) {
		children[i] = nullptr;
	}
}

trie::node::~node() {
	for (int i = 0; i < alphabet_size; ++i) {
		delete children[i];
	}
	delete[] children;
}

void trie::node::append(string s) {
	int index = char_to_int(s[0]);
	if (!children[index]) {
		children[index] = new node(this, index);
	}
	if (s.size() == 1) {
		children[index]->terminal = true;
		return;
	}
	children[index]->append(s.substr(1));
}

bool trie::node::remove() {
	if (!terminal) {
		return false;
	}
	terminal = false;
	node *_node = this, *_parent = parent;
	while (_parent && !_node->has_children() && !_node->terminal) {
		_parent->children[_node->index] = nullptr;
		delete _node;
		_node = _parent;
		_parent = _parent->parent;
	}
	return true;
}

trie::node* trie::node::find_node(string s) {
	if (s == "") {
		throw "Error: Cannot search for empty string.";
	}
	int index = char_to_int(s[0]);
	if (children[index]) {
		if (s.size() == 1) {
			return children[index];
		}
		return children[index]->find_node(s.substr(1));
	}
	return nullptr;
}

trie::node* trie::node::find_terminal(string s) {
	node* n = find_node(s);
	return n && n->terminal ? n : nullptr;
}

void trie::node::print_completions(string prefix) {
	if (terminal) {
		cout << prefix << endl;
	}
	for (int i = 0; i < alphabet_size; ++i) {
		if (children[i]) {
			children[i]->print_completions(prefix + int_to_char(children[i]->index));
		}
	}
}

trie::trie() {
	root = new node(nullptr, -1);
}

void trie::insert(string s) {
	root->append(s);
}

bool trie::search(string s) {
	return root->find_terminal(s);
}

bool trie::remove(string s) {
	return root->find_node(s)->remove();
}

bool trie::print_completions(string prefix) {
	node* prefix_node = root->find_node(prefix);
	if (!prefix_node) {
		return false;
	}
	prefix_node->print_completions(prefix);
	return true;
}