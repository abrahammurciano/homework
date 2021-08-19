#include "fibonacci.h"
#include "ReadInt.h"
#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <limits.h>

int main()
{
    mpz_t nth_fib;
    uint n = ReadIntInRange("Which fibonacci number do you want?\n> ", 0, INT_MAX);
    fibonacci(n, nth_fib);
    char *nth_fib_str = mpz_get_str(NULL, 10, nth_fib);
    printf("%s\n", n, nth_fib_str);
    free(nth_fib_str);
    mpz_clear(nth_fib);

    return 0;
}