#ifndef b_tree_h
#define b_tree_h

#include <cstring>
#include <functional>
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
		int _num_keys;
		node* _parent;
		node** _children;

		// Returns the index of where in an array of keys a key is/should be using binary search. In case of multiple matches, returns the last one
		int find_in_keys(const K& element, int min, int max) const;
		// Helper function to emulate a default parameter for max being set to the number of keys
		int find_in_keys(const K& element, int min = 0) const;
		// Rebalances a tree if too few keys remain in a node after removing a key
		node* rebalance();
		// Given the index of a child node, this function will rotate a key between that child, this node, and the child's left sibling
		void rotate_left(int index);
		// Given the index of a child node, this function will rotate a key between that child, this node, and the child's right sibling
		void rotate_right(int index);
		// Merge the two children at index and at index+1 into one node
		void merge_children(int index);
		// Returns the index that a child is located in under its parent
		int index_under_parent();

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
		// Returns the leaf where a new element could be inserted
		node* find_leaf(const K& element);
		// Inserts a key into the b-tree
		node* insert(const K& element, node* sub_tree = 0);
		// Removes a key from the b-tree
		node* remove(const K& element, int index = -1);
		// Deallocates all children in this node and in all its children, then deallocates itself
		void clear();
		// Traverses the tree in order and calls function f for each key
		void for_each(std::function<void(K&)> f);
		// Traverses the tree in order and calls function f for each key between min and max
		void for_each(const K& min, const K& max, std::function<void(K&)> f);
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
	void for_each(std::function<void(K&)> f);
	// Traverses the tree in order and calls function f for each key between min and max
	void for_each(const K& min, const K& max, std::function<void(K&)> f);
	// Prints all keys in order
	void print();
	// Prints all keys between min and max (inclusive)
	void print_between(const K& min, const K& max);
	~b_tree();
};

template <class T>
void copy(T* src, T* dest, int n) {
	if (dest <= src) {
		std::copy(src, src + n, dest);
	} else {
		std::copy_backward(src, src + n, dest + n);
	}
}

template <class K, int M>
b_tree<K, M>::node::node(node* parent, K* keys, node** children, int num_keys)
	: _parent(parent), _num_keys(num_keys) {
	if (num_keys > b_tree<K, M>::MAX_KEYS) {
		throw std::string("Error: Could not create node - too many keys. ") + std::string("Expected up to ") + std::to_string(MAX_KEYS) + std::string(", but received ") + std::to_string(num_keys) + '.';
	}
	if (num_keys < b_tree<K, M>::MIN_KEYS) {
		if (children || parent) {
			throw std::string("Error: Could not create node - too few keys for a non-root, non-leaf node. ") + std::string("Expected at least ") + std::to_string(MIN_KEYS) + std::string(", but received ") + std::to_string(num_keys) + '.';
		}
	}

	copy(keys, _keys, num_keys);
	if (!children) {
		_children = 0;
	} else {
		_children = new node*[MAX_CHILDREN];
		copy(children, _children, num_keys + 1);
	}
}

template <class K, int M>
int b_tree<K, M>::node::keys() const {
	return _num_keys;
}

template <class K, int M>
bool b_tree<K, M>::node::root() const {
	return !_parent;
}

template <class K, int M>
bool b_tree<K, M>::node::leaf() const {
	return !_children;
}

template <class K, int M>
int b_tree<K, M>::node::find_in_keys(const K& element, int min, int max) const {
	if (min == max) {
		return min;
	}
	int mid = (min + max) / 2;
	if (element < _keys[mid]) {
		return find_in_keys(element, min, mid);
	} else {
		return find_in_keys(element, mid + 1, max);
	}
}

template <class K, int M>
int b_tree<K, M>::node::find_in_keys(const K& element, int min) const {
	return find_in_keys(element, min, keys());
}

template <class K, int M>
typename b_tree<K, M>::node* b_tree<K, M>::node::rebalance() {
	if (root()) {
		if (keys() > 0) {
			return 0;
		}
		node* new_root = _children[0];
		delete this;
		return new_root;
	} else {
		if (keys() >= MIN_KEYS) {
			return 0;
		}
		int parent_index = index_under_parent();
		try {
			_parent->rotate_right(parent_index - 1);
		} catch (const std::string&) {
			try {
				_parent->rotate_left(parent_index + 1);
			} catch (const std::string&) {
				if (parent_index > 0) {
					_parent->merge_children(parent_index - 1);
				} else {
					_parent->merge_children(parent_index);
				}
				return _parent->rebalance();
			}
		}
	}
	return 0;
}

