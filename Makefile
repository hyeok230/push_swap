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

FOLDER	= ./srcs/

SRCS	= main.c\
			linkeddeque.c\
			print_error.c\
			free_stack.c\
			ft_swap.c\
			ft_push.c\
			

SOURCES =  $(addprefix $(FOLDER), $(SRCS))

OBJECTS = $(SOURCES:%.c=%.o)
OBJECTS_BONUS = $(SOURCES_BONUS:%.c=%.o)

# =============================================================================
# Target Generating
# =============================================================================

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)
	rm -f $(OBJECTS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJECTS_BONUS)
	$(CC) $(CFLAGS) $(OPTIONS) -o $(NAME) $(OBJECTS_BONUS)

.PHONY: all clean fclean re bonus
