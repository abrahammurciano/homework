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

    if (baseSize < 0)
    {
        printf("Number cannot be negative.\n");
        return 1;
    }

    PrintDiamond(baseSize, '*');
    return 0;
}