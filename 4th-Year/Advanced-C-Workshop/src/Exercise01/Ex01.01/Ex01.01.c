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
#include "ForEachLine.h"

 /**
  * @brief Echoes back to the console a given line.
  *
  * @param line The line to be echoed back.
  */
void EchoLine(char *line)
{
    printf("You entered:\n%s", line);
}

/**
 * @brief A program that receives character input from the user and prints it. The program terminates when the input is 'Q' or 'q'.
 *
 * @return int 0
 */
int main()
{
    ForEachLine("Enter a string:\n", EchoLine, 'q');
    return 0;
}