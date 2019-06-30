/*
 * File Name:				BST.h
 * Program Description:		Binary search trees
 * Course Name:				Workshop in C++
 * Assignment Number:		11
 * Question Number:			1
 * Author:					Abraham Murciano
 */

#ifndef BST_h
#define BST_h

//#include <iostream>
#include "Tree.h"
#include <stdlib.h>
using namespace std;

template <class T>
class BST : public Tree<T> {
  protected:
	class Node : public Tree<T>::Node {
		friend BST;

	  public:
		using Tree<T>::Node::Node;
	};
	using Tree<T>::_root;
	using Tree<T>::node_begin;
	using Tree<T>::node_end;
	using Tree<T>::node_root;

  public:
	class iterator : public Tree<T>::iterator {
		friend BST;

	  protected:
		using Tree<T>::iterator::node;
		using Tree<T>::iterator::iterator;
		using Tree<T>::iterator::setLeft;
		using Tree<T>::iterator::setRight;

	  public:
		iterator left() const;
		iterator right() const;
		iterator parent() const;
		iterator bottomLeft() const;
		iterator bottomRight() const;
		iterator next() const;
		iterator prev() const;
	};
	using Tree<T>::insert;
	using Tree<T>::remove;
	using Tree<T>::empty;
	using Tree<T>::leaves;
	using Tree<T>::height;
	using Tree<T>::reflect;
	using Tree<T>::onlyLeftChild;
	using Tree<T>::for_each;
	using Tree<T>::count_if;

	// Methods
	iterator begin() const;
	iterator end() const;
	iterator root() const;
	iterator search(const T& val) const;
	iterator insert(const T& val);
	iterator remove(iterator i);
	iterator remove(const T& val);
	int level(iterator i) const;
	int level(const T& val) const;
};

template <class T>
typename BST<T>::iterator BST<T>::iterator::left() const {
	return node->node_left();
}

template <class T>
typename BST<T>::iterator BST<T>::iterator::right() const {
	return node->node_right();
}

template <class T>
typename BST<T>::iterator BST<T>::iterator::parent() const {
	return node->node_parent();
}

template <class T>
typename BST<T>::iterator BST<T>::iterator::bottomLeft() const {
	return node->node_bottomLeft();
}

template <class T>
typename BST<T>::iterator BST<T>::iterator::bottomRight() const {
	return node->node_bottomRight();
}

template <class T>
typename BST<T>::iterator BST<T>::iterator::next() const {
	return node->node_next();
}

template <class T>
typename BST<T>::iterator BST<T>::iterator::prev() const {
	return node->node_prev();
}

template <class T>
typename BST<T>::iterator BST<T>::begin() const {
	return node_begin();
}

template <class T>
typename BST<T>::iterator BST<T>::end() const {
	return node_end();
}

template <class T>
typename BST<T>::iterator BST<T>::root() const {
	return node_root();
}

template <class T>
typename BST<T>::iterator BST<T>::search(const T& val) const {
	for (iterator i = root(); i; i = (val < *i) ? i.left() : i.right()) {
		if (val == *i) {
			return i;
		}
	}
}

template <class T>
typename BST<T>::iterator BST<T>::insert(const T& val) {
	iterator temp(new Node(val));
	if (empty()) {
		_root = temp.node;
		return root();
	} else {
		iterator i = root();
		while (i) {
			if (val <= *i) {
				if (!i.left()) {
					i.setLeft(temp);
					return temp;
				}
				i = i.left();
			} else {
				if (!i.right()) {
					i.setRight(temp);
					return temp;
				}
				i = i.right();
			}
		}
	}
}

template <class T>
typename BST<T>::iterator BST<T>::remove(iterator i) {
	if (i) {
		iterator nextNode = i.next();
		if (i.leaf()) {
			(i.parent().left() == i) ? i.parent().setLeft(end()) : i.parent().setRight(end());
		} else if (!(i.left() && i.right())) {
			iterator inheritor = i.left() ? i.left() : i.right();
			(i.parent().left() == i) ? i.parent().setLeft(inheritor)
									 : i.parent().setRight(inheritor);
		} else {
			iterator predecessor = i.left().bottomRight();
			swap(*i, *predecessor);
			remove(predecessor);
			delete predecessor.node;
			return i;
		}
		delete i.node;
		return nextNode;
	}
	return end();
}

template <class T>
typename BST<T>::iterator BST<T>::remove(const T& val) {
	remove(search(val));
}

template <class T>
int BST<T>::level(iterator i) const {
	int level = 0;
	for (iterator it = root(); it; it = (*i <= *it) ? it.left() : it.right(), level++) {
		if (i == it) {
			return level;
		}
	}
	return -1;
}

template <class T>
int BST<T>::level(const T& val) const {
	int level = 0;
	for (iterator i = root(); i; i = (val <= *i) ? i.left() : i.right(), level++) {
		if (val == *i) {
			return level;
		}
	}
	return -1;
}

#endif
