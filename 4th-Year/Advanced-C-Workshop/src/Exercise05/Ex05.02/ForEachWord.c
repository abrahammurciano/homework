#include "ForEachWord.h"
#include <string.h>

void ForEachWord(const char *sentence, char *delim, StringConsumer consumer, ...)
{
    va_list args;
    va_start(args, consumer);
    for (char *word = strtok(strdup(sentence), delim); word; word = strtok(NULL, delim))
    {
        va_list args_copy;
        va_copy(args_copy, args);
        consumer(word, args_copy);
        va_end(args_copy);
    }
    va_end(args);
}