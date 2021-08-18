#include "fibonacci.h"
#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int main()
{
    mpz_t nth_fib;
    for (size_t i = 0; i <= 100; ++i)
    {
        fibonacci(i, nth_fib);
        char *nth_fib_str = mpz_get_str(NULL, 10, nth_fib);
        printf("%3lu: %21s\n", i, nth_fib_str);
        free(nth_fib_str);
    }
    mpz_clear(nth_fib);

    return 0;
}