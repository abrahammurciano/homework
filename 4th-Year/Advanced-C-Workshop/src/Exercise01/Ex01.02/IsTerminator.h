/**
 * @file IsTerminator.h
 * @author Abraham Murciano (abrahammurciano@gmail.com)
 * @brief Checks if a string matches the given character (case insensitively) followed by a new line.
 * @version 0.1
 * @date 2021-08-09
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef IsTerminator_h
#define IsTerminator_h

#include <stdbool.h>

 /**
    * @brief Checks if a string matches the given character (case insensitively) followed by a new line.
    *
    * @param line The string to check.
    * @param terminator The character to check against.
    * @return true if the string consists of a Terminator and a new line.
    * @return false otherwise.
    */
bool IsTerminator(char *line, char terminator);

#endif // !IsTerminator_h