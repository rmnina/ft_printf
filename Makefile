# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jovicu <jovicu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/29 22:09:37 by jdufour           #+#    #+#              #
#    Updated: 2023/07/03 01:54:29 by jovicu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c\
ft_format.c\

OBJS = ${SRCS:.c=.o}

CC = gcc

RM = rm -rfv

FLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${FLAGS} -c ${SRCS}
	ar cr ${NAME} ${OBJS}

clean: 
	${RM} ${OBJS}
		
fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re