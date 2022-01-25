/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:25:14 by junylee           #+#    #+#             */
/*   Updated: 2022/01/25 16:27:02 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	malloc_error(void)
{
	write(2, "ERROR\n", 6);
	exit(1);
}

void	insert_error(void)
{
	write(2, "ERROR\n", 6);
	exit(1);
}

void	arg_error(void)
{
	write(2, "ERROR\n", 6);
	exit(1);
}

void	int_error(void)
{
	write(2, "ERROR\n", 6);
	exit(1);
}

void	duplicate_error(void)
{
	write(2, "ERROR\n", 6);
	exit(1);
}
