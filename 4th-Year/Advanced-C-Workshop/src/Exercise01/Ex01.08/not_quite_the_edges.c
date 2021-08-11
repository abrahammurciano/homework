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
#include "ReadInt.h"

typedef bool (*BinaryIntPredicate)(int, int);
typedef int (*IntProducer) ();

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
void SwapIf(int *a, int *b, BinaryIntPredicate predicate)
{
    if (predicate(*a, *b))
    {
        Swap(a, b);
    }

}

/**
 * @brief Given two ineger pointers and an integer, it puts the most extreme of the three integers into `*edge` and the second most extreme into `*almostEdge`. Extremity is determined according to the given `predicate`.
 *
 * @param edge A pointer to the most extreme of the three numbers. If `input` is more extreme, its value is updated to that of `input`.
 * @param almostEdge A pointer to the second most extreme number. If `input` is more extreme, its value will be updated to the median of the three ints.
 * @param input The new number to consider.
 * @param predicate A function which takes two integers and returns true if the first integer is more extreme than the second, or false otherwise.
 */
void UpdateEdge(int *edge, int *almostEdge, int input, BinaryIntPredicate predicate)
{
    SwapIf(&input, edge, predicate);
    SwapIf(&input, almostEdge, predicate);
}

/**
 * @brief Takes input from `producer` until a `terminator` is inputted. Places the second smallest and second largest values into the given addresses.
 *
 * @param secondSmallest The address where the second smallest input should be stored.
 * @param secondLargest The address where the second largest input should be stored.
 * @param producer A function which takes no parameters and returns an int.
 * @param terminator The value for which the function should end when equal to the input.
 * @return int 0 on success. -1 if too few (less than two) inputs were received before receiving the terminator.
 */
int NotQuiteTheEdges(int *secondSmallest, int *secondLargest, IntProducer producer, int terminator)
{
    int smallest = INT_MAX;
    int largest = INT_MIN;
    *secondSmallest = INT_MAX;
    *secondLargest = INT_MIN;

    for (int count = 0; true; ++count)
    {
        int input = producer();
        if (input == terminator)
        {
            return count < 2 ? -1 : 0;
        }
        UpdateEdge(&smallest, secondSmallest, input, LessThan);
        UpdateEdge(&largest, secondLargest, input, GreaterThan);
    }
}

int ProduceFromStdin()
{
    return ReadInt("Enter a number: ");
}

int main()
{
    int secondSmallest;
    int secondLargest;

    while (NotQuiteTheEdges(&secondSmallest, &secondLargest, ProduceFromStdin, 0) != 0)
    {
        printf("Error: You must enter at least two numbers. Please start over.\n");
    }

    printf("The second largest number is: %d\n", secondLargest);
    printf("The second smallest number is: %d\n", secondSmallest);

    return 0;
}