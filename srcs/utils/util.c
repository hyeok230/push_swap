/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:44:22 by junylee           #+#    #+#             */
/*   Updated: 2022/01/25 17:31:44 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_stack_a(t_LinkedDeque *a, char *argv)
{
	int			i;
	int			num;
	t_DequeNode	element;
	char		**args;

	i = 0;
	args = ft_split(argv, ' ');
	while (args[i])
	{
		num = ft_atoi(args[i]);
		element.data = num;
		element.pLLink = NULL;
		element.pRLink = NULL;
		if (insertRearLD(a, element) == FALSE)
		{
			free_stack(a);
			insert_error();
		}
		i++;
	}
}

void	init_a(t_LinkedDeque *a, int argc, char	**argv)
{
	int			i;

	i = 1;
	while (i < argc)
	{
		set_stack_a(a, argv[i]);
		i++;
	}
	check_stack(a);
}

void	init_sort(t_sort *sort)
{
	sort->ra = 0;
	sort->rb = 0;
	sort->pa = 0;
	sort->pb = 0;
}
