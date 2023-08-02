# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 15:06:43 by ride-sou          #+#    #+#              #
#    Updated: 2023/08/02 11:51:49 by ride-sou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = src/push_swap.c src/ps_checks.c src/ps_lists.c src/ps_sort.c \
	src/ps_moves_0.c src/ps_moves_1.c src/ps_sort_aux.c src/ps_sort_big_0.c \
	src/ps_sort_big_1.c src/ps_sort_big_2.c src/ps_others.c \

OBJS = ${SRC:.c=.o}

RM = rm -f
CFLAGS = -Wall -Wextra -Werror
MAKE = make -C
LIBFT = -L libft -lft

all:	${NAME}

$(NAME): ${OBJS}
		${MAKE} libft
		cc ${CFLAGS} ${OBJS} ${LIBFT} -o ${NAME}

clean:
		${MAKE} libft clean
		${RM} ${OBJS}

fclean: clean
		${MAKE} libft fclean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

.SILENT: