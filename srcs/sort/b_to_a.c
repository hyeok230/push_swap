#include "push_swap.h"

void b_to_a_sub(t_sort *sort, t_LinkedDeque *a, t_LinkedDeque *b)
{
    if (b->pFrontNode->data <= sort->pivot_small)
    {
        ft_rb(b);
        sort->rb++;
    }
    else
    {
        ft_pa(a, b);
        sort->pa++;
        if (a->pFrontNode->data <= sort->pivot_big)
        {
            ft_ra(a);
            sort->ra++;
        }
    }
}

void b_to_a(int r, t_LinkedDeque *a, t_LinkedDeque *b)
{
    t_sort sort;
    
    if (r <= 3 || r == 5)
    {
        sort_args_three_five(r, a, b, B);
        return ;
    }
    init_sort(&sort);
    select_pivot(r, b, &sort);
    while (r--)
        b_to_a_sub(&sort, a, b);
    a_to_b(sort.pa - sort.ra, a, b);
    if (sort.ra > sort.rb)
        reverse_rotate_a(sort, a, b);
    else
        reverse_rotate_b(sort, a, b);
    a_to_b(sort.ra, a, b);
    b_to_a(sort.rb, a, b);
}