# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/23 17:20:50 by edbernar          #+#    #+#              #
#    Updated: 2023/07/24 17:33:09 by edbernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	main.c

NAME		=	ft_cat

OBJS		=	${SRCS:.c=.o}

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

all : ${NAME}

${NAME} : ${OBJS} 
	${CC} ${CFLAGS} ${SRCS} -o ${NAME}

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re	: fclean all

.PHONY : re fclean all clean
