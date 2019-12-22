#include <cstring>
#include <iostream>

template <class K, int O>
class b_tree {
  private:
	const static int MIN_CHILDREN = (O + 1) / 2;
	const static int MAX_CHILDREN = O;
	const static int MIN_KEYS = MIN_CHILDREN - 1;
	const static int MAX_KEYS = O - 1;

	class node {
	  private:
		K _keys[MAX_KEYS];
		int num_keys;
		node* parent;
		node** children;

		// Returns the key at the given index
		K& key(int index) const;
		// Returns the child at the given index
		node* child(int index) const;
		// Returns the index of where in an array of keys a key is/should be using binary search
		int find_in_keys(const K& element, int min = 0, int max = keys() + 1) const;
		// Returns the leaf where a new element could be inserted
		node* find_leaf(const K& element) const;

	  public:
		node(node* parent = 0, K* keys = 0, node** children = 0, int num_keys = 0);
		// Returns number of keys in this node
		int keys() const;
		// Returns true if this node is the root
		bool root() const;
		// Returns true if this node is a leaf
		bool leaf() const;
		// Returns a pointer to a key if found. Otherwise returns 0
		K* search(const K& element) const;
		// Inserts a key into the b-tree
		node* insert(const K& element, node* sub_tree = 0);
	};

	node* root;

  public:
	b_tree();
	// Search for an element in the b-tree
	bool search(const K& element) const;
	// Insert an element into the b-tree
	void insert(const K& element);
	~b_tree();
};

template <class K, int O>
b_tree<K, O>::node::node(node* parent, K* keys, node** children, int num_keys)
	: parent(parent), num_keys(num_keys) {
	if (num_keys > b_tree<K, O>::MAX_KEYS) {
		throw std::string("Error: Could not create node - too many keys. ") + std::string("Expected up to ") + std::to_string(MAX_KEYS) + std::string(", but received ") + std::to_string(num_keys) + '.';
	}
	if (num_keys < b_tree<K, O>::MIN_KEYS) {
		if (children || parent) {
			throw std::string("Error: Could not create node - too few keys for a non-root, non-leaf node. ") + std::string("Expected at least ") + std::to_string(MIN_KEYS) + std::string(", but received ") + std::to_string(num_keys) + '.';
		}
	}

	std::memcpy(_keys, keys, num_keys * sizeof(K));
	if (!children) {
		this->children = 0;
	} else {
		this->children = new node*[MAX_CHILDREN];
		std::memcpy(this->children, children, (num_keys + 1) * sizeof(node*));
	}
}

template <class K, int O>
int b_tree<K, O>::node::keys() const {
	return num_keys;
}

template <class K, int O>
bool b_tree<K, O>::node::root() const {
	return !parent;
}

template <class K, int O>
bool b_tree<K, O>::node::leaf() const {
	return !children;
}

template <class K, int O>
K& b_tree<K, O>::node::key(int index) const {
	return _keys[index];
}

template <class K, int O>
typename b_tree<K, O>::node* b_tree<K, O>::node::child(int index) const {
	return children[index];
}

template <class K, int O>
int b_tree<K, O>::node::find_in_keys(const K& element, int min, int max) const {
	if (min == max) {
		return min;
	}
	int mid = (min + max) / 2;
	if (element < key(mid)) {
		return find_in_keys(element, min, mid);
	} else {
		return find_in_keys(element, mid + 1, max);
	}
}

template <class K, int O>
typename b_tree<K, O>::node* b_tree<K, O>::node::find_leaf(const K& element) const {
	if (leaf()) {
		return this;
	}
	int index = find_in_keys(element);
	return children[index]->find_leaf(element);
}

template <class K, int O>
K* b_tree<K, O>::node::search(const K& element) const {
	int index = find_in_keys(element);
	if (index < keys() && element == key(index)) {
		return &key(index);
	}
	if (leaf()) {
		return 0;
	}
	return children[index]->search(element);
}

template <class K, int O>
typename b_tree<K, O>::node* b_tree<K, O>::node::insert(const K& element, node* sub_tree) {
	if (keys() < MAX_KEYS) {
		int index = find_in_keys(element);
		std::memmove(&key(index + 1), &key(index), (keys() - index) * sizeof(K));
		key(index) = element;
		if (!leaf()) {
			std::memmove(&child(index + 2), &child(index + 1), (keys() - index) * sizeof(node*));
			child(index + 1) = sub_tree;
		}
	} else {
		int mid = keys() / 2;
		node* right = new node(parent, &key(mid + 1), &child(mid + 1), keys() - mid - 1);
		for (int i = 0; i <= right->keys(); ++i) {
			right->child(i)->parent = right;
		}
		if (!root()) {
			parent->insert(key(mid), right);
		} else {
			node** root_children = new node*[2];
			root_children[0] = this;
			root_children[1] = right;
			node* root = new node(0, &key(mid), root_children, 1);
			delete[] root_children;
			return root;
		}
		num_keys = mid;
	}
}

template <class K, int O>
b_tree<K, O>::b_tree()
	: root(new node()) {}

template <class K, int O>
bool b_tree<K, O>::search(const K& element) const {
	return root->search(element);
}

template <class K, int O>
void b_tree<K, O>::insert(const K& element) {
	node* leaf = find_leaf(element);
	node* new_root = leaf->insert(element);
	if (new_root) {
		root = new_root;
	}
}