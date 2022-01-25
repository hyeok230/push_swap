/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkeddeque2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:04:31 by junylee           #+#    #+#             */
/*   Updated: 2022/01/25 17:23:07 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkeddeque.h"

void	deleteLinkedDeque(t_LinkedDeque *pDeque)
{
	t_DequeNode	*delNode;

	if (pDeque == NULL)
		return ;
	while (pDeque->currentElementCount != 0)
	{
		delNode = deleteFrontLD(pDeque);
		free(delNode);
	}
}

int	isLinkedDequeFull(t_LinkedDeque	*pDeque)
{
	if (pDeque == NULL)
		return (FALSE);
	return (TRUE);
}

int	isLinkedDequeEmpty(t_LinkedDeque	*pDeque)
{
	if (pDeque == NULL)
		return (FALSE);
	if (pDeque->currentElementCount == 0)
		return (TRUE);
	return (FALSE);
}
