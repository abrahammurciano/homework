#include "prime.h"

unsigned int prime::next_prime(unsigned int n) {
	while (true) {
		if (is_prime(n)) {
			return n;
		}
		++n;
	}
}

bool prime::is_prime(unsigned int n) {
	if (n < 2) {
		return false;
	}
	if (n < 4) {
		return true;
	}
	if (n % 2 == 0) {
		return false;
	}
	for (int i = 3; i * i < n; i += 2) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}