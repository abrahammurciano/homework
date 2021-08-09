#include <stdio.h>
#include <stdlib.h>
#include "PrintDiamond.h"

/**
 * @brief Get the smallest odd number greater than or equal to the given number.
 *
 * @param n The given number.
 * @return int `n+1` if `n` is even, otherwise `n`.
 */
int NextOdd(int n)
{
    return n / 2 * 2 + 1;
}

/**
 * @brief Print a single line of a diamond with the specified number of spaces and non-spaces.
 *
 * @param spaces The number of spaces to print before this line.
 * @param symbols The number of symbols to print after the spaces.
 * @param symbol The symbol to print.
 */
void PrintDiamondLine(uint spaces, uint symbols, char symbol)
{
    for (size_t i = 0; i < spaces; ++i)
    {
        printf(" ");
    }
    for (size_t i = 0; i < symbols; ++i)
    {
        printf("%c", symbol);
    }
    printf("\n");
}


void PrintDiamond(uint baseSize, char symbol)
{
    baseSize = NextOdd(baseSize); // if even, bump to next odd.
    int spaces = baseSize / 2; // the absolute value of this variable is the number of spaces.
    int symbols = baseSize - 1; // baseSize minus the absolute value of this variable is the number of symbols.
    for (size_t i = 0; i < baseSize; ++i)
    {
        PrintDiamondLine(abs(spaces), baseSize - abs(symbols), symbol);
        --spaces;
        symbols -= 2;
    }
}