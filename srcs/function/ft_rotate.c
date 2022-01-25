/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:32:09 by junylee           #+#    #+#             */
/*   Updated: 2022/01/25 15:35:35 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_stack(t_LinkedDeque *stack)
{
	t_DequeNode	*element;
	int			length;

	length = stack->currentElementCount;
	if (length < 2)
		return (FALSE);
	element = deleteFrontLD(stack);
	if (element == NULL)
		return (FALSE);
	if (insertRearLD(stack, *element) == FALSE)
	{
		free_stack(stack);
		insert_error();
	}
	free(element);
	return (TRUE);
}

void	ft_ra(t_LinkedDeque *a)
{
	if (rotate_stack(a) == FALSE)
		return ;
	write(1, "ra\n", 3);
}

void	ft_rb(t_LinkedDeque *b)
{
	if (rotate_stack(b) == FALSE)
		return ;
	write(1, "rb\n", 3);
}

void	ft_rr(t_LinkedDeque *a, t_LinkedDeque *b)
{
	if (rotate_stack(a) == FALSE)
		return ;
	if (rotate_stack(b) == FALSE)
		return ;
	write(1, "rr\n", 3);
}
