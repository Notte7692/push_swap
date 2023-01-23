# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nassimsalhi <marvin@42.fr>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 10:54:43 by nassimsalhi       #+#    #+#              #
#    Updated: 2023/01/23 11:07:22 by nassimsalhi      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
AR = ar rcs
SRC = input_check_utils.c \
	stack.c \
	cost.c \
	main.c \
	reverse_rotate.c \
	swap.c \
	do_move.c \
	function_for_position.c \
	rotate.c \
	utils.c \
	initialization.c \
	push.c \
	sort.c \
	input_check.c \
	sort_three.c \

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

