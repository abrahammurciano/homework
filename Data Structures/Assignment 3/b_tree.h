#include <cstring>
#include <iostream>

template <class K, int M>
class b_tree {
  private:
	const static int MIN_CHILDREN = (M + 1) / 2;
	const static int MAX_CHILDREN = M;
	const static int MIN_KEYS = MIN_CHILDREN - 1;
	const static int MAX_KEYS = M - 1;

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
		int find_in_keys(const K& element, int min = 0, int max = keys()) const;
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
		// Removes a key from the b-tree
		void remove(const K& element, int index = -1);
	};

	node* root;

  public:
	b_tree();
	// Search for an element in the b-tree
	bool search(const K& element) const;
	// Insert an element into the b-tree
	void insert(const K& element);
	// Remove an element from the b-tree
	void remove(const K& element);
	~b_tree();
};

template <class K, int M>
b_tree<K, M>::node::node(node* parent, K* keys, node** children, int num_keys)
	: parent(parent), num_keys(num_keys) {
	if (num_keys > b_tree<K, M>::MAX_KEYS) {
		throw std::string("Error: Could not create node - too many keys. ") + std::string("Expected up to ") + std::to_string(MAX_KEYS) + std::string(", but received ") + std::to_string(num_keys) + '.';
	}
	if (num_keys < b_tree<K, M>::MIN_KEYS) {
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

template <class K, int M>
int b_tree<K, M>::node::keys() const {
	return num_keys;
}

template <class K, int M>
bool b_tree<K, M>::node::root() const {
	return !parent;
}

template <class K, int M>
bool b_tree<K, M>::node::leaf() const {
	return !children;
}

template <class K, int M>
K& b_tree<K, M>::node::key(int index) const {
	if (index >= keys() || index < 0) {
		throw std::string("Error: Out of bounds key access attempted");
	}
	return _keys[index];
}

template <class K, int M>
typename b_tree<K, M>::node* b_tree<K, M>::node::child(int index) const {
	if (index > keys() || index < 0) {
		throw std::string("Error: Out of bounds child access attempted");
	}
	return children[index];
}

template <class K, int M>
int b_tree<K, M>::node::find_in_keys(const K& element, int min, int max) const {
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

template <class K, int M>
typename b_tree<K, M>::node* b_tree<K, M>::node::find_leaf(const K& element) const {
	if (leaf()) {
		return this;
	}
	int index = find_in_keys(element);
	return children[index]->find_leaf(element);
}

template <class K, int M>
K* b_tree<K, M>::node::search(const K& element) const {
	int index = find_in_keys(element);
	if (index < keys() && element == key(index)) {
		return &key(index);
	}
	if (leaf()) {
		return 0;
	}
	return children[index]->search(element);
}

template <class K, int M>
typename b_tree<K, M>::node* b_tree<K, M>::node::insert(const K& element, node* sub_tree) {
	if (keys() < MAX_KEYS) {
		int index = find_in_keys(element);
		std::memmove(&key(index + 1), &key(index), (keys() - index) * sizeof(K));
		key(index) = element;
		if (!leaf()) {
			std::memmove(&child(index + 2), &child(index + 1), (keys() - index) * sizeof(node*));
			child(index + 1) = sub_tree;
		}
		++num_keys;
	} else {
		int mid = keys() / 2;
		int tmp_mid = (element < key(mid) ? mid - 1 : mid);
		node* right = new node(parent, &key(tmp_mid + 1), &child(tmp_mid + 1), keys() - tmp_mid - 1);
		for (int i = 0; i <= right->keys(); ++i) {
			right->child(i)->parent = right;
		}
		num_keys = mid;
		if (element < right->key(0)) {
			insert(element, sub_tree);
		} else {
			right->insert(element, sub_tree);
		}
		if (!root()) {
			parent->insert(key(keys() - 1), right);
		} else {
			node** root_children = new node*[2];
			root_children[0] = this;
			root_children[1] = right;
			node* root = new node(0, &key(mid), root_children, 1);
			delete[] root_children;
			return root;
		}
	}
}

template <class K, int M>
void b_tree<K, M>::node::remove(const K& element, int index) {
	if (index < 0) {
		index = find_in_keys(element);
	}
	if (leaf()) {
		if (index < keys() && key(index) == element) {
			memmove(&key(index), &key(index + 1), 1 * sizeof(K));
			--num_keys;
			if (keys() < MIN_KEYS) {
				rebalance();
			}
		}
	} else {
		if ((index < keys() && key(index) == element)) {
			node* leaf = child(index)->find_leaf(element);
			key(index) = leaf->key(leaf->keys() - 1);
			leaf->remove(key(index), leaf->keys() - 1);
		} else {
			child(index)->remove(element);
		}
	}
}

template <class K, int M>
b_tree<K, M>::b_tree()
	: root(new node()) {}

template <class K, int M>
bool b_tree<K, M>::search(const K& element) const {
	return root->search(element);
}

template <class K, int M>
void b_tree<K, M>::insert(const K& element) {
	node* leaf = find_leaf(element);
	node* new_root = leaf->insert(element);
	if (new_root) {
		root = new_root;
	}
}

template <class K, int M>
void b_tree<K, M>::remove(const K& element) {
	root->remove(element);
}