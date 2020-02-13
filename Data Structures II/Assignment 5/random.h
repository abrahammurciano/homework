#ifndef random_gen_h
#define random_gen_h

#include <cstdlib>
#include <ctime>

class random {
	typedef unsigned long long ull;

  private:
	static bool seeded;

  public:
	// Generate a random integer in the range [min, max)
	static ull generate(ull min, ull max);
	// Generate a random number in the range [0, max)
	static ull generate(ull max = 0x7fffffff);
};

#endif