template <class K, int M>
void b_tree<K, M>::node::rotate_left(int index) {
	if (leaf()) {
		throw std::string("Error: Cannot rotate under a leaf.");
	}
	if (index < 1) {
		throw std::string("Error: Cannot rotate left from the 0th child.");
	}
	if (_children[index - 1]->keys() >= MAX_KEYS) {
		throw std::string("Error: Cannot rotate to a full child.");
	}
	if (_children[index]->keys() <= MIN_KEYS) {
		throw std::string("Error: Cannot rotate from a child with the minimum number of keys.");
	}
	_children[index - 1]->_keys[keys()] = _keys[index - 1];
	_keys[index - 1] = _children[index]->_keys[0];
	copy(&(_children[index]->_keys[1]), &(_children[index]->_keys[0]), _children[index]->keys() - 1);
	if (!_children[index]->leaf()) {
		_children[index - 1]->_children[_children[index - 1]->keys() + 1] = _children[index]->_children[0];
		copy(&(_children[index]->_children[1]), &(_children[index]->_children[0]), _children[index]->keys());
	}
	++(_children[index - 1]->_num_keys);
	--(_children[index]->_num_keys);
}

template <class K, int M>
void b_tree<K, M>::node::rotate_right(int index) {
	if (leaf()) {
		throw std::string("Error: Cannot rotate under a leaf.");
	}
	if (index >= keys() - 1) {
		throw std::string("Error: Cannot rotate right from the last child.");
	}
	if (_children[index + 1]->keys() >= MAX_KEYS) {
		throw std::string("Error: Cannot rotate to a full child.");
	}
	if (_children[index]->keys() <= MIN_KEYS) {
		throw std::string("Error: Cannot rotate from a child with the minimum number of keys.");
	}
	copy(&(_children[index + 1]->_keys[0]), &(_children[index + 1]->_keys[1]), _children[index + 1]->keys());
	_children[index + 1]->_keys[0] = _keys[index];
	_keys[index] = _children[index]->_keys[_children[index]->keys() - 1];
	if (!_children[index]->leaf()) {
		copy(&(_children[index + 1]->_children[0]), &(_children[index + 1]->_children[1]), _children[index + 1]->keys() + 1);
		_children[index + 1]->_children[0] = _children[index]->_children[keys()];
	}
	++(_children[index + 1]->_num_keys);
	--(_children[index]->_num_keys);
}

template <class K, int M>
void b_tree<K, M>::node::merge_children(int index) {
	if (leaf()) {
		throw std::string("Error: Cannot merge children of a leaf. A leaf has no children.");
	}
	if (index >= keys() - 1) {
		throw std::string("Error: Cannot merge the last key in a node with the next one, because the next one doesn't exist.");
	}
	_children[index]->_keys[keys()] = _keys[index];
	copy(&(_children[index + 1]->_keys[0]), &(_children[index]->_keys[keys() + 1]), _children[index + 1]->keys());
	if (!_children[index]->leaf()) {
		copy(&(_children[index + 1]->_children[0]), &(_children[index]->_children[keys() + 1]), _children[index + 1]->keys() + 1);
		for (int i = 0; i < _children[index + 1]->keys() + 1; ++i) {
			_children[index + 1]->_children[i]->_parent = _children[index];
		}
	}
	_children[index]->_num_keys += 1 + _children[index + 1]->keys();
	delete _children[index + 1];
	copy(&_keys[index + 1], &_keys[index], keys() - index - 1);
	copy(&_children[index + 2], &_children[index + 1], keys() - index - 1);
	--_num_keys;
}

template <class K, int M>
int b_tree<K, M>::node::index_under_parent() {
	int parent_index = _parent->find_in_keys(_keys[0]) + 1;	 // +1 in case the first key of the child = previous key of parent != next key of parent
	while (_parent->_children[parent_index] != this) {
		--parent_index;
	}
	return parent_index;
}

template <class K, int M>
K* b_tree<K, M>::node::search(const K& element) const {
	int index = find_in_keys(element);
	if (index < keys() && element == _keys[index]) {
		return &_keys[index];
	}
	if (leaf()) {
		return 0;
	}
	return _children[index]->search(element);
}

template <class K, int M>
typename b_tree<K, M>::node* b_tree<K, M>::node::find_leaf(const K& element) {
	if (leaf()) {
		return this;
	}
	int index = find_in_keys(element);
	return _children[index]->find_leaf(element);
}

template <class K, int M>
typename b_tree<K, M>::node* b_tree<K, M>::node::insert(const K& element, node* sub_tree) {
	node* new_root = 0;	 // If a new root is created by the insertion, a pointer will be puthere and this variable will be returned
	if (keys() < MAX_KEYS) {
		int index = find_in_keys(element);
		copy(&_keys[index], &_keys[index + 1], keys() - index);
		_keys[index] = element;
		if (!leaf()) {
			copy(&_children[index + 1], &_children[index + 2], keys() - index);
			_children[index + 1] = sub_tree;
		}
		++_num_keys;
	} else {  // We must split the node
		int mid = keys() / 2;
		if (element < _keys[mid]) {
			--mid;	// If the new node will go in the left node, split the node further left to make room for the new element on the left
		}
		node* right = new node(_parent, &_keys[mid + 1], &_children[mid + 1], keys() - mid - 1);  // Create a right node
		for (int i = 0; i <= right->keys(); ++i) {
			right->_children[i]->_parent = right;  // Update all the right children's parent pointers
		}
		_num_keys -= right->keys();		  // Shrink the left node by however many keys were moved to the new node
		if (element < right->_keys[0]) {  // If less than 1st key in right, insert in left node
			insert(element, sub_tree);
		} else {  // Otherwise insert in right node
			right->insert(element, sub_tree);
		}
		if (!root()) {	// Insert the last key of the left into the parent
			new_root = _parent->insert(_keys[keys() - 1], right);
		} else {  // If there is no parent
			// Put pointers to the two nodes in a new array to copy them to the new root
			node** root_children = new node*[2];
			root_children[0] = this;
			root_children[1] = right;
			new_root = new node(0, &_keys[keys() - 1], root_children, 1);  // Make new root
			delete[] root_children;										   // Deallocate the array that was just created
		}
		--_num_keys;  // Shrink node by 1 because the last key was moved to the parent
	}
	return new_root;  // Return the new root. If the root was not changed, return null
}

template <class K, int M>
typename b_tree<K, M>::node* b_tree<K, M>::node::remove(const K& element, int index) {
	if (index < 0) {
		index = find_in_keys(element);
	}
	if (leaf()) {
		if (index < keys() && _keys[index] == element) {
			copy(&_keys[index + 1], &_keys[index], keys() - index - 1);
			--_num_keys;
			return rebalance();
		}
	} else {
		if (index < keys() && _keys[index] == element) {
			node* leaf = _children[index]->find_leaf(element);
			_keys[index] = leaf->_keys[leaf->keys() - 1];
			return leaf->remove(_keys[index], leaf->keys() - 1);
		} else {
			return _children[index]->remove(element);
		}
	}
	return 0;
}

template <class K, int M>
void b_tree<K, M>::node::clear() {
	if (!leaf()) {
		for (int i = 0; i < keys() + 1; ++i) {
			_children[i]->clear();
		}
		delete _children;
	}
	delete this;
}

template <class K, int M>
void b_tree<K, M>::node::for_each(std::function<void(K&)> f) {
	if (!leaf()) {
		_children[0]->for_each(f);
	}
	for (int i = 0; i < keys(); ++i) {
		f(_keys[i]);
		if (!leaf()) {
			_children[i + 1]->for_each(f);
		}
	}
}

template <class K, int M>
void b_tree<K, M>::node::for_each(const K& min, const K& max, std::function<void(K&)> f) {
	int min_index = find_in_keys(min);
	int max_index = find_in_keys(max);
	while (_keys[min_index - 1] == min) {  // Find first instance of min
		--min_index;
	}
	if (!leaf()) {
		_children[min_index]->for_each(min, max, f);
	}
	for (int i = min_index; i < max_index; ++i) {
		f(_keys[i]);
		if (!leaf()) {
			_children[i + 1]->for_each(f);
		}
	}
	if (_keys[max_index] == max) {
		f(_keys[max_index]);
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
	node* new_root = root->find_leaf(element)->insert(element);
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
void b_tree<K, M>::for_each(std::function<void(K&)> f) {
	root->for_each(f);
}

template <class K, int M>
void b_tree<K, M>::for_each(const K& min, const K& max, std::function<void(K&)> f) {
	root->for_each(min, max, f);
}

template <class K, int M>
void b_tree<K, M>::print() {
	for_each([](K& key) {
		std::cout << key << std::endl;
	});
}

template <class K, int M>
void b_tree<K, M>::print_between(const K& min, const K& max) {
	for_each(min, max, [](K& key) {
		std::cout << key << std::endl;
	});
}

template <class K, int M>
b_tree<K, M>::~b_tree() {
	root->clear();
}

#endif