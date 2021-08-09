#include "stack.h"

stack create_stack()
{
    stack *s = malloc(sizeof(stack));
    s->head = NULL;
    return *s;
}

void destroy_stack(stack *s)
{
    // TODO: finish
}