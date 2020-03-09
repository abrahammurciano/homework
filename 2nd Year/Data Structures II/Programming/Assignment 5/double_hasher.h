#ifndef double_hasher_h
#define double_hasher_h

#include "hasher.h"

template <class K>
class double_hasher {
  private:
	int m;
	hasher<K> h1;
	hasher<K> h2;

  public:
	double_hasher(int m);
	int operator()(K key, int i = 0) const;
};

template <class K>
double_hasher<K>::double_hasher(int m) : m(m), h1(m), h2(m) {}

template <class K>
int double_hasher<K>::operator()(K key, int i) const {
	return (h1(key) + i * h2(key)) % m;
}

#endif
