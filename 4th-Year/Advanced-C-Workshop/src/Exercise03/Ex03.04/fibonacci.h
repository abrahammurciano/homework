#ifndef fibonacci_h
#define fibonacci_h

#include <gmp.h>

typedef unsigned int uint;

/**
 * @brief Get the nth fibonacci number.
 *
 * @param n The index of the fibonacci number to get.
 * @param result an mpz_t where the nth fibonacci number will be stored.
 */
void fibonacci(uint n, mpz_t result);

#endif