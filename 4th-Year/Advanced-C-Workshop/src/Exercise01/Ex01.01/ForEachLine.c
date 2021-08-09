#include "ForEachLine.h"
#include "IsTerminator.h"
#include <stdio.h>

void ForEachLine(const char *prompt, void (*function)(char *), char terminator)
{
    char *line = NULL;
    size_t size;
    while (1)
    {
        printf(prompt);
        getline(&line, &size, stdin);

        if (IsTerminator(line, terminator))
        {
            break;
        }

        function(line);
    }
}