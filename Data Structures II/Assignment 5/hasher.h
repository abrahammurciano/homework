#ifndef hasher_h
#define hasher_h

#include "prime.h"
#include "random.h"
#include <string>

template <class K>
class hasher;

// ==============
// Integer Hasher
// ==============

template <>
class hasher<int> {
  private:
	int m;
	const static unsigned int p = 2147483659;  // smallest prime number past largest int
	unsigned int a, b;

  public:
	hasher(int m);
	int operator()(int key) const;
};

hasher<int>::hasher(int m) : m(m) {
	a = random::generate(1, p);
	b = random::generate(0, p);
}

int hasher<int>::operator()(int key) const {
	return ((a * key + b) % p) % m;
}

// =============
// String Hasher
// =============

template <>
class hasher<std::string> {
  private:
	int m;
	hasher<int> hash;

  public:
	hasher(int m);
	int operator()(string key) const;
};

hasher<std::string>::hasher(int m) : m(m), hash(hasher<int>(m)) {}

int hasher<std::string>::operator()(string key) const {
	unsigned int h = 0x7FFFFFFF;
	for (auto i = key.begin(); i != key.end(); ++i) {
		h += hash(*i);
	}
	return h % m;
}

#endif
