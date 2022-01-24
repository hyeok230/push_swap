#include "push_swap.h"

int check_duplicate(t_LinkedDeque *stack)
{
    int i;
    t_DequeNode* curr;
    t_DequeNode* temp;

    i = 0;
    curr = stack->pFrontNode;
    while (i < stack->currentElementCount) {
        temp = curr->pRLink;
        while (temp) {
            if (temp->data == curr->data)
                return (TRUE);
            temp = temp->pRLink;
        }
        curr = curr->pRLink;
        i++;
    }
    return (FALSE);
}

int check_sorted(t_LinkedDeque *stack)
{
    int i;
    t_DequeNode* curr;
    t_DequeNode* temp;
    int min;

    i = 0;
    min = 0;
    curr = stack->pFrontNode;
    while (i < stack->currentElementCount)
    {
        min = curr->data;
        temp = curr->pRLink;
        while (temp)
        {
            if (min > temp->data) 
                return (FALSE);
            temp = temp->pRLink;
        }
        curr = curr->pRLink;
        i++;
    }
    return (TRUE);
}

void check_stack(t_LinkedDeque *stack)
{
    // 1. 중복된 값이 있는지 확인하기
    if (check_duplicate(stack) == TRUE)
    {
        free_stack(stack);
        duplicate_error();
    }
    // 2. 이미 정렬되어 할 것이 없는지 확인하기
    if (check_sorted(stack) == TRUE)
    {
        free_stack(stack);
        exit(0);
    }
}