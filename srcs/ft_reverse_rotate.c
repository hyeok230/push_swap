#include "push_swap.h"

int reverse_rotate_stack(t_LinkedDeque *stack)
{
    t_DequeNode *element;
    int length;

    length = stack->currentElementCount;
    if (length < 2)
        return (FALSE);
    element = deleteRearLD(stack);
    if (element == NULL)
        return (FALSE);
    if (insertFrontLD(stack, *element) == FALSE)
    {
        free_stack(stack);
        insert_error();
    }
    free(element);
    return (TRUE);
}

void ft_rra(t_LinkedDeque *a)
{
    if (reverse_rotate_stack(a) == FALSE)
        return ;
    write(1, "rra\n", 4);
}

void ft_rrb(t_LinkedDeque *b)
{
    if (reverse_rotate_stack(b) == FALSE)
        return ;
    write(1, "rrb\n", 4);
}