/**
 * @file Ex01.07.c
 * @author Abraham Murciano (abrahammurciano@gmail.com)
 * @brief A program that reads numbers from the user until the number 0 is entered, and then prints them in reverse order.
 * @version 0.1
 * @date 2021-08-10
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <stdbool.h>
#include <stdio.h>
#include "stack.h"

int main()
{
    stack *s = create_stack();
    int value;
    while (true)
    {
        printf("Enter a number: ");
        scanf("%d", &value);
        if (value == 0)
        {
            break;
        }
        push(s, value);
    }

    printf("The numbers in reverse order are:\n");

    while (pop(s, &value))
    {
        printf("%d ", value);
    }
    printf("\n");
    destroy_stack(s);
    return 0;
}