/**
 * @file not_quite_the_edges.c
 * @author Abraham Murciano (abrahammurciano@gmail.com)
 * @brief A program that reads numbers from the user (terminated by 0) and prints the second largest and second smallest numbers.
 * @version 0.1
 * @date 2021-08-10
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>


 /**
  * @brief Check if a is less than b.
  *
  * @param a An integer to compare.
  * @param b An integer to compare.
  * @return true if a < b, false otherwise
  */
bool LessThan(int a, int b)
{
    return a < b;
}

/**
 * @brief Check if a is greater than b.
 *
 * @param a An integer to compare.
 * @param b An integer to compare.
 * @return true if a > b, false otherwise
 */
bool GreaterThan(int a, int b)
{
    return a > b;
}

/**
 * @brief Swap the values at the given addresses.
 *
 * @param a The first address to swap.
 * @param b The second address to swap.
 */
void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Swaps the values at the given addresses only if `predicate(a,b)` is true.
 *
 * @param a The address of the first number.
 * @param b The address of the second number.
 * @param predicate A predicate that takes two integers which determines if a and b should be swapped.
 */
void SwapIf(int *a, int *b, bool (*predicate)(int, int))
{
    if (predicate(*a, *b))
    {
        Swap(a, b);
    }

}

int main()
{
    int smallest = INT_MAX;
    int secondSmallest = INT_MAX;
    int largest = INT_MIN;
    int secondLargest = INT_MIN;
    int inputA, inputB;

    while (true)
    {
        printf("Enter a number:\n");
        scanf("%d", &inputA);
        if (inputA == 0)
        {
            break;
        }
        inputB = inputA;
        SwapIf(&inputA, &smallest, LessThan);
        SwapIf(&inputA, &secondSmallest, LessThan);
        SwapIf(&inputB, &largest, GreaterThan);
        SwapIf(&inputB, &secondLargest, GreaterThan);
    }

    printf("The second largest number is: %d\n", secondLargest);
    printf("The second smallest number is: %d\n", secondSmallest);

    return 0;
}