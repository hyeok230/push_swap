#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

t_Heap* createHeap(int maxElementCount) {
    t_Heap* pHeap;

    if (maxElementCount <= 0) {
        printf("maxElementCount ERROR\n");
        return (NULL);
    }
    pHeap = (t_Heap*)malloc(sizeof(t_Heap));
    pHeap->maxElementCount = maxElementCount;
    pHeap->currentElementCount = 0; 
    pHeap->pElement = (t_HeapNode*)malloc(sizeof(t_HeapNode) * (maxElementCount + 1));
    memset(pHeap->pElement, 0, sizeof(t_HeapNode) * (pHeap->maxElementCount + 1));
    return (pHeap);
}

int insertMaxHeap(t_Heap* pHeap, t_HeapNode element) {
    int i;
    t_HeapNode* newNode;
    
    if (pHeap == NULL) {
        printf("pHeap ERROR\n");
        return (FALSE);
    }
    if (isHeapFull(pHeap)) {
        printf("pHeap full ERROR\n");
        return (FALSE);
    }
    pHeap->currentElementCount++;
    i = pHeap->currentElementCount;
    while(i > 1 && element.data > pHeap->pElement[i / 2].data) {
        pHeap->pElement[i] = pHeap->pElement[i/2];
        i = i / 2;
    }
    pHeap->pElement[i] = element;
    return (TRUE);
}

int insertMinHeap(t_Heap* pHeap, t_HeapNode element) {
    int i;
    t_HeapNode* newNode;
    
    if (pHeap == NULL) {
        printf("pHeap ERROR\n");
        return (FALSE);
    }
    if (isHeapFull(pHeap)) {
        printf("pHeap full ERROR\n");
        return (FALSE);
    }
    pHeap->currentElementCount++;
    i = pHeap->currentElementCount;
    while(i > 1 && element.data < pHeap->pElement[i/2].data) {
        pHeap->pElement[i] = pHeap->pElement[i/2];
        i = i / 2;
    }
    pHeap->pElement[i] = element;
    return (TRUE);
}

int isHeapFull(t_Heap* pHeap) {
    if (pHeap == NULL) {
        printf("pHeap ERROR\n");
        return (FALSE);
    }
    if (pHeap->currentElementCount == pHeap->maxElementCount) {
        return (TRUE);
    }
    return (FALSE);
}

int isHeapEmpty(t_Heap* pHeap) {
    if (pHeap == NULL) {
        printf("pHeap ERROR\n");
        return (FALSE);
    }
    if (pHeap->currentElementCount == 0) {
        return (TRUE);
    }
    return (FALSE);
}

t_HeapNode* deleteMaxHeapNode(t_Heap* pHeap) {
    int i;
    int parent;
    int child;
    t_HeapNode* retNode;
    t_HeapNode* temp;
    
    if (pHeap == NULL) {
        printf("pHeap ERROR\n");
        return (NULL);
    }
    if (isHeapEmpty(pHeap)) {
        printf("pHeap empty ERROR\n");
        return (NULL);
    }
    retNode = (t_HeapNode*)malloc(sizeof(t_HeapNode));
    if (retNode == NULL) {
        printf("retNode ERROR\n");
        return (NULL);
    }
    *retNode = pHeap->pElement[1];
    i = pHeap->currentElementCount;
    temp = &(pHeap->pElement[i]);
    pHeap->currentElementCount--;
    parent = 1;
    child = 2;
    while (child <= pHeap->currentElementCount) {
        if (child < pHeap->currentElementCount && pHeap->pElement[child].data < pHeap->pElement[child + 1].data) {
            child++;
        }
        if (temp->data >= pHeap->pElement[child].data) {
            break ;
        }
        pHeap->pElement[parent] = pHeap->pElement[child]; 
        parent = child;
        child = child * 2;
    }
    pHeap->pElement[parent] = *temp;
    return (retNode);
}

t_HeapNode* deleteMinHeapNode(t_Heap* pHeap) {
    int i;
    int parent;
    int child;
    t_HeapNode* retNode;
    t_HeapNode* temp;
    
    if (pHeap == NULL) {
        printf("pHeap ERROR\n");
        return (NULL);
    }
    if (isHeapEmpty(pHeap)) {
        printf("pHeap empty ERROR\n");
        return (NULL);
    }
    retNode = (t_HeapNode*)malloc(sizeof(t_HeapNode));
    if (retNode == NULL) {
        printf("retNode ERROR\n");
        return (NULL);
    }
    *retNode = pHeap->pElement[1];
    i = pHeap->currentElementCount;
    temp = &(pHeap->pElement[i]);
    pHeap->currentElementCount--;
    parent = 1;
    child = 2;
    while (child <= pHeap->currentElementCount) {
        if (child < pHeap->currentElementCount && pHeap->pElement[child].data > pHeap->pElement[child + 1].data) {
            child++;
        }
        if (temp->data <= pHeap->pElement[child].data) {
            break ;
        }
        pHeap->pElement[parent] = pHeap->pElement[child]; 
        parent = child;
        child = child * 2;
    }
    pHeap->pElement[parent] = *temp;
    return (retNode);
}

void deleteHeap(t_Heap* pHeap) {
    if (pHeap == NULL) {
        printf("pHeap ERROR\n");
        return ;
    }
    if (pHeap->pElement == NULL) {
        printf("pHeap pElement ERROR\n");
        return ;
    }
    free(pHeap->pElement);
    free(pHeap);
    return ;
}

void displayHeap(t_Heap* pHeap) {
    if (pHeap == NULL) {
        printf("pHeap ERROR\n");
        return ;
    }
    if (pHeap->pElement == NULL) {
        printf("pHeap pElement ERROR\n");
        return ;
    }
    for (int i = 1; i <= pHeap->currentElementCount; i++) {
        printf("[%d] => data [%d]\n", i, pHeap->pElement[i].data);
    }
}