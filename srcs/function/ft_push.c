/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:28:20 by junylee           #+#    #+#             */
/*   Updated: 2022/01/25 15:30:05 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_stack(t_LinkedDeque *fromStack, t_LinkedDeque *toStack)
{
	t_DequeNode	*element;

	element = deleteFrontLD(fromStack);
	if (element == NULL)
		return (FALSE);
	if (insertFrontLD(toStack, *element) == FALSE)
	{
		free_all(fromStack, toStack);
		insert_error();
	}
	free(element);
	return (TRUE);
}

void	ft_pa(t_LinkedDeque *a, t_LinkedDeque *b)
{
	if (push_stack(b, a) == FALSE)
		return ;
	write(1, "pa\n", 3);
}

void	ft_pb(t_LinkedDeque *a, t_LinkedDeque *b)
{
	if (push_stack(a, b) == FALSE)
		return ;
	write(1, "pb\n", 3);
}
