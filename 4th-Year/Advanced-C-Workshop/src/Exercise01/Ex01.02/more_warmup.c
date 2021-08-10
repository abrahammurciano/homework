/**
 * @file more_warmup.c
 * @author Abraham Murciano (abrahammurciano@gmail.com)
 * @brief A program that receives a single character input from the user and prints it in upper-case. The program terminates when the input is 'Q' or 'q'.
 * @version 0.1
 * @date 2021-08-09
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "ForEachChar.h"

void PrintUpper(char c)
{
    printf("%c\n", toupper(c));
}

/**
 * @brief A program that receives a single character input from the user and prints it in upper-case. The program terminates when the input is 'Q' or 'q'.
 *
 * @return int 0
 */
int main()
{
    ForEachChar("Enter a character:\n", PrintUpper, 'q');
    return 0;
}