# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/23 17:20:50 by edbernar          #+#    #+#              #
#    Updated: 2023/08/01 23:01:32 by edbernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	main.c\
				file1.c\
				file2.c\
				file3.c\
				file4.c

NAME		=	ft_hexdump


CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

all : ${NAME}

${NAME} :
	${CC} ${CFLAGS} ${SRCS} -o ${NAME}

clean :
	rm -f ${SRCS:.c=.o}

fclean : clean
	rm -f ${NAME}

re	: fclean all

.PHONY : re fclean all clean
