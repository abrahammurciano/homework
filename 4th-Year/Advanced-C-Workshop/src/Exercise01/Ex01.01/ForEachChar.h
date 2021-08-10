/**
 * @file ForEachChar.h
 * @author Abraham Murciano (abrahammurciano@gmail.com)
 * @brief Prompts the user for input of a single character repeatedly, and for each character runs a given function. The loop terminates when the specified terminator character is input.
 * @version 0.1
 * @date 2021-08-09
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef ForEachChar_h
#define ForEachChar_h

 /**
  * @brief Prompts the user for input of a single character repeatedly, and for each character runs a given function. The loop terminates when the specified terminator character is input.
  *
  * @param prompt The prompt to show the user before reading each line.
  * @param function The function to run on each line.
  * @param terminator The character to end the loop with.
  */
void ForEachChar(const char *prompt, void (*function)(char), char terminator);

#endif // !ForEachLine_h