/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkeddeque.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:28:28 by junylee           #+#    #+#             */
/*   Updated: 2022/01/25 16:32:43 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKEDDEQUE_H

# define LINKEDDEQUE_H
# include <stdlib.h>

/*
** =============================================================================
** Struct Type Definitions
** =============================================================================
*/

# define TRUE		1
# define FALSE		0

typedef struct s_DequeNodeType
{
	int						data;
	struct s_DequeNodeType	*pRLink;
	struct s_DequeNodeType	*pLLink;
}	t_DequeNode;

typedef struct s_LinkedDequeType
{
	int			currentElementCount;
	t_DequeNode	*pFrontNode;
	t_DequeNode	*pRearNode;
}	t_LinkedDeque;

/*
** =============================================================================
** linkeddeque.c
** =============================================================================
*/

t_LinkedDeque	*createLinkedDeque(void);
int				insertFrontLD(t_LinkedDeque *pDeque, t_DequeNode element);
int				insertRearLD(t_LinkedDeque *pDeque, t_DequeNode element);
t_DequeNode		*deleteFrontLD(t_LinkedDeque *pDeque);
t_DequeNode		*deleteRearLD(t_LinkedDeque *pDeque);
void			deleteLinkedDeque(t_LinkedDeque *pDeque);
int				isLinkedDequeFull(t_LinkedDeque *pDeque);
int				isLinkedDequeEmpty(t_LinkedDeque *pDeque);
void			displayDeque(t_LinkedDeque *pDeque);

#endif
