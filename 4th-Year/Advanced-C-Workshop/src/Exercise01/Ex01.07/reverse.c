/**
 * @file reverse.c
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
#include "ReadInt.h"

int main()
{
    Stack *stack = CreateStack();
    int value;
    int *copy;
    while (true)
    {
        value = ReadInt("Enter a number: ");
        if (value == 0)
        {
            break;
        }
        copy = malloc(sizeof(int));
        *copy = value;
        Push(stack, copy);
    }

    printf("The numbers in reverse order are:\n");

    while (Pop(stack, (void *) &copy))
    {
        printf("%d ", *copy);
        free(copy);
    }
    printf("\n");
    DestroyStack(stack);
    return 0;
}