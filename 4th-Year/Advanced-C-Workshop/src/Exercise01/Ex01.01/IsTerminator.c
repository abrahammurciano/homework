#include "IsTerminator.h"
#include <string.h>
#include <ctype.h>

bool IsTerminator(char *line, char terminator)
{
    return strlen(line) == 2 && line[1] == '\n' && (line[0] == toupper(terminator) || line[0] == tolower(terminator));
}