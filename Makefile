# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/15 14:18:54 by erigolon          #+#    #+#              #
#    Updated: 2023/05/29 20:43:15 by erigolon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	  = push_swap

SRCS 	  = main.c \
			check_string.c \
			list.c

OBJS 	  = ${SRCS:.c=.o}

LIBFT	  = ./libft
LIBPRINTF = ./ft_printf

HEADERS	  = -I ./includes
LIBS 	  = ${LIBFT}/libft.a ${LIBPRINTF}/libftprintf.a

CC		  = gcc
FLAGS	  = -Wall -Wextra -Werror

RM		  = rm -f

all: libs ${NAME}

libs:
	@${MAKE} -C ${LIBFT}
	@${MAKE} -C ${LIBPRINTF}

${NAME}: ${OBJS}
	@${CC} ${FLAGS} ${OBJS} ${HEADERS} ${LIBS} -o ${NAME}

clean:
	@${RM} ${OBJS}
	@${MAKE} -C ${LIBFT} clean
	@${MAKE} -C ${LIBPRINTF} clean

fclean: clean
	@${RM} ${NAME}
	@${MAKE} -C ${LIBFT} fclean
	@${MAKE} -C ${LIBPRINTF} fclean

re: fclean all

.PHONY: all, clean, fclean, re