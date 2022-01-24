#ifndef _LINKED_DEQUE_
#define _LINKED_DEQUE_

#include <stdlib.h>
/*
** =============================================================================
** Struct Type Definitions
** =============================================================================
*/

typedef struct s_DequeNodeType
{
	int data;
	struct s_DequeNodeType* pRLink;
	struct s_DequeNodeType* pLLink;
} t_DequeNode;

typedef struct s_LinkedDequeType
{
	int currentElementCount;
	t_DequeNode* pFrontNode;
	t_DequeNode* pRearNode;
} t_LinkedDeque;

/*
** =============================================================================
** linkeddeque.c
** =============================================================================
*/

t_LinkedDeque* createLinkedDeque();
int insertFrontLD(t_LinkedDeque* pDeque, t_DequeNode element);
int insertRearLD(t_LinkedDeque* pDeque, t_DequeNode element);
t_DequeNode* deleteFrontLD(t_LinkedDeque* pDeque);
t_DequeNode* deleteRearLD(t_LinkedDeque* pDeque);
void deleteLinkedDeque(t_LinkedDeque* pDeque);
int isLinkedDequeFull(t_LinkedDeque* pDeque);
int isLinkedDequeEmpty(t_LinkedDeque* pDeque);
void displayDeque(t_LinkedDeque* pDeque);

#endif

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE		1
#define FALSE		0

#endif