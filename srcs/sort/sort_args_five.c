/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_args_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:47:08 by junylee           #+#    #+#             */
/*   Updated: 2022/01/25 15:55:38 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_args_five_a(int five, t_LinkedDeque *a, t_LinkedDeque *b)
{
	int		mid;
	t_sort	sort;

	init_sort(&sort);
	mid = get_args_five_mid_value(a);
	while (five--)
	{
		if (a->pFrontNode->data >= mid)
		{
			ft_ra(a);
			sort.ra++;
		}
		else
		{
			ft_pb(a, b);
			sort.pb++;
		}
		if (sort.pb == 2)
			break ;
	}
	while (sort.ra--)
		ft_rra(a);
}

void	sort_args_five_b(int five, t_LinkedDeque *a, t_LinkedDeque *b)
{
	int		mid;
	t_sort	sort;

	init_sort(&sort);
	mid = get_args_five_mid_value(b);
	while (five--)
	{
		if (b->pFrontNode->data < mid)
		{
			ft_rb(b);
			sort.rb++;
		}
		else
		{
			ft_pa(a, b);
			sort.pa++;
		}
		if (sort.pa == 3)
			break ;
	}
	while (sort.rb--)
		ft_rrb(b);
}

void	sort_args_five(int r, t_LinkedDeque *a, t_LinkedDeque *b, int flag)
{
	if (flag == A)
		sort_args_five_a(r, a, b);
	else
		sort_args_five_b(r, a, b);
	sort_args_three_a(3, a);
	sort_args_two(a, b, B);
}

void	sort_five(t_LinkedDeque *a, t_LinkedDeque *b)
{
	int		mid;
	t_sort	sort;

	init_sort(&sort);
	mid = get_args_five_mid_value(a);
	while (1)
	{
		if (a->pFrontNode->data >= mid)
		{
			ft_ra(a);
			sort.ra++;
		}
		else
		{
			ft_pb(a, b);
			sort.pb++;
		}
		if (sort.pb == 2)
			break ;
	}
	sort_args_three_a(3, a);
	sort_args_two(a, b, B);
}

void	sort_args_three_five(int r, t_LinkedDeque *a, t_LinkedDeque *b,
		int flag)
{
	if (r <= 3)
		sort_args_under_three(r, a, b, flag);
	if (r == 5)
		sort_args_five(r, a, b, flag);
}
