#include "push_swap.h"

void a_three_min_top(t_LinkedDeque *a, int max)
{
    if (a->currentElementCount == 3)
    {
        if (a->pFrontNode->pRLink->data == max)
        {
            ft_rra(a);
            ft_sa(a);
        }
    }
    else
    {
        if (a->pFrontNode->pRLink->data == max)
        {
            ft_ra(a);
            ft_sa(a);
            ft_rra(a);
        }
    }
}

void a_three_min_mid(t_LinkedDeque *a, int max)
{
    if (a->pFrontNode->data == max)
    {
        if (a->currentElementCount == 3)
        {
            ft_ra(a);
        }
        else
        {
            ft_sa(a);
            ft_ra(a);
            ft_sa(a);
            ft_rra(a);
        }
    }
    else 
        ft_sa(a);
}

void a_three_min_bottom(t_LinkedDeque *a, int max)
{
    if (a->currentElementCount == 3)
    {
        if (a->pFrontNode->data == max)
            ft_sa(a);
        ft_rra(a);
    }
    else
    {
        if (a->pFrontNode->data == max)
            ft_sa(a);
        ft_ra(a);
        ft_sa(a);
        ft_rra(a);
        ft_sa(a);
    }
}

void sort_args_three_a(int r, t_LinkedDeque *a)
{
    int max;
    int min;

    max = get_max_value(a, r);
    min = get_min_value(a, r);
    if (a->pFrontNode->data == min)
        a_three_min_top(a, max);
    else if (a->pFrontNode->pRLink->data == min)
        a_three_min_mid(a, max);
    else if (a->pFrontNode->pRLink->pRLink->data == min)
        a_three_min_bottom(a, max);
}

