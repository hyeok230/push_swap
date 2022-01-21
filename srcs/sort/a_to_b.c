#include "push_swap.h"

void init_sort(t_sort *sort)
{
    sort->ra = 0;
    sort->rb = 0;
    sort->pa = 0;
    sort->pb = 0;
}

void a_to_b(int r, t_LinkedDeque *a, t_LinkedDeque *b)
{
    t_sort sort;
    
    (void)b;
    if (r <= 3)
        sort_args_under_three(r, a, b, A);
    init_sort(&sort);
}