#include "push_swap.h"

// void push_swap() {

// }

int ft_isdigit(char c) {
    if (c >= '0' && c <= '9')
        return (TRUE);
    return (FALSE);
}

int ft_isspace(char c) {
    if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == ' ')
		return (TRUE);
	else
		return (FALSE);
}

int ft_atoi(const char *str) {
    long ret;
    long sign;
    int i;

    sign = 1;
    i = 0;
    ret = 0;
    while (str[i] && ft_isspace(str[i]))
        i++;
    if (str[i] == '-')
        sign = -1;
    if (str[i] == '-' || str[i] == '+')
        i++;
    if (ft_isdigit(str[i]) == FALSE)
        arg_error();
    while (str[i]) 
    {
        if (ft_isdigit(str[i]) == FALSE)
            arg_error();
        ret = ret * 10 + (str[i] - '0');
        if ((ret > 2147483647 && sign == 1) || (ret > 2147483648 && sign == -1))
            int_error();
        i++;
    }
    return (sign * ret); 
}

int check_duplicate(t_LinkedDeque *stack) {
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

int check_sorted(t_LinkedDeque *stack) {
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

void check_stack(t_LinkedDeque *stack) {
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

void init_a(t_LinkedDeque *a, int argc, char** argv) {
    int i;
    int num;
    t_DequeNode element;

    i = 1;
    while (i < argc)
    {
        num = ft_atoi(argv[i]);
        element.data = num;
        element.pLLink = NULL;
        element.pRLink = NULL;
        if (insertRearLD(a, element) == FALSE) 
        {
            free_stack(a);
            insert_error();
        }
        i++;
    }
    check_stack(a);
}

int main(int argc, char** argv) {
    t_LinkedDeque   *a;
    // t_LinkedDeque   *b;

    if (argc < 2)
        return (1);
    a = createLinkedDeque();
    init_a(a, argc, argv);

    displayDeque(a);
    ft_sa(a);
    displayDeque(a);
    free_stack(a);
    // b = createLinkedDeque();
    // if (a->currentElementCount == 5) 
    //     5일 경우
    // else
    //     push_swap(a, b);
    // free_all(a, b);
}