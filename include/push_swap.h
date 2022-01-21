#ifndef PUSH_SWAP
#define PUSH_SWAP

/*
** =============================================================================
** Dependencies
** =============================================================================
*/

# include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "linkeddeque.h"

/*
** =============================================================================
** Struct Type Definitions
** =============================================================================
*/

#define A 1
#define B 2
#define ALL 3

typedef struct s_sort
{
    int pivot_big;
    int pivot_small;
	int ra;
    int rb;
    int pa;
    int pb;
} t_sort;

/*
** =============================================================================
** print_error.c
** =============================================================================
*/

void malloc_error();
void insert_error();
void arg_error();
void int_error();
void duplicate_error();

/*
** =============================================================================
** free_stack.c
** =============================================================================
*/

void free_stack(t_LinkedDeque *stack);
void free_all(t_LinkedDeque *a, t_LinkedDeque *b);

/*
** =============================================================================
** get_max_mid_min.c
** =============================================================================
*/

int get_args_five_mid_value(t_LinkedDeque *stack);
int get_max_value(t_LinkedDeque *stack, int size);
int get_mid_value(int list[], int size);
int get_min_value(t_LinkedDeque *stack, int size);

/*
** =============================================================================
** ft_swap.c
** =============================================================================
*/

int swap_stack(t_LinkedDeque *stack);
void ft_sa(t_LinkedDeque *a);
void ft_sb(t_LinkedDeque *b);
void ft_ss(t_LinkedDeque *a, t_LinkedDeque *b);

/*
** =============================================================================
** ft_push.c
** =============================================================================
*/

int push_stack(t_LinkedDeque *fromStack, t_LinkedDeque *toStack);
void ft_pa(t_LinkedDeque *a, t_LinkedDeque *b);
void ft_pb(t_LinkedDeque *a, t_LinkedDeque *b);

/*
** =============================================================================
** ft_rotate.c
** =============================================================================
*/

int rotate_stack(t_LinkedDeque *stack);
void ft_ra(t_LinkedDeque *a);
void ft_rb(t_LinkedDeque *b);

/*
** =============================================================================
** ft_reverse_rotate.c
** =============================================================================
*/

int reverse_rotate_stack(t_LinkedDeque *stack);
void ft_rra(t_LinkedDeque *a);
void ft_rrb(t_LinkedDeque *b);

/*
** =============================================================================
** a_to_b.c
** =============================================================================
*/

void init_sort(t_sort *sort);
void a_to_b(int r, t_LinkedDeque *a, t_LinkedDeque *b);

/*
** =============================================================================
** sort_args_three_a.c
** =============================================================================
*/

void a_three_min_top(t_LinkedDeque *a, int max);
void a_three_min_mid(t_LinkedDeque *a, int max);
void a_three_min_bottom(t_LinkedDeque *a, int max);
void sort_args_three_a(int r, t_LinkedDeque *a);

/*
** =============================================================================
** sort_args_three_b.c
** =============================================================================
*/

void sort_args_three_b(int r, t_LinkedDeque *a, t_LinkedDeque *b);

/*
** =============================================================================
** sort_args_under_three.c
** =============================================================================
*/

void sort_args_two(t_LinkedDeque *a, t_LinkedDeque *b, int flag);
void sort_args_under_three(int r, t_LinkedDeque *a, t_LinkedDeque *b, int flag);

#endif