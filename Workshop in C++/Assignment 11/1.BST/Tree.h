/*
 * File Name:				Tree.h
 * Program Description:		Binary search Trees
 * Course Name:				Workshop in C++
 * Assignment Number:		11
 * Question Number:			1
 * Author:					Abraham Murciano
 */

#ifndef Tree_h
#define Tree_h

//#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
using namespace std;

template <class T>
class Tree {

  protected:
	class Node {
		friend Tree;

	  public:
		// Data
		T val;
		Node* right;
		Node* left;
		Node* parent;

		// Constructors
		Node();
		Node(const T& val);

		// Methods
		virtual Node* node_left() const;
		virtual Node* node_right() const;
		virtual Node* node_parent() const;
		virtual Node* node_bottomLeft();
		virtual const Node* node_bottomLeft() const;
		virtual Node* node_bottomRight();
		virtual const Node* node_bottomRight() const;
		virtual Node* node_next();
		virtual const Node* node_next() const;
		virtual Node* node_prev();
		virtual const Node* node_prev() const;
	};

	// Data
	Node* _root;

	// Methods
	virtual Node* node_begin() const;
	virtual Node* node_end() const;
	virtual Node* node_root() const;

  public:
	class iterator {
		friend Tree;

	  protected:
		// Data
		Node* node;

		// Constructors
		iterator(Node* n);

		// Methods
		iterator randomNull() const;
		void setLeft(iterator child);
		void setRight(iterator child);

	  public:
		// Constructors
		explicit(operator bool)() const {
			return node != nullptr;
		}

		// Operators
		bool operator==(const iterator& i) const;
		bool operator!=(const iterator& i) const;
		iterator operator+(int n);
		iterator operator-(int n);
		iterator operator++();
		iterator operator++(int);
		iterator operator--();
		iterator operator--(int);
		T& operator*() const;

		// Methods
		iterator left() const;
		iterator right() const;
		iterator parent() const;
		iterator bottomLeft() const;
		iterator bottomRight() const;
		iterator next() const;
		iterator prev() const;
		bool leaf() const;
		int leaves() const;
		int height() const;
		void reflect();
		void for_each(void (*f)(T&));
		int count_if(bool (*f)(iterator)) const;
	};

	// Constructors
	Tree();

	// Methods
	iterator insert(const T& val);
	iterator remove(iterator i);
	iterator begin() const;
	iterator end() const;
	iterator root() const;
	bool empty() const;
	int leaves() const;
	int height() const;
	void reflect();
	int onlyLeftChild();
	void for_each(void (*f)(T&));
	int count_if(bool (*f)(iterator));
};

template <class T>
Tree<T>::Node::Node() {
	right = left = parent = nullptr;
}

template <class T>
Tree<T>::Node::Node(const T& val) {
	right = left = parent = nullptr;
	this->val = val;
}

template <class T>
typename Tree<T>::Node* Tree<T>::Node::node_left() const {
	return left;
}

template <class T>
typename Tree<T>::Node* Tree<T>::Node::node_right() const {
	return right;
}

template <class T>
typename Tree<T>::Node* Tree<T>::Node::node_parent() const {
	return parent;
}

template <class T>
typename Tree<T>::Node* Tree<T>::Node::node_bottomLeft() {
	return const_cast<Node*>(static_cast<const Node&>(*this).node_bottomLeft());
}

template <class T>
const typename Tree<T>::Node* Tree<T>::Node::node_bottomLeft() const {
	if (left) {
		return left->node_bottomLeft();
	}
	return this;
}

template <class T>
typename Tree<T>::Node* Tree<T>::Node::node_bottomRight() {
	return const_cast<Node*>(static_cast<const Node&>(*this).node_bottomRight());
}

template <class T>
const typename Tree<T>::Node* Tree<T>::Node::node_bottomRight() const {
	if (right) {
		return right->node_bottomRight();
	}
	return this;
}

template <class T>
typename Tree<T>::Node* Tree<T>::Node::node_next() {
	return const_cast<Node*>(static_cast<const Node&>(*this).node_next());
}

template <class T>
const typename Tree<T>::Node* Tree<T>::Node::node_next() const {
	const Node* n = this;
	if (n) {
		if (!n->right) {
			while (n->parent && n->parent->left != n) {
				n = n->parent;
			}
			return n->parent;
		} else {
			return n->right->node_bottomLeft();
		}
	} else {
		return nullptr;
	}
}

template <class T>
typename Tree<T>::Node* Tree<T>::Node::node_prev() {
	return const_cast<Node*>(static_cast<const Node&>(*this).node_prev());
}

template <class T>
const typename Tree<T>::Node* Tree<T>::Node::node_prev() const {
	const Node* n = this;
	if (n) {
		if (!n->left) {
			while (n->parent && n->parent->right != n) {
				n = n->parent;
			}
			return n->parent;
		} else {
			return n->left->node_bottomRight();
		}
	} else {
		return nullptr;
	}
}

template <class T>
typename Tree<T>::Node* Tree<T>::node_begin() const {
	Node* n = _root;
	while (n->left) {
		n = n->left;
	}
	return n;
}

template <class T>
typename Tree<T>::Node* Tree<T>::node_end() const {
	return nullptr;
}

template <class T>
typename Tree<T>::Node* Tree<T>::node_root() const {
	return _root;
}

template <class T>
Tree<T>::iterator::iterator(Node* n) {
	this->node = n;
}

template <class T>
typename Tree<T>::iterator Tree<T>::iterator::randomNull() const {
	if (!(left() && right())) {
		return *this;
	}
	return (rand() % 2 ? left() : right()).randomNull();
}

