#include "ForEachChar.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

void ForEachChar(const char *prompt, void (*function)(char), char terminator)
{
    char c;
    while (1)
    {
        printf(prompt);
        scanf(" %c", &c);

        if (tolower(c) == tolower(terminator))
        {
            break;
        }

        function(c);
    }
}