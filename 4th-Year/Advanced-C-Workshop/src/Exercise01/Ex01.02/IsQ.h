/**
 * @file IsQ.h
 * @author Abraham Murciano (abrahammurciano@gmail.com)
 * @brief Checks if a string is an uppercase or lowercase Q followed by a new line.
 * @version 0.1
 * @date 2021-08-09
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef IsQ_h
#define IsQ_h

#include <stdbool.h>

 /**
    * @brief Checks if a string is an uppercase or lowercase Q followed by a new line.
    *
    * @param line The string to check.
    * @return true if the string consists of a Q and a new line.
    * @return false otherwise.
    */
bool IsQ(char *line);

#endif // !IsQ_h