template <class T, int M>
class b_tree {
  private:
	const static int MAX_KEYS = M - 1;
	const static int MAX_CHILDREN = M;

	class node {
	  private:
		T _keys[MAX_KEYS];
		int num_keys;
		node* parent;
		node** children;

		// Returns the index of where in an array of keys a key is/should be using binary search
		int find_in_keys(const T& element, int min = 0, int max = keys());
		// Returns the leaf where a new element could be inserted
		node* find_leaf(const T& element);
		// Returns the key at the given index
		T& key(int index);

	  public:
		node(node* parent = 0, bool leaf = false);
		// Returns number of keys in this node
		int keys();
		// Returns true if this node is a leaf
		bool leaf();
		// Returns a pointer to a key if found. Otherwise returns 0
		T* search(const T& element);
		// Inserts a key into the b-tree
		void insert(const T& element);
	};

	node* root;

  public:
	b_tree();
	// Search for an element in the b-tree
	bool search(const T& element);
	// Insert an element into the b-tree
	void insert(const T& element);
	~b_tree();
};

template <class T, int M>
b_tree<T, M>::node::node(node* parent, bool leaf)
	: parent(parent) {
	children = (leaf ? 0 : new node*[MAX_CHILDREN]);
}

template <class T, int M>
int b_tree<T, M>::node::keys() {
	return num_keys;
}

template <class T, int M>
bool b_tree<T, M>::node::leaf() {
	return !children;
}

template <class T, int M>
T& b_tree<T, M>::node::key(int index) {
	return _keys[index];
}

template <class T, int M>
int b_tree<T, M>::node::find_in_keys(const T& element, int min, int max) {
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

template <class T, int M>
typename b_tree<T, M>::node* b_tree<T, M>::node::find_leaf(const T& element) {
	if (leaf()) {
		return this;
	}
	int index = find_in_keys(const T& element);
	return children[index]->find_leaf(element);
}

template <class T, int M>
T* b_tree<T, M>::node::search(const T& element) {
	int index = find_in_keys(const T& element);
	if (element == key(index)) {
		return &key(index);
	}
	if (leaf()) {
		return 0;
	}
	return children[index]->search(element);
}

template <class T, int M>
void b_tree<T, M>::node::insert(const T& element) {
	if (keys() < MAX_KEYS) {
		int index = find_in_keys(element);
		for (int i = keys(); i > index; --i) {
			key(i) = key(i - 1);
		}
		key(index) = element;

		// TODO
	}
}

template <class T, int M>
b_tree<T, M>::b_tree()
	: root(new node(true)) {}

template <class T, int M>
bool b_tree<T, M>::search(const T& element) {
	return root->search(element);
}

template <class T, int M>
void b_tree<T, M>::insert(const T& element) {
	node* leaf = find_leaf(element);
	leaf->insert(element);
}