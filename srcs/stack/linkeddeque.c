#include "linkeddeque.h"

t_LinkedDeque* createLinkedDeque() {
    t_LinkedDeque* pDeque;

    pDeque = (t_LinkedDeque*)malloc(sizeof(t_LinkedDeque));
    if (pDeque == NULL) {
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
        return (FALSE);
    }
    newNode = (t_DequeNode*)malloc(sizeof(t_DequeNode));
    if (newNode == NULL) {
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
        return (FALSE);
    }
    newNode = (t_DequeNode*)malloc(sizeof(t_DequeNode));
    if (newNode == NULL) {
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
        return (NULL);
    }
    if (isLinkedDequeEmpty(pDeque)) {
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
        return (NULL);
    }
    if (isLinkedDequeEmpty(pDeque)) {
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