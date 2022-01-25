/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_args_under_three.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:02:26 by junylee           #+#    #+#             */
/*   Updated: 2022/01/25 16:03:10 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_args_two(t_LinkedDeque *a, t_LinkedDeque *b, int flag)
{
	if (flag == A)
	{
		if (a->pFrontNode->data > a->pFrontNode->pRLink->data)
			ft_sa(a);
	}
	else
	{
		if (b->pFrontNode->data < b->pFrontNode->pRLink->data)
			ft_sb(b);
		ft_pa(a, b);
		ft_pa(a, b);
	}
}

void	sort_args_under_three(int r, t_LinkedDeque *a, t_LinkedDeque *b,
		int flag)
{
	if (r == 3)
	{
		if (flag == A)
			sort_args_three_a(r, a);
		else
			sort_args_three_b(r, a, b);
	}
	else if (r == 2)
		sort_args_two(a, b, flag);
	else if (r == 1)
	{
		if (flag == B)
			ft_pa(a, b);
	}
}
