#ifndef hash_map_h
#define hash_map_h

#include "double_hasher.h"
#include "prime.h"

template <class K, class T>
class hash_map {
  private:
	class slot {
	  private:
		bool deleted;
		record* rec;

	  public:
		slot();
		slot(K key, T value);
	};

	class record {
	  private:
		K key;
		T value;

	  public:
		record(K key, T value);
	};

	int slots;
	int _size;
	slot* table;
	double_hasher<K> hash;

	void expand();

  public:
	hash_map();
	hash_map(int n);
	~hash_map();
	int size() const;
	void insert(K key, T value);

	class iterator {
	  private:
		slot* ptr;

		iterator(slot* ptr);

	  public:
		// Operators
		bool operator==(const iterator& i) const;
		bool operator!=(const iterator& i) const;
		iterator operator++();
		iterator operator++(int);
		iterator operator--();
		iterator operator--(int);
		T& operator*() const;
	}
};

template <class K, class T>
hash_map<K, T>::record::record(K key, T value) : key(key), value(value) {}

template <class K, class T>
hash_map<K, T>::hash_map() : hash_map(0) {}

template <class K, class T>
hash_map<K, T>::hash_map(int n) : _size(0), hash(0) {
	if (n < 0) {
		throw std::runtime_error("Error: Cannot have a negative number of values in a hash_map.");
	}
	slots = n < 10 ? 17 : prime::next_prime(n * 1.5);  // Make sure the number of slots is prime and bigger than the amount of value to reduce the load factor
	table = new record* [slots] { 0 };
	hash = double_hasher<K>(slots);
}

template <class K, class T>
hash_map<K, T>::~hash_map() {
	for (int i = 0; i < slots; ++i) {
		delete[] table[i];
	}
	delete[] table;
}

template <class K, class T>
int hash_map<K, T>::size() const {
	return _size;
}

template <class K, class T>
void hash_map<K, T>::insert(K key, T value) {
	// TODO: check if key already exits
	for (int i = 0; i < slots; ++i) {
		int index = hash(key, i);
		if (table[index] == 0) {
			table[index] = new T(value);
			return;
		}
	}
	expand();
	insert(key, value);
}

template <class K, class T>
void hash_map<K, T>::expand() {
	hash_map<K, T> temp_map(2 * slots);
	// TODO: insert all the keys into the temp_map
	delete[] table;
	table = temp_map.table;
	temp_map.table = 0;
}

template <class K, class T>
hash_map<K, T>::iterator::iterator(slot* pointer) : pointer(pointer) {}

template <class K, class T>
bool hash_map<K, T>::iterator::operator==(const iterator& i) const {
	return index == i.index;
}

template <class K, class T>
bool hash_map<K, T>::iterator::operator!=(const iterator& i) const {
	return index != i.index;
}

template <class K, class T>
typename hash_map<K, T>::iterator hash_map<K, T>::iterator::operator++() {
	// TODO
}

template <class K, class T>
typename hash_map<K, T>::iterator hash_map<K, T>::iterator::operator++(int) {
	// TODO
}

template <class K, class T>
typename hash_map<K, T>::iterator hash_map<K, T>::iterator::operator--() {
	// TODO
}

template <class K, class T>
typename hash_map<K, T>::iterator hash_map<K, T>::iterator::operator--(int) {
	// TODO
}

template <class K, class T>
T& hash_map<K, T>::iterator::operator*() const {
	// TODO
}

#endif
