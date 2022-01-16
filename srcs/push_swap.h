#ifndef PUSH_SWAP
#define PUSH_SWAP

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_DoublyListNode
{
	int data;
	struct s_DoublyListNode* pLLink;
	struct s_DoublyListNode* pRLink;
} t_DoublyListNode;

typedef struct s_DoublyList
{
	int	currentElementCount;
	t_DoublyListNode	headerNode;
} t_DoublyList;



#endif