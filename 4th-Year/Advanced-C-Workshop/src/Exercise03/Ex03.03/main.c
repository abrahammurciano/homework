#include "fibonacci.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    for (size_t i = 0; i < 94; ++i)
    {
        printf("%lu: %llu\n", i, fibonacci(i));
    }

    return 0;
}