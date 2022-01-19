#include "push_swap.h"

void free_stack(t_LinkedDeque *stack)
{
    deleteLinkedDeque(stack);
    free(stack);
}

void free_all(t_LinkedDeque *a, t_LinkedDeque *b)
{
    free_stack(a);
    free_stack(b);
}