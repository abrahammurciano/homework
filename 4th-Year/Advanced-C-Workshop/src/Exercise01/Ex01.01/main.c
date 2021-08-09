#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Checks if a string is an uppercase or lowercase Q followed by a new line.
 *
 * @param line The string to check.
 * @return true if the string consists of a Q and a new line.
 * @return false otherwise.
 */
bool IsQ(char *line)
{
    return !(strcmp(line, "q\n") && strcmp(line, "Q\n"));
}

/**
 * @brief A program that receives character input from the user and prints it. The program terminates when the input is 'Q' or 'q'.
 *
 * @return int 0
 */
int main()
{
    char *line = NULL;
    size_t length = 0;

    do
    {
        printf("Enter a string:\n");
        getline(&line, &length, stdin);
        printf("You entered:\n%s", line);
    } while (!IsQ(line));

    free(line);
    return 0;
}