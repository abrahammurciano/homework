/**
 * @file PrintDiamond.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2021-08-10
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef PrintDiamond_h
#define PrintDiamond_h

typedef unsigned int uint;

/**
 * @brief Print a diamond of the given (odd) size with the given symbol.
 *
 * @param baseSize The number of symbols in the middle row. This value must be odd. If an even number is given, the next odd number will be used instead.
 * @param symbol The symbol to use to make the diamond.
 */
void PrintDiamond(uint baseSize, char symbol);

#endif // !PrintDiamond_h