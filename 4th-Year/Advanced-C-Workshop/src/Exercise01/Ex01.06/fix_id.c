/**
 * @file fix_id.c
 * @author Abraham Murciano (abrahammurciano@gmail.com)
 * @brief Check the validity of an Israeli ID number.
 * @version 0.1
 * @date 2021-08-10
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <stdbool.h>
#include <stdio.h>
#include "ReadInt.h"

 /**
  * @brief Sums all the digits of parameter n
  *
  * @param n The number whose digits should be summed.
  * @return int The sum of all the digits.
  */
int SumDigits(int n)
{
    int sum = 0;

    do
    {
        sum += n % 10;
    } while (n /= 10);

    return sum * (sum > 0 ? 1 : -1);  // Takes into account negative numbers
}

/**
 * @brief Returns the check digit of 8 digit number n.
 *
 * @param n The 8 digit number to calculate the CheckDigit for.
 * @return int The check digit of 8 digit number.
 */
int CheckDigit(int n)
{
    int sum = 0;
    int weight = 2;

    do
    {
        int digit = n % 10;
        sum += SumDigits(digit * weight);
        weight = 1 + (weight == 1); // Toggle weight between 1 and 2
    } while (n /= 10);

    int sumLastDigit = sum % 10;
    int checkDigit = 10 - sumLastDigit;
    checkDigit %= 10;

    return checkDigit;
}

int main()
{
    int id = ReadIntInRange("Enter the first 8 digits of your ID: ", 0, 99999999);  // Variable to store user input

    printf("Your ID number is: %d%d\n", id, CheckDigit(id));

    return 0;
}