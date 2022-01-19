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

#endif