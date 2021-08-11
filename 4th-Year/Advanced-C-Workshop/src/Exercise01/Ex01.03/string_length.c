/**
 * @file string_length.c
 * @author Abraham Murciano (abrahammurciano@gmail.com)
 * @brief My own implementation of the strlen() standard C function.
 * @version 0.1
 * @date 2021-08-10
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <stdlib.h>
#include <stdio.h>

 /**
  * @brief Get the number of characters in a string (not including the null terminator).
  *
  * @param str The string to get the length of.
  * @return size_t The length of the string.
  */
size_t strlen(const char *str)
{
    size_t count;
    for (count = 0; *str; ++str, ++count);
    return count;
}

/**
 * @brief Prints a string and its length.
 *
 * @param str The string to print.
 */
void PrintStringSize(const char *str)
{
    printf("The size of \"%s\" is %lu characters.\n", str, strlen(str));
}

int main()
{
    char *line = NULL;
    size_t length;
    printf("Enter a string:\n");
    getline(&line, &length, stdin);
    PrintStringSize(line);
    free(line);
    return 0;
}