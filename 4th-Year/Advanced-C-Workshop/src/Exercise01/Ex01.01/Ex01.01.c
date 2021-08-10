/**
 * @file Ex01.01.c
 * @author Abraham Murciano (abrahammurciano@gmail.com)
 * @brief A program that receives character input from the user and prints it. The program terminates when the input is 'Q' or 'q'.
 * @version 0.1
 * @date 2021-08-09
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ForEachChar.h"

 /**
  * @brief Echoes back to the console a given character.
  *
  * @param c The character to be echoed back.
  */
void EchoChar(char c)
{
    printf("You entered:\n%c\n", c);
}

/**
 * @brief A program that receives character input from the user and prints it. The program terminates when the input is 'Q' or 'q'.
 *
 * @return int 0
 */
int main()
{
    ForEachChar("Enter a character:\n", EchoChar, 'q');
    return 0;
}