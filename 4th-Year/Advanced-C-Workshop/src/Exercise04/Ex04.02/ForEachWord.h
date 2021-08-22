#ifndef print_reverse_sentence_h
#define print_reverse_sentence_h

#include <stdarg.h>

/**
 * @brief A function which takes a string and a list of arguments and does something with them.
 */
typedef void (*StringConsumer)(char *, va_list);

/**
 * @brief This function takes a sentence, splits it up into words using the given delimiters, and passes each word along with the rest of the arguments to the string consumer provided
 *
 * @param sentence The sentence to split into words.
 * @param delim An array of characters to use as delimiters.
 * @param consumer The function which each word will be passed to along with the rest of the arguments of this function.
 * @param ... The other arguments to pass to the consumer.
 */
void ForEachWord(const char *sentence, char *delim, StringConsumer consumer, ...);

#endif