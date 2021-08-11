#include "ReadInt.h"
#include <stdbool.h>
#include <stdio.h>

int ReadInt(const char *prompt)
{
    int input;
    printf(prompt);
    while (scanf("%d", &input) < 1)
    {
        while (getchar() != '\n');
        printf("Error: Could not read an integer.\n");
        printf(prompt);
    };
    return input;
}

int ReadIntInRange(const char * prompt, int min, int max)
{
    while (true)
    {
        int input = ReadInt(prompt);
        if (input >= min && input <= max)
        {
            return input;
        }
        printf("Error: Input must be between %d and %d\n", min, max);
    }
}
