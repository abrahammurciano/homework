/**
 * @file diamond.c
 * @author Abraham Murciano (abrahammurciano@gmail.com)
 * @brief Print diamonds of any size.
 * @version 0.1
 * @date 2021-08-10
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <stdio.h>
#include <limits.h>
#include "PrintDiamond.h"
#include "ReadInt.h"

int main()
{
    int baseSize = ReadIntInRange("Enter the size of the diamond: ", 1, INT_MAX);
    PrintDiamond(baseSize, '*');
    return 0;
}