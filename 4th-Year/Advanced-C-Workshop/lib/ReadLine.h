#ifndef getline_h
#define getline_h

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief This function reads an entire line from stream, storing the address of the buffer containing the text into *lineptr. The buffer is null-terminated and includes the newline character, if one was found.
 *
 * If *lineptr is set to NULL before the call, then getline() will allocate a buffer for storing the line. This buffer should be freed by the user program even if getline() failed.
 *
 * Alternatively, before calling getline(), *lineptr can contain a pointer to a malloc-allocated buffer *n bytes in size.  If the buffer is not large enough to hold the line, getline() resizes it with realloc, updating *lineptr and *n as necessary.
 In either case, on a successful call, *lineptr and *n will be updated to reflect the buffer address and allocated size respectively.
 *
 * @param lineptr A pointer to the buffer which will contain the line. If its value is NULL, a buffer will be allocated.
 * @param n A pointer to the size of the buffer. This value will be updated as necessary.
 * @return size_t The number of characters read, or -1 on error.
 */
size_t ReadLine(const char *prompt, char **lineptr, size_t *n);

#endif