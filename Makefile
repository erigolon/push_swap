# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/15 14:18:54 by erigolon          #+#    #+#              #
#    Updated: 2023/05/31 17:32:49 by erigolon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	  = push_swap

SRCS 	  = main.c \
			check_string.c \
			list.c \
			list_order.c \
			swap.c \
			assign_data.c \
			sort_three.c

OBJS 	  = ${SRCS:.c=.o}

LIBFT	  = ./libft

HEADERS	  = -I ./includes
LIBS 	  = ${LIBFT}/libft.a

CC		  = gcc
FLAGS	  = -Wall -Wextra -Werror

RM		  = rm -f

all: libs ${NAME}

libs:
	@${MAKE} -C ${LIBFT}

${NAME}: ${OBJS}
	@${CC} ${FLAGS} ${OBJS} ${HEADERS} ${LIBS} -o ${NAME}

clean:
	@${RM} ${OBJS}
	@${MAKE} -C ${LIBFT} clean

fclean: clean
	@${RM} ${NAME}
	@${MAKE} -C ${LIBFT} fclean

re: fclean all

.PHONY: all, clean, fclean, re