/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:35:40 by junylee           #+#    #+#             */
/*   Updated: 2022/01/25 15:37:22 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_stack(t_LinkedDeque *stack)
{
	t_DequeNode	*first;
	t_DequeNode	*second;

	if (stack->currentElementCount < 2)
		return (FALSE);
	first = deleteFrontLD(stack);
	second = deleteFrontLD(stack);
	if (insertFrontLD(stack, *first) == FALSE)
	{
		free_stack(stack);
		insert_error();
	}
	if (insertFrontLD(stack, *second) == FALSE)
	{
		free_stack(stack);
		insert_error();
	}
	free(first);
	free(second);
	return (TRUE);
}

void	ft_sa(t_LinkedDeque *a)
{
	if (swap_stack(a) == FALSE)
		return ;
	write(1, "sa\n", 3);
}

void	ft_sb(t_LinkedDeque *b)
{
	if (swap_stack(b) == FALSE)
		return ;
	write(1, "sb\n", 3);
}

void	ft_ss(t_LinkedDeque *a, t_LinkedDeque *b)
{
	if ((swap_stack(a) == FALSE) || (swap_stack(b) == FALSE))
		return ;
	write(1, "ss\n", 3);
}
