#include "push_swap.h"

void b_three_min_top(t_LinkedDeque *b, int max)
{
    if (b->currentElementCount == 3)
    {
        ft_rb(b);
        if (b->pFrontNode->pRLink->data == max)
            ft_sb(b);
    }
    else
    {
        ft_sb(b);
        ft_rb(b);
        ft_sb(b);
        ft_rrb(b);
        if (b->pFrontNode->pRLink->data == max)
            ft_sb(b);
    }
}

void b_three_min_mid(t_LinkedDeque *b, int max)
{
    if (b->currentElementCount == 3)
    {
        ft_rrb(b);
        if (b->pFrontNode->pRLink->data == max)
            ft_sb(b);
    }
    else
    {
        ft_rb(b);
        ft_sb(b);
        ft_rrb(b);
        if (b->pFrontNode->pRLink->data == max)
            ft_sb(b);
    }
}

void b_three_min_bottom(t_LinkedDeque *b, int max)
{
    if (b->pFrontNode->pRLink->data == max)
        ft_sb(b);
}

void sort_args_three_b(int r, t_LinkedDeque *a, t_LinkedDeque *b)
{
    int max;
    int min;

    max = get_max_value(b, r);
    min = get_min_value(b, r);
    if (b->pFrontNode->data == min)
        b_three_min_top(b, max);
    else if (b->pFrontNode->pRLink->data == min)
        b_three_min_mid(b, max);
    else if (b->pFrontNode->pRLink->pRLink->data == min)
        b_three_min_bottom(b, max);
    ft_pa(a, b);
    ft_pa(a, b);
    ft_pa(a, b);
}