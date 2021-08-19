#include "ReadLine.h"

size_t ReadLine(const char *prompt, char **lineptr, size_t *n)
{
    char *bufptr = NULL;
    char *p = bufptr;
    size_t size;
    int c;

    if (lineptr == NULL || stdin == NULL || n == NULL)
    {
        return -1;
    }
    bufptr = *lineptr;
    size = *n;

    printf(prompt);

    c = fgetc(stdin);
    if (c == EOF)
    {
        return -1;
    }
    if (bufptr == NULL)
    {
        bufptr = malloc(size = 128);
        if (bufptr == NULL)
        {
            return -1;
        }
    }
    p = bufptr;
    while (c != EOF)
    {
        if ((p - bufptr) > (size - 1))
        {
            bufptr = realloc(bufptr, size *= 2);
            if (bufptr == NULL)
            {
                return -1;
            }
        }
        *p++ = c;
        if (c == '\n')
        {
            break;
        }
        c = fgetc(stdin);
    }

    *p = '\0';
    *lineptr = bufptr;
    *n = size;

    return p - bufptr;
}