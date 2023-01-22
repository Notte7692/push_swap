# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsalhi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 13:46:21 by nsalhi            #+#    #+#              #
#    Updated: 2023/01/18 15:33:24 by nsalhi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
AR = ar rcs
SRC = get_inputs-utils.c \
		swap.c \
		cost.c \
		initialization.c \
		reverse_rotate.c \
		utils.c \
		do_move.c \
		main.c \
		rotate.c \
		utils_stack.c \
		function_for_position.c \
		sort.c \
		get_inputs.c \
		push.c \
		sort_short.c \

CFLAGS += -Werror -Wextra -Wall -g

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o  $(NAME)

all :	$(NAME)

clean :
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean 	all

.PHONY: all clean fclean re bonus
