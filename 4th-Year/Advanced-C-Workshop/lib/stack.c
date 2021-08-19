#include "stack.h"

Stack *CreateStack()
{
    Stack *stack = malloc(sizeof(Stack));
    stack->head = NULL;
    return stack;
}

void DestroyStack(Stack *stack)
{
    void *temp;
    while (Pop(stack, &temp));
    free(stack);
}

/**
 * @brief Create a node object
 *
 * @param value A pointer to be stored.
 * @param next A pointer to the next node.
 * @return Node* A pointer to the created node.
 */
Node *CreateNode(void *value, Node *next)
{
    Node *new = malloc(sizeof(Node));
    new->value = value;
    new->next = next;
    return new;
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

void Push(Stack *stack, void *value)
{
    stack->head = CreateNode(value, stack->head);
}

bool Pop(Stack *stack, void **value)
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