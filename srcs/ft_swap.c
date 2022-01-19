#include "push_swap.h"

int swap_stack(t_LinkedDeque *stack)
{
    t_DequeNode *first;
    t_DequeNode *second;
    // t_DequeNode pFirst;
    // t_DequeNode pSecond;

    if (stack->currentElementCount < 2)
        return (FALSE);
    first = deleteRearLD(stack);
    second = deleteRearLD(stack);
    // pFirst = *first;
    // pSecond = *second;
    if (insertRearLD(stack, *first) == FALSE)
    {
        free_stack(stack);
        insert_error();
    }
    if (insertRearLD(stack, *second) == FALSE)
    {
        free_stack(stack);
        insert_error();
    }
    free(first);
    free(second);
    return (TRUE);
}

void ft_sa(t_LinkedDeque *a)
{
    if (swap_stack(a) == FALSE)
        return ;
    write(1, "sa\n", 3);
}

void ft_sb(t_LinkedDeque *b)
{
    if (swap_stack(b) == FALSE)
        return ;
    write(1, "sa\n", 3);
}

void ft_ss(t_LinkedDeque *a, t_LinkedDeque *b)
{
    if ((swap_stack(a) == FALSE) || (swap_stack(b) == FALSE))
        return ;
    write(1, "ss\n", 3);
}