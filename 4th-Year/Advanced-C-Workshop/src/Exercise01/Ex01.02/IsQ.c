#include "IsQ.h"
#include <string.h>

bool IsQ(char *line)
{
    return !(strcmp(line, "q\n") && strcmp(line, "Q\n"));
}