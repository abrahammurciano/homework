/**
 * @file Ex01.02.c
 * @author Abraham Murciano (abrahammurciano@gmail.com)
 * @brief A program that receives character input from the user and prints it in upper-case. The program terminates when the input is 'Q' or 'q'.
 * @version 0.1
 * @date 2021-08-09
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "ForEachLine.h"

 /**
  * @brief Prints a string in upper case.
  *
  * @param string The string to print in upper case.
  */
void PrintUpperCase(char *string)
{
    printf("Your string in upper case is:\n");
    for (size_t i = 0; string[i] != '\0'; ++i)
    {
        printf("%c", toupper(string[i]));
    }
}

/**
 * @brief A program that receives character input from the user and prints it in upper-case. The program terminates when the input is 'Q' or 'q'.
 *
 * @return int 0
 */
int main()
{
    ForEachLine("Enter a string:\n", PrintUpperCase, 'q');
    return 0;
}