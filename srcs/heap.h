#ifndef _HEAP_
#define _HEAP_

typedef struct s_HeapNodeType
{
	int data;
} t_HeapNode;

typedef struct s_HeapType
{
	int maxElementCount;		
	int currentElementCount;
    t_HeapNode* pElement;
} t_Heap;

t_Heap* createHeap(int maxElementCount);
void deleteHeap(t_Heap* pHeap);
int isHeapFull(t_Heap* pHeap);
int isHeapEmpty(t_Heap* pHeap);
int insertMaxHeap(t_Heap* pHeap, t_HeapNode element);
int insertMinHeap(t_Heap* pHeap, t_HeapNode element);
t_HeapNode* deleteMaxHeapNode(t_Heap* pHeap);
t_HeapNode* deleteMinHeapNode(t_Heap* pHeap);
void displayHeap(t_Heap* pHeap);

#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE		1
#define FALSE		0

#endif