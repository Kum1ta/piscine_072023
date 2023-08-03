# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edbernar <edbernar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/23 13:03:11 by edbernar          #+#    #+#              #
#    Updated: 2023/07/23 23:42:13 by edbernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	./srcs/ft_putchar.c\
				./srcs/ft_putstr.c\
				./srcs/ft_strcmp.c\
				./srcs/ft_strlen.c\
				./srcs/ft_swap.c

HEAD		=  ./includes/ft.h

NAME		= libft.a

OBJS		= ${SRCS:.c=.o}

.c.o :
	gcc -Wall -Werror -Wextra -I ./includes/ -c $< -o ${<:.c=.o}

all : ${NAME}

${NAME} : ${OBJS} 
	ar rc ${NAME} ${OBJS} ${HEAD}

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re	: fclean all

.PHONY : re fclean all clean
