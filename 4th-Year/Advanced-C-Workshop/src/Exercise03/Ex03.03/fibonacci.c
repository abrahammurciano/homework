#include "fibonacci.h"

ull fibonacci(uint n)
{
    ull result = 0;
    for (ull next = 1; n > 0; --n)
    {
        ull old_result = result;
        result = next;
        next += old_result;
    }
    return result;
}