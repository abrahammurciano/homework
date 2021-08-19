#include "fibonacci.h"
#include <stdlib.h>
#include <math.h>

#define TABLE_SIZE 100

static mpz_t *table[TABLE_SIZE] = { NULL };
static uint last_remembered;

uint min(uint a, uint b)
{
    return a < b ? a : b;
}

void remember(uint n, mpz_t result)
{
    if (n < TABLE_SIZE)
    {
        table[n] = malloc(sizeof(mpz_t));
        mpz_init_set(*table[n], result);
        last_remembered = n;
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

void remember_up_to(uint n)
{
    set_base_cases();
    for (size_t i = last_remembered; i < min(n, TABLE_SIZE - 1); ++i)
    {
        mpz_t sum;
        mpz_init(sum);
        mpz_add(sum, *table[i], *table[i - 1]);
        remember(i + 1, sum);
    }

}

void calc_past_table(uint n, mpz_t result)
{
    mpz_t prev_a;
    mpz_t prev_b;
    mpz_t temp;
    mpz_init_set(prev_a, *table[TABLE_SIZE - 2]);
    mpz_init_set(prev_b, *table[TABLE_SIZE - 1]);
    mpz_init(temp);
    for (size_t i = TABLE_SIZE; i <= n; ++i)
    {
        mpz_add(result, prev_a, prev_b);
        mpz_set(temp, prev_a);
        mpz_set(prev_a, prev_b);
        mpz_add(prev_b, prev_b, temp);
    }
    mpz_clear(prev_a);
    mpz_clear(prev_b);
    mpz_clear(temp);
}

void fibonacci(uint n, mpz_t result)
{
    remember_up_to(n);
    if (n < TABLE_SIZE)
    {
        mpz_init_set(result, *table[n]);
    }
    else
    {
        calc_past_table(n, result);
    }
}