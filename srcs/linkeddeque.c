#include "linkeddeque.h"
#include <stdio.h>
#include <stdlib.h>

t_LinkedDeque* createLinkedDeque() {
    t_LinkedDeque* pDeque;

    pDeque = (t_LinkedDeque*)malloc(sizeof(t_LinkedDeque));
    if (pDeque == NULL) {
        printf("malloc ERROR\n");
        return (NULL);
    }
    pDeque->currentElementCount = 0;
    pDeque->pFrontNode = NULL;
    pDeque->pRearNode = NULL;
    return (pDeque);
}

int insertFrontLD(t_LinkedDeque* pDeque, t_DequeNode element) {
    t_DequeNode* newNode;

    if (pDeque == NULL) {
        printf("pDeque Error\n");
        return (FALSE);
    }
    newNode = (t_DequeNode*)malloc(sizeof(t_DequeNode));
    if (newNode == NULL) {
        printf("malloc Error\n");
        return (FALSE);
    }
    *newNode = element;
    newNode->pLLink = NULL;
    newNode->pRLink = NULL;
    if (pDeque->currentElementCount == 0) {
        pDeque->pFrontNode = newNode;
        pDeque->pRearNode = newNode;
    } else {
        pDeque->pFrontNode->pLLink = newNode;
        newNode->pRLink = pDeque->pFrontNode;
        pDeque->pFrontNode = newNode;
    }
    pDeque->currentElementCount++;
    return (TRUE);
}

int insertRearLD(t_LinkedDeque* pDeque, t_DequeNode element) {
    t_DequeNode* newNode;

    if (pDeque == NULL) {
        printf("pDeque Error\n");
        return (FALSE);
    }
    newNode = (t_DequeNode*)malloc(sizeof(t_DequeNode));
    if (newNode == NULL) {
        printf("malloc Error\n");
        return (FALSE);
    }
    *newNode = element;
    newNode->pLLink = NULL;
    newNode->pRLink = NULL;
    if (pDeque->currentElementCount == 0) {
        pDeque->pFrontNode = newNode;
        pDeque->pRearNode = newNode;
    } else {
        pDeque->pRearNode->pRLink = newNode;
        newNode->pLLink = pDeque->pRearNode;
        pDeque->pRearNode = newNode;
    }
    pDeque->currentElementCount++;
    return (TRUE);
}

t_DequeNode* deleteFrontLD(t_LinkedDeque* pDeque) {
    t_DequeNode* retNode;
    
    if (pDeque == NULL) {
        printf("pDeque Error\n");
        return (NULL);
    }
    if (isLinkedDequeEmpty(pDeque)) {
        printf("pDeque empty Error\n");
        return (NULL);
    }
    retNode = pDeque->pFrontNode;
    pDeque->pFrontNode = pDeque->pFrontNode->pRLink;
    retNode->pRLink = NULL;
    if (pDeque->currentElementCount == 1) {
        pDeque->pRearNode = NULL;
    } else {
        pDeque->pFrontNode->pLLink = NULL;
    }
    pDeque->currentElementCount--;
    return (retNode);
}

t_DequeNode* deleteRearLD(t_LinkedDeque* pDeque) {
    t_DequeNode* retNode;

    if (pDeque == NULL) {
        printf("pDeque Error\n");
        return (NULL);
    }
    if (isLinkedDequeEmpty(pDeque)) {
        printf("pDeque empty Error\n");
        return (NULL);
    }
    retNode = pDeque->pRearNode;
    pDeque->pRearNode = pDeque->pRearNode->pLLink;
    retNode->pLLink = NULL;
    if (pDeque->currentElementCount == 1) {
        pDeque->pFrontNode = NULL;
    } else {
        pDeque->pRearNode->pRLink = NULL;
    }
    pDeque->currentElementCount--;
    return (retNode);
}

t_DequeNode* peekFrontLD(t_LinkedDeque* pDeque) {
    if (pDeque == NULL) {
        printf("pDeque Error\n");
        return (NULL);
    }
    if (isLinkedDequeEmpty(pDeque)) {
        printf("pDeque empty Error\n");
        return (NULL);
    }
    return (pDeque->pFrontNode);
}

t_DequeNode* peekRearLD(t_LinkedDeque* pDeque) {
    if (pDeque == NULL) {
        printf("pDeque Error\n");
        return (NULL);
    }
    if (isLinkedDequeEmpty(pDeque)) {
        printf("pDeque empty Error\n");
        return (NULL);
    }
    return (pDeque->pRearNode);
}

void deleteLinkedDeque(t_LinkedDeque* pDeque) {
    t_DequeNode* delNode;
    
    if (pDeque == NULL) {
        printf("pDeque Error\n");
        return ;
    }
    while (pDeque->currentElementCount != 0) {
        delNode = deleteFrontLD(pDeque);
        free(delNode);
    }
}

int isLinkedDequeFull(t_LinkedDeque* pDeque) {
    if (pDeque == NULL) {
        printf("pDeque Error\n");
        return (FALSE);
    }
    return (TRUE);
}

int isLinkedDequeEmpty(t_LinkedDeque* pDeque) {
    if (pDeque == NULL) {
        printf("pDeque Error\n");
        return (FALSE);
    }
    if (pDeque->currentElementCount == 0) {
        return (TRUE);
    }
    return (FALSE);
}

void displayDeque(t_LinkedDeque* pDeque) {
    t_DequeNode* printNode;

    if (pDeque == NULL) {
        printf("pDeque Error\n");
        return ;
    }
    printNode = pDeque->pFrontNode;
    for (int i =0; i < pDeque->currentElementCount; i++) {
        printf("data => [%d]\n", printNode->data);
        printNode = printNode->pRLink;
    }
}