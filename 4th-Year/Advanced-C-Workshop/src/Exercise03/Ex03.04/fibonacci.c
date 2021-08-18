#include "fibonacci.h"
#include <stdlib.h>

#define TABLE_SIZE 100

static mpz_t *table[TABLE_SIZE] = { NULL };

void remember(uint n, mpz_t result)
{
    if (n < TABLE_SIZE)
    {
        table[n] = malloc(sizeof(mpz_t));
        mpz_init_set(*table[n], result);
    }
}

void set_base_cases()
{
    if (!table[1])
    {
        mpz_t value;
        mpz_init(value);
        remember(0, value);
        mpz_set_ui(value, 1);
        remember(1, value);
    }
}

void fibonacci(uint n, mpz_t result)
{
    set_base_cases();
    mpz_init(result);

    if (n < TABLE_SIZE && table[n])
    {
        mpz_set(result, *table[n]);
        return;
    }

    mpz_t prev_a, prev_b;
    fibonacci(n - 2, prev_a);
    fibonacci(n - 1, prev_b);
    mpz_add(result, prev_a, prev_b);
    remember(n, result);
}