template <class T>
void Tree<T>::iterator::setLeft(iterator child) {
	node->left = child.node;
	if (child) {
		child.node->parent = node;
	}
}

template <class T>
void Tree<T>::iterator::setRight(iterator child) {
	node->right = child.node;
	if (child) {
		child.node->parent = node;
	}
}

template <class T>
bool Tree<T>::iterator::operator!=(const iterator& i) const {
	return node != i.node;
}

template <class T>
bool Tree<T>::iterator::operator==(const iterator& i) const {
	return node == i.node;
}

template <class T>
typename Tree<T>::iterator Tree<T>::iterator::operator++() {
	node = next().node;
	return *this;
}

template <class T>
typename Tree<T>::iterator Tree<T>::iterator::operator++(int) {
	iterator i = *this;
	operator++();
	return i;
}

template <class T>
typename Tree<T>::iterator Tree<T>::iterator::operator--() {
	node = prev().node;
	return *this;
}

template <class T>
typename Tree<T>::iterator Tree<T>::iterator::operator--(int) {
	iterator i = *this;
	operator--();
	return i;
}

template <class T>
T& Tree<T>::iterator::operator*() const {
	return node->val;
}

template <class T>
typename Tree<T>::iterator Tree<T>::iterator::left() const {
	return node->node_left();
}

template <class T>
typename Tree<T>::iterator Tree<T>::iterator::right() const {
	return node->node_right();
}

template <class T>
typename Tree<T>::iterator Tree<T>::iterator::parent() const {
	return node->node_parent();
}

template <class T>
typename Tree<T>::iterator Tree<T>::iterator::bottomLeft() const {
	return node->node_bottomLeft();
}

template <class T>
typename Tree<T>::iterator Tree<T>::iterator::bottomRight() const {
	return node->node_bottomRight();
}

template <class T>
typename Tree<T>::iterator Tree<T>::iterator::next() const {
	return node->node_next();
}

template <class T>
typename Tree<T>::iterator Tree<T>::iterator::prev() const {
	return node->node_prev();
}

template <class T>
bool Tree<T>::iterator::leaf() const {
	return !(left() || right());
}

template <class T>
int Tree<T>::iterator::leaves() const {
	if (!*this) {
		return 0;
	}
	if (leaf()) {
		return 1;
	}
	return left().leaves() + right().leaves();
}

template <class T>
int Tree<T>::iterator::height() const {
	if (!*this) {
		return 0;
	}
	int leftH = left().height();
	int rightH = right().height();
	return 1 + (leftH > rightH ? leftH : rightH);
}

template <class T>
void Tree<T>::iterator::reflect() {
	if (*this) {
		swap(node->left, node->right);
		left().reflect();
		right().reflect();
	}
}

template <class T>
void Tree<T>::iterator::for_each(void (*f)(T&)) {
	if (*this) {
		left().for_each(f);
		f(**this);
		right().for_each(f);
	}
}

template <class T>
int Tree<T>::iterator::count_if(bool (*f)(iterator)) const {
	if (*this) {
		return left().count_if(f) + f(*this) + right().count_if(f);
	}
}

template <class T>
Tree<T>::Tree() {
	_root = nullptr;
}

template <class T>
typename Tree<T>::iterator Tree<T>::insert(const T& val) {
	iterator temp(new Node(val));
	if (empty()) {
		_root = temp.node;
		return root();
	} else {
		srand(time(nullptr));
		for (iterator i = root(); i; i = rand() % 2 ? i.left() : i.right()) {
			if (!i.left()) {
				i.setLeft(temp);
			}
			if (!i.right()) {
				i.setRight(temp);
			}
			return temp;
		}
	}
}

template <class T>
typename Tree<T>::iterator Tree<T>::remove(iterator i) {
	if (i) {
		if (i.leaf()) {
			i.parent().left() == i ? i.parent().setLeft(nullptr) : i.parent().setRight(nullptr);
		} else if (!(i.left() && i.right())) {
			iterator inheritor = i.left() ? i.left() : i.right();
			i.parent().left() == i ? i.parent().setLeft(inheritor) : i.parent().setRight(inheritor);
		} else {
			iterator disowned = rand() % 2 ? i.left() : i.right();
			iterator inheritor = (i.left() == disowned ? i.right() : i.left());
			(i.parent().left() == i ? i.parent().setLeft(inheritor)
									: i.parent().setRight(inheritor));
			iterator adopter = i.randomNull();
			adopter.left() ? adopter.setRight(disowned) : adopter.setLeft(disowned);
		}
		iterator nextNode = i.next();
		delete i.node;
		return nextNode;
	}
	return end();
}

template <class T>
typename Tree<T>::iterator Tree<T>::begin() const {
	return node_begin();
}

template <class T>
typename Tree<T>::iterator Tree<T>::end() const {
	return node_end();
}

template <class T>
typename Tree<T>::iterator Tree<T>::root() const {
	return node_root();
}

template <class T>
bool Tree<T>::empty() const {
	return !root();
}

template <class T>
int Tree<T>::leaves() const {
	return root().leaves();
}

template <class T>
int Tree<T>::height() const {
	return root().height();
}

template <class T>
void Tree<T>::reflect() {
	root().reflect();
}

template <class T>
int Tree<T>::onlyLeftChild() {
	count_if([](iterator i) { return i.parent() && !i.parent().right(); });
}

template <class T>
void Tree<T>::for_each(void (*f)(T&)) {
	root().for_each(f);
}

template <class T>
int Tree<T>::count_if(bool (*f)(iterator)) {
	root().count_if(f);
}

#endif
