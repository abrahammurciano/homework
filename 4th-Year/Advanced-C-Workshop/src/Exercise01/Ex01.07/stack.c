#include "stack.h"

Stack *CreateStack()
{
    Stack *stack = malloc(sizeof(Stack));
    stack->head = NULL;
    return stack;
}

void DestroyStack(Stack *stack)
{
    int temp;
    while (pop(stack, &temp));
    free(stack);
}

/**
 * @brief Create a node object
 *
 * @param value The integer value to be stored by the node.
 * @param next A pointer to the next node.
 * @return Node* A pointer to the created node.
 */
Node *CreateNode(int value, Node *next)
{
    Node *new = malloc(sizeof(Node));
    new->value = value;
    new->next = next;
}

/**
 * @brief Destroy a node object
 *
 * @param node A pointer to the node to destroy.
 * @return Node* A pointer to the next node.
 */
Node *DestroyNode(Node *node)
{
    Node *next = node->next;
    free(node);
    return next;
}

void push(Stack *stack, int value)
{
    stack->head = CreateNode(value, stack->head);
}

bool pop(Stack *stack, int *value)
{
    if (IsEmpty(stack))
    {
        return false;
    }
    *value = stack->head->value;
    stack->head = DestroyNode(stack->head);
    return true;
}

bool IsEmpty(const Stack *stack)
{
    return stack->head == NULL;
}