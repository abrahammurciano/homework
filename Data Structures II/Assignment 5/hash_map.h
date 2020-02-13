#ifndef hash_map_h
#define hash_map_h

#include "double_hasher.h"
#include "prime.h"

template <class K, class T>
class hash_map {
  private:
	typedef pair<K, T> record;

	class slot {
	  public:
		bool deleted;
		record* rec;

		slot(record* rec = 0);
		slot(K key, T value);
		~slot();

		bool sentinel() const;	// Returns true if the slot is a sentinel
		bool empty() const;		// Returns true when the record pointer is null. Will return false for occupied slots and sentinel slots
	};

	int slots;
	int _size;
	slot* table;
	double_hasher<K> hash;

	void expand();

  public:
	class iterator {
	  private:
		slot* slot_ptr;
		enum direction { backward, forward };

		iterator(slot* slot_ptr);
		void shift(direction);

	  public:
		explicit operator bool() const {
			return slot_ptr != 0;
		}
		// Operators
		bool operator==(const iterator& i) const;
		bool operator!=(const iterator& i) const;
		iterator operator++();
		iterator operator++(int);
		iterator operator--();
		iterator operator--(int);
		record& operator*() const;
	};

	hash_map();
	hash_map(int n);
	~hash_map();
	int size() const;
	iterator find(K key) const;
	// Inserts key into table and returns an iterator
	iterator insert(K key);
	// Inserts key and value into table and returns an iterator
	iterator insert(K key, T value);
	// Returns the value (by reference) corresponding to given key. If the key doesn't exist, the key will be added
	T& operator[](K key);

	iterator begin() const;
	iterator end() const;
};

template <class K, class T>
hash_map<K, T>::hash_map() : hash_map(0) {}

template <class K, class T>
hash_map<K, T>::hash_map(int n) : _size(0), hash(0) {
	if (n < 0) {
		throw std::runtime_error("Error: Cannot have a negative number of values in a hash_map.");
	}
	slots = n < 10 ? 17 : prime::next_prime(n * 1.5);  // Make sure the number of slots is prime and bigger than the amount of value to reduce the load factor
	table = (new slot[slots + 2]) + 1;				   // Add an extra slot for a sentinel value before and after the array
	table[slots].rec = (record*)&table[slots];		   // Sentinel slot will point to itself
	table[-1].rec = (record*)&table[-1];			   // Sentinel slot will point to itself
	hash = double_hasher<K>(slots);
}

template <class K, class T>
hash_map<K, T>::~hash_map() {
	delete[](table - 1);  // Must delete one spot behind the start of the table to also delete the first sentinel
}

template <class K, class T>
int hash_map<K, T>::size() const {
	return _size;
}

template <class K, class T>
void hash_map<K, T>::expand() {
	hash_map<K, T> temp_map(2 * slots);
	for (iterator i = begin(); i != end(); ++i) {
		temp_map[(*i).first] = (*i).second;
	}
	delete[](table - 1);

	table = temp_map.table;
	_size = temp_map._size;
	slots = temp_map.slots;
	hash = temp_map.hash;

	temp_map.table = 0;
}

template <class K, class T>
typename hash_map<K, T>::iterator hash_map<K, T>::insert(K key) {
	if (size() >= slots) {	// If the table is full, double the size and rehash
		expand();
	}
	// Find the first hash that maps to an empty slot
	int index, i = 0;
	do {
		index = hash(key, i);
	} while (!table[index].empty());
	// Put the key in the slot and default construct a value
	table[index] = slot(key, T());
	return iterator(&table[index]);
}

template <class K, class T>
typename hash_map<K, T>::iterator hash_map<K, T>::insert(K key, T value) {
	iterator i = find(key);
	if (!i) {  // If the key doesn't exist
		i = insert(key);
	}

	(*i).second = value;
	return i;
}

template <class K, class T>
typename hash_map<K, T>::iterator hash_map<K, T>::find(K key) const {
	int index;
	for (int i = 0; i < slots; ++i) {
		index = hash(key, i);
		if (table[index].rec->first == key) {
			return iterator(&table[index]);
		}
		if (table[index].empty() && !table[index].deleted) {
			return end();
		}
	}
	return end();
}

template <class K, class T>
T& hash_map<K, T>::operator[](K key) {
	iterator i = find(key);
	if (!i) {  // If the key doesn't already exist
		i = insert(key);
	}
	return (*i).second;	 // Return the corresponding value by reference
}

template <class K, class T>
typename hash_map<K, T>::iterator hash_map<K, T>::begin() const {
	iterator i(table - 1);
	return ++i;
}

template <class K, class T>
typename hash_map<K, T>::iterator hash_map<K, T>::end() const {
	return iterator(0);
}

template <class K, class T>
hash_map<K, T>::iterator::iterator(slot* slot_ptr) : slot_ptr(slot_ptr) {}

template <class K, class T>
bool hash_map<K, T>::iterator::operator==(const iterator& i) const {
	return slot_ptr == i.slot_ptr;
}

template <class K, class T>
bool hash_map<K, T>::iterator::operator!=(const iterator& i) const {
	return slot_ptr != i.slot_ptr;
}

template <class K, class T>
void hash_map<K, T>::iterator::shift(direction d) {
	do {
		slot_ptr += (d == forward ? 1 : -1);
	} while (slot_ptr->empty());
	if (slot_ptr->sentinel()) {
		slot_ptr = 0;
	}
}

template <class K, class T>
typename hash_map<K, T>::iterator hash_map<K, T>::iterator::operator++() {
	shift(forward);
	return *this;
}

template <class K, class T>
typename hash_map<K, T>::iterator hash_map<K, T>::iterator::operator++(int) {
	iterator temp_i = *this;
	shift(forward);
	return temp_i;
}

template <class K, class T>
typename hash_map<K, T>::iterator hash_map<K, T>::iterator::operator--() {
	shift(backward);
	return *this;
}

template <class K, class T>
typename hash_map<K, T>::iterator hash_map<K, T>::iterator::operator--(int) {
	iterator temp_i = *this;
	shift(backward);
	return temp_i;
}

template <class K, class T>
pair<K, T>& hash_map<K, T>::iterator::operator*() const {
	return *(slot_ptr->rec);
}

template <class K, class T>
hash_map<K, T>::slot::slot(record* rec) : deleted(false), rec(rec) {}

template <class K, class T>
hash_map<K, T>::slot::slot(K key, T value) : slot(new record(key, value)) {}

template <class K, class T>
hash_map<K, T>::slot::~slot() {
	if (!sentinel()) {
		delete rec;
	}
}

template <class K, class T>
bool hash_map<K, T>::slot::sentinel() const {
	return (slot*)rec == this;	// A sentinel slot has its record pointer pointing to itself
}

template <class K, class T>
bool hash_map<K, T>::slot::empty() const {
	return rec == 0;
}

#endif