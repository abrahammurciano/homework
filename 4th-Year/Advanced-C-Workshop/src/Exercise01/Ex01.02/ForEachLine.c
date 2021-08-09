#include "ForEachLine.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

/**
 * @brief Checks if a string matches the given character (case insensitively) followed by a new line.
 *
 * @param line The string to check.
 * @param terminator The character to check against.
 * @return true if the string consists of a Terminator and a new line.
 * @return false otherwise.
 */
bool IsTerminator(char *line, char terminator)
{
    return strlen(line) == 2 && line[1] == '\n' && (line[0] == toupper(terminator) || line[0] == tolower(terminator));
}

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