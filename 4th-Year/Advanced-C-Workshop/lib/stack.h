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

#ifndef Stack_h
#define Stack_h

#include <stdlib.h>
#include <stdbool.h>

 /**
  * @brief A stack node contains one datum and a pointer to the next node.
  */
typedef struct Node
{
    void *value;
    struct Node *next;
} Node;

/**
 * @brief A data structure which allows pushing and popping of data in a last in first out order.
 * @relates Stack
 */
typedef struct Stack
{
    Node *head;
} Stack;

/**
 * @brief Create a stack object.
 * @relates Stack
 *
 * @return Stack The stack that was created.
 */
Stack *CreateStack();

/**
 * @brief Destroy a stack object.
 * @relates Stack
 *
 * @param s The stack to be destroyed.
 */
void DestroyStack(Stack *s);

/**
 * @brief Push a value onto the top of the stack.
 * @relates Stack
 *
 * @param s The stack to push a value to.
 * @param value The value to push onto the stack.
 */
void Push(Stack *s, void *value);

/**
 * @brief Pop a value from the top of the stack.
 * @relates Stack
 *
 * @param s The stack to pop a value from.
 * @param value A pointer to where the popped value will be stored.
 * @return true if there was a value to pop, or false if the stack was empty.
 */
bool Pop(Stack *s, void **value);

/**
 * @brief Check if the stack is empty.
 * @relates Stack
 *
 * @param s The stack to be checked.
 * @return true if there are no elements in the stack, or false if there are.
 */
bool IsEmpty(const Stack *s);

#endif // !Stack_h