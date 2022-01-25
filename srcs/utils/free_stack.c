/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:24:53 by junylee           #+#    #+#             */
/*   Updated: 2022/01/25 16:25:11 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_LinkedDeque *stack)
{
	deleteLinkedDeque(stack);
	free(stack);
}

void	free_all(t_LinkedDeque *a, t_LinkedDeque *b)
{
	free_stack(a);
	free_stack(b);
}
