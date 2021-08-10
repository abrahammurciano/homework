/**
 * @file stack.h
 * @author Abraham Murciano (abrahammurciano@gmail.com)
 * @brief A stack implementation.
 * @version 0.1
 * @date 2021-08-10
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef stack_h
#define stack_h

#include <stdlib.h>
#include <stdbool.h>

 /**
  * @brief A stack node contains one datum and a pointer to the next node.
  */
typedef struct node
{
    int value;
    struct node *next;
} node;

/**
 * @brief A data structure which allows pushing and popping of data in a last in first out order.
 */
typedef struct stack
{
    node *head;
} stack;

/**
 * @brief Create a stack object.
 *
 * @return stack The stack that was created.
 */
stack *create_stack();

/**
 * @brief Destroy a stack object.
 *
 * @param s The stack to be destroyed.
 */
void destroy_stack(stack *s);

/**
 * @brief Push a value onto the top of the stack.
 *
 * @param s The stack to push a value to.
 * @param value The value to push onto the stack.
 */
void push(stack *s, int value);

/**
 * @brief Pop a value from the top of the stack.
 *
 * @param s The stack to pop a value from.
 * @param value A pointer to where the popped value will be stored.
 * @return true if there was a value to pop, or false if the stack was empty.
 */
bool pop(stack *s, int *value);

/**
 * @brief Check if the stack is empty.
 *
 * @param s The stack to be checked.
 * @return true if there are no elements in the stack, or false if there are.
 */
bool is_empty(const stack *s);

#endif // !stack_h