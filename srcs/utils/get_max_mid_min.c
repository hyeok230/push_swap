/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max_mid_min.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:17:45 by junylee           #+#    #+#             */
/*   Updated: 2022/01/25 16:19:45 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_value(t_LinkedDeque *stack, int size)
{
	int			max;
	t_DequeNode	*node;

	if (stack == NULL || stack->currentElementCount < size)
		return (0);
	node = stack->pFrontNode;
	max = node->data;
	while (size--)
	{
		if (max < node->data)
			max = node->data;
		node = node->pRLink;
	}
	return (max);
}

int	get_min_value(t_LinkedDeque *stack, int size)
{
	int			min;
	t_DequeNode	*node;

	if (stack == NULL || stack->currentElementCount < size)
		return (0);
	node = stack->pFrontNode;
	min = node->data;
	while (size--)
	{
		if (min > node->data)
			min = node->data;
		node = node->pRLink;
	}
	return (min);
}

int	get_mid_value(int list[], int size)
{
	int	i;
	int	temp;

	while (size--)
	{
		i = 0;
		while (i < size)
		{
			if (list[i] > list[i + 1])
			{
				temp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = temp;
			}
			i++;
		}
	}
	return (list[2]);
}

int	get_args_five_mid_value(t_LinkedDeque *stack)
{
	int			i;
	int			size;
	int			list[5];
	t_DequeNode	*node;

	if (stack == NULL)
		return (0);
	i = 0;
	size = 5;
	node = stack->pFrontNode;
	while (size--)
	{
		list[i] = node->data;
		node = node->pRLink;
		i++;
	}
	return (get_mid_value(list, 5));
}
