# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junylee <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 17:04:14 by junylee           #+#    #+#              #
#    Updated: 2021/10/21 17:35:56 by junylee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============================================================================
# Command Variables
# =============================================================================

CC 			= gcc
CFLAGS		= -Wall -Wextra -Werror
NAME		= push_swap
# =============================================================================
# File Variables
# =============================================================================

INCLUDE = -Iinclude/
FOLDER	= ./srcs/
D_SORT = ./sort/
D_FUNCTION = ./function/
D_UTILS = ./utils/

SRCS	= main.c\
			linkeddeque.c\
			$(D_UTILS)check_stack.c\
			$(D_UTILS)util.c\
			$(D_UTILS)print_error.c\
			$(D_UTILS)free_stack.c\
			$(D_UTILS)get_max_mid_min.c\
			$(D_FUNCTION)ft_swap.c\
			$(D_FUNCTION)ft_push.c\
			$(D_FUNCTION)ft_rotate.c\
			$(D_FUNCTION)ft_reverse_rotate.c\
			$(D_SORT)a_to_b.c\
			$(D_SORT)b_to_a.c\
			$(D_SORT)sort_args_three_a.c\
			$(D_SORT)sort_args_three_b.c\
			$(D_SORT)sort_args_under_three.c\
			$(D_SORT)sort_args_five.c\

			

SOURCES =  $(addprefix $(FOLDER), $(SRCS))

OBJECTS = $(SOURCES:%.c=%.o)

# =============================================================================
# Target Generating
# =============================================================================

all: $(NAME)

%.o: %.c
	${CC} ${CFLAGS} $(INCLUDE) -c $< -o $@

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)
	rm -f $(OBJECTS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
