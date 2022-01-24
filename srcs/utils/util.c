#include "push_swap.h"

int ft_isdigit(char c)
{
    if (c >= '0' && c <= '9')
        return (TRUE);
    return (FALSE);
}

int ft_isspace(char c)
{
    if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == ' ')
		return (TRUE);
	else
		return (FALSE);
}

int ft_atoi(const char *str)
{
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

void init_a(t_LinkedDeque *a, int argc, char** argv)
{
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