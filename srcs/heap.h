#ifndef _HEAP_
#define _HEAP_

/*
** =============================================================================
** Struct Type Definitions
** =============================================================================
*/

typedef struct HeapNodeType
{
	int data;
} HeapNode;

typedef struct HeapType
{
	int maxElementCount;		
	int currentElementCount;
    HeapNode* pElement;
} Heap;

/*
** =============================================================================
** linkeddeque.c
** =============================================================================
*/

Heap* createHeap(int maxElementCount);
void deleteHeap(Heap* pHeap);
int isHeapFull(Heap* pHeap);
int isHeapEmpty(Heap* pHeap);
int insertMaxHeap(Heap* pHeap, HeapNode element);
int insertMinHeap(Heap* pHeap, HeapNode element);
HeapNode* deleteMaxHeapNode(Heap* pHeap);
HeapNode* deleteMinHeapNode(Heap* pHeap);
void displayHeap(Heap* pHeap);

#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE		1
#define FALSE		0

#endif