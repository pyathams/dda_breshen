# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/23 03:09:28 by pyathams          #+#    #+#              #
#    Updated: 2024/03/23 03:57:47 by pyathams         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRC		=	ft_hexadecimal_util.c \
			ft_printf_util.c \
			ft_printf.c \
			ft_putnbr_util.c \
			ft_putptr_util.c  \
			ft_uputnbr_util.c \
			print_char.c \
					
OBJ		=	$(SRC:.c=.o)

CC		= 	cc
FLAGS	=	-Wall -Werror -Wextra

%o:%c
	$(CC) $(FLAGS) -g -c $< -o $@

${NAME}:${OBJ}
	ar rcs ${NAME} ${OBJ}

all :	${NAME}

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re :	fclean	all
