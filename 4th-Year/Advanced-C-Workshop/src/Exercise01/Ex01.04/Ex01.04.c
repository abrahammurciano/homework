/**
 * @file Ex01.04.c
 * @author Abraham Murciano (abrahammurciano@gmail.com)
 * @brief Print diamonds of any size.
 * @version 0.1
 * @date 2021-08-10
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <stdio.h>
#include "PrintDiamond.h"

int main()
{
    int baseSize;
    printf("Enter the size of the diamond: ");
    scanf("%d", &baseSize);
    PrintDiamond(baseSize, '*');
    return 0;
}