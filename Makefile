# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/29 22:09:37 by jdufour           #+#    #+#              #
#    Updated: 2023/04/30 20:07:02 by jdufour          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c\
ft_puttrucs.c\

OBJS = ${SRCS:.c=.o}

HEADER = libftprintf.h

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
