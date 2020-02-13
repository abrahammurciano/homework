#include "random.h"

bool random::seeded = false;

random::ull random::generate(ull min, ull max) {
	if (!seeded) {
		srand(time(0));
		seeded = true;
	}
	ull random_num = rand();
	random_num <<= 33;
	ull r = rand();
	random_num |= r << 2;
	random_num |= rand() % 4;
	return (random_num % (max - min)) + min;
}

random::ull random::generate(ull max) {
	return generate(0, max);
}