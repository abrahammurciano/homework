#include "stack.h"

stack *create_stack()
{
    stack *s = malloc(sizeof(stack));
    s->head = NULL;
    return s;
}

void destroy_stack(stack *s)
{
    int temp;
    while (pop(s, &temp));
    free(s);
}

/**
 * @brief Create a node object
 *
 * @param value The integer value to be stored by the node.
 * @param next A pointer to the next node.
 * @return node* A pointer to the created node.
 */
node *create_node(int value, node *next)
{
    node *n = malloc(sizeof(node));
    n->value = value;
    n->next = next;
}

/**
 * @brief Destroy a node object
 *
 * @param n A pointer to the node to destroy.
 * @return node* A pointer to the next node.
 */
node *destroy_node(node *n)
{
    node *next = n->next;
    free(n);
    return next;
}

void push(stack *s, int value)
{
    s->head = create_node(value, s->head);
}

bool pop(stack *s, int *value)
{
    if (is_empty(s))
    {
        return false;
    }
    *value = s->head->value;
    s->head = destroy_node(s->head);
    return true;
}

bool is_empty(const stack *s)
{
    return s->head == NULL;
}