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
** ft_swap.c
** =============================================================================
*/

int swap_stack(t_LinkedDeque *stack);
void ft_sa(t_LinkedDeque *a);
void ft_sb(t_LinkedDeque *b);
void ft_ss(t_LinkedDeque *a, t_LinkedDeque *b);

/*
** =============================================================================
** free_stack.c
** =============================================================================
*/

void free_stack(t_LinkedDeque *stack);
void free_all(t_LinkedDeque *a, t_LinkedDeque *b);

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
#endif