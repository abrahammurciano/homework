#ifndef parameters_h
#define parameters_h

#include <stdlib.h>

typedef enum Case
{
    NO_CASE, LOWER_CASE, UPPER_CASE
} Case;

/**
 * @brief Check if a string is upper case, lower case, or neither.
 *
 * A string is upper case if it contains letters between 'A' and 'Z' but not between 'a' and 'z'.
 * A string is lower case if it contains letters between 'a' and 'z' but not between 'A' and 'Z'.
 * A string is neither if it contains either no letters, or both uppercase and lowercase letters.
 *
 * @param str The string to check the case of.
 * @return Case The case of the given string.
 */
Case CaseOf(const char *str);

/**
 * @brief Check if a character is upper case, lower case, or neither.
 *
 * @param character The character to check the case of.
 * @return Case The case of the given character.
 */
Case CaseOfChar(char character);

/**
 * @brief Check how many flags are in a single parameter. For example, there are no flags in the parameter "main.c", there is one flag in "--help", and there are three flags in "-abc" (which is equivalent to "-a -b -c").
 *
 * @param param The parameter whose flags to count. If there is a space or an equals in the parameter, everything after it will be ignored.
 * @return size_t The number of flags in the given parameter.
 */
size_t FlagCount(const char *param);

#endif