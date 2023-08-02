# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/13 10:05:12 by ride-sou          #+#    #+#              #
#    Updated: 2023/05/30 12:36:06 by ride-sou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# Part 1 - LIBFT - Libc functions

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c

SRC += ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c
SRC += ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c
SRC += ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c
SRC += ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c

# Part 2 - LIBFT - Additional functions

SRC += ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c
SRC += ft_itoa.c ft_strmapi.c ft_striteri.c
SRC += ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c
SRC += ft_putnbr_fd.c

# Part 3 - LIBFT - Bonus functions

SRC += ft_lstnew.c ft_lstadd_front.c ft_lstlast.c
SRC += ft_lstsize.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c
SRC += ft_lstiter.c ft_lstmap.c

# Printf functions

SRC += ft_printf.c ft_printf_aux.c ft_print_hex_ptr.c ft_print_unsigned.c

# GNL (BONUS functions)

SRC += get_next_line.c get_next_line_utils.c

OBJS = ${SRC:.c=.o}

RM = rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
				cc ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):        ${OBJS}
				ar rcs ${NAME} ${OBJS}

all:    ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re:     fclean all

.PHONY: all clean fclean re

.SILENT: