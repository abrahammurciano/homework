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
		// Rebalances a tree if too few keys remain in a node after removing a key
		node* rebalance();
		// Given the index of a child node, this function will rotate a key between that child, this node, and the child's left sibling
		void rotate_left(int index);
		// Given the index of a child node, this function will rotate a key between that child, this node, and the child's right sibling
		void rotate_right(int index);
		// Merge the two children at index and at index+1 into one node
		void merge_children(int index);

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
		node* remove(const K& element, int index = -1);
		// Deallocates all children in this node and in all its children, then deallocates itself
		void clear();
		// Traverses the tree in order and calls function f for each key
		void for_each(void (*f)(K&));
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
	// Removes all the nodes from the b-tree
	void clear();
	// Traverses the tree in order and calls function f for each key
	void for_each(void (*f)(K&));
	// Prints all keys in order
	void print();
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
typename b_tree<K, M>::node* b_tree<K, M>::node::rebalance() {
	if (root()) {
		if (keys() > 0) {
			return 0;
		}
		node* new_root = child(0);
		delete this;
		return new_root;
	} else {
		if (keys() >= MIN_KEYS) {
			return 0;
		}
		int parent_index = parent->find_in_keys(key(keys() - 1));
		while (parent->child(parent_index) != this) {
			--parent_index;
		}
		try {
			parent->rotate_right(parent_index - 1);
		} catch (const std::string&) {
			try {
				parent->rotate_left(parent_index + 1);
			} catch (const std::string&) {
				if (parent_index > 0) {
					parent->merge_children(parent_index - 1);
				} else {
					parent->merge_children(parent_index);
				}
				return parent->rebalance();
			}
		}
	}
}

template <class K, int M>
void b_tree<K, M>::node::rotate_left(int index) {
	if (leaf()) {
		throw std::string("Error: Cannot rotate under a leaf.");
	}
	if (index < 1) {
		throw std::string("Error: Cannot rotate left from the 0th child.");
	}
	if (child(index - 1)->keys() >= MAX_KEYS) {
		throw std::string("Error: Cannot rotate to a full child.");
	}
	if (child(index)->keys() <= MIN_KEYS) {
		throw std::string("Error: Cannot rotate from a child with the minimum number of keys.");
	}
	child(index - 1)->key(keys()) = key(index - 1);
	key(index - 1) = child(index)->key(0);
	memmove(&(child(index)->key(0)), &(child(index)->key(1)), (child(index)->keys() - 1) * sizeof(K));
	if (!child(index)->leaf()) {
		child(index - 1)->child(child(index - 1)->keys() + 1) = child(index)->child(0);
		memmove(&(child(index)->child(0)), &(child(index)->child(1)), (child(index)->keys()) * sizeof(node*));
	}
	++(child(index - 1)->num_keys);
	--(child(index)->num_keys);
}

template <class K, int M>
void b_tree<K, M>::node::rotate_right(int index) {
	if (leaf()) {
		throw std::string("Error: Cannot rotate under a leaf.");
	}
	if (index >= keys() - 1) {
		throw std::string("Error: Cannot rotate right from the last child.");
	}
	if (child(index + 1)->keys() >= MAX_KEYS) {
		throw std::string("Error: Cannot rotate to a full child.");
	}
	if (child(index)->keys() <= MIN_KEYS) {
		throw std::string("Error: Cannot rotate from a child with the minimum number of keys.");
	}
	memmove(&(child(index + 1)->key(1)), &(child(index + 1)->key(0)), child(index + 1)->keys() * sizeof(K));
	child(index + 1)->key(0) = key(index);
	key(index) = child(index)->key(child(index)->keys() - 1);
	if (!child(index)->leaf()) {
		memmove(&(child(index + 1)->child(1)), &(child(index + 1)->child(0)), (child(index + 1)->keys() + 1) * sizeof(node*));
		child(index + 1)->child(0) = child(index)->child(keys());
	}
	++(child(index + 1)->num_keys);
	--(child(index)->num_keys);
}

template <class K, int M>
void b_tree<K, M>::node::merge_children(int index) {
	if (leaf()) {
		throw std::string("Error: Cannot merge children of a leaf. A leaf has no children.");
	}
	if (index >= keys() - 1) {
		throw std::string("Error: Cannot merge the last key in a node with the next one, because the next one doesn't exist.");
	}
	child(index)->key(keys()) = key(index);
	memccpy(&(child(index)->key(keys() + 1)), &(child(index + 1)->key(0)), child(index + 1)->keys() * sizeof(K));
	if (!child(index)->leaf()) {
		memccpy(&(child(index)->child(keys() + 1)), (&(child(index + 1)->child(0))), (child(index + 1)->keys() + 1) * sizeof(node*));
		for (int i = 0; i < child(index + 1)->keys() + 1; ++i) {
			child(index + 1)->child(i)->parent = child(index);
		}
	}
	child(index)->num_keys += 1 + child(index + 1)->keys();
	delete child(index + 1);
	memmove(&key(index), &key(index + 1), (keys() - index - 1) * sizeof(K));
	memmove(&child(index + 1), &child(index + 2), (keys() - index - 1) * sizeof(node*));
	--num_keys;
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
typename b_tree<K, M>::node* b_tree<K, M>::node::remove(const K& element, int index) {
	if (index < 0) {
		index = find_in_keys(element);
	}
	if (leaf()) {
		if (index < keys() && key(index) == element) {
			memmove(&key(index), &key(index + 1), (keys() - index - 1) * sizeof(K));
			--num_keys;
			return rebalance();
		}
	} else {
		if ((index < keys() && key(index) == element)) {
			node* leaf = child(index)->find_leaf(element);
			key(index) = leaf->key(leaf->keys() - 1);
			leaf->remove(key(index), leaf->keys() - 1);
		} else {
			return child(index)->remove(element);
		}
	}
}

template <class K, int M>
void b_tree<K, M>::node::clear() {
	if (!leaf()) {
		for (int i = 0; i < keys() + 1; ++i) {
			child(i)->clear();
		}
		delete child;
	}
	delete this;
}

template <class K, int M>
void b_tree<K, M>::node::for_each(void (*f)(K&)) {
	if (!leaf()) {
		chid(0)->for_each(f);
	}
	for (int i = 0; i < keys(); ++i) {
		f(key(i));
		if (!leaf()) {
			chid(i + 1)->for_each(f);
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
	node* new_root = find_leaf(element)->insert(element);
	if (new_root) {
		root = new_root;
	}
}

template <class K, int M>
void b_tree<K, M>::remove(const K& element) {
	node* new_root = root->remove(element);
	if (new_root) {
		root = new_root;
	}
}

template <class K, int M>
void b_tree<K, M>::clear() {
	root->clear();
	root = new node();
}

template <class K, int M>
void b_tree<K, M>::for_each(void (*f)(K&)) {
	root->for_each(f);
}

template <class K, int M>
void b_tree<K, M>::print() {
	root->for_each([](K& key) {
		std::cout << key << std::endl;
	});
}

template <class K, int M>
b_tree<K, M>::~b_tree() {
	root->clear();
}