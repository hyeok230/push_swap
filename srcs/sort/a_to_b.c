#include "push_swap.h"

void init_sort(t_sort *sort)
{
    sort->ra = 0;
    sort->rb = 0;
    sort->pa = 0;
    sort->pb = 0;
}

void select_pivot(int r, t_LinkedDeque *stack, t_sort *sort)
{
    int min;
    int max;

    min = get_min_value(stack, r);
    max = get_max_value(stack, r);
    sort->pivot_big = (min + max) / 2;
    sort->pivot_small = (min + sort->pivot_big) / 2; 
}

void reverse_rotate_a(t_sort sort, t_LinkedDeque *a, t_LinkedDeque *b, int *start)
{
    int rrr;
    int rra;

    rrr = sort.rb;
    rra = sort.ra - sort.rb;
    if (*start == 0)
    {
        while (rrr--)
            ft_rrb(b);
    }
    else
    {
        while (rrr--)
            ft_rrr(a, b);
        while (rra--)
            ft_rra(a);
    }
}

void reverse_rotate_b(t_sort sort, t_LinkedDeque *a, t_LinkedDeque *b, int *start)
{
    int rrr;
    int rrb;

    rrr = sort.ra;
    rrb = sort.rb - sort.ra;
    if (*start == 0)
    {
        while (sort.rb--)
            ft_rrb(b);
    }
    else
    {
        while (rrr--)
            ft_rrr(a, b);
        while (rrb--)
            ft_rrb(b);
    }
}

void a_to_b_sub(t_sort *sort, t_LinkedDeque *a, t_LinkedDeque *b)
{
    if (a->pFrontNode->data > sort->pivot_big)
        {
            ft_ra(a);
            sort->ra++;
        }
    else
    {
        ft_pb(a, b);
        sort->pb++;
        if (b->pFrontNode->data > sort->pivot_small)
        {
            ft_rb(b);
            sort->rb++;
        }
    }
}

void a_to_b(int r, t_LinkedDeque *a, t_LinkedDeque *b, int *start)
{
    t_sort sort;
    
    if (r <= 3 || r == 5)
    {
        sort_args_three_five(r, a, b, A);
        return ;
    }
    init_sort(&sort);
    select_pivot(r, a, &sort);
    while (r--)
        a_to_b_sub(&sort, a, b);
    if (sort.ra > sort.rb)
        reverse_rotate_a(sort, a, b, start);
    else
        reverse_rotate_b(sort, a, b, start);
    a_to_b(sort.ra, a, b, start);
    b_to_a(sort.rb, a, b, start);
    b_to_a(sort.pb - sort.rb, a, b, start);
}