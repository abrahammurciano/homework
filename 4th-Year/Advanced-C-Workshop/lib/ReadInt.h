/**
 * @file ReadInt.h
 * @author Abraham Murciano (abrahammurciano@gmail.com)
 * @brief Read an integer from stdin.
 * @version 0.1
 * @date 2021-08-11
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef ReadInt_h
#define ReadInt_h

/**
 * @brief Read an integer from stdin after printing the given prompt.
 *
 * @param prompt The string to prompt the user with.
 * @return int  The integer read.
 */
int ReadInt(const char *prompt);

/**
 * @brief Takes an input int between min and max inclusive, then returns the input. If the input is out of bounds, it prints an error message and tries again.
 *
 * @param min The smallest valid value.
 * @param max The largest valid value.
 * @return int The input value.
 */
int ReadIntInRange(const char*prompt, int min, int max);

#endif // !ReadInt_h