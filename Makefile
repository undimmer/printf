# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anquesad <anquesad@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/27 23:48:57 by anquesad          #+#    #+#              #
#    Updated: 2024/07/29 18:56:02 by anquesad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libftprintf.a
INCLUDE = ft_printf.h

SRC 	= 	ft_printf.c	ft_basics.c \

OBJ		= 	${SRC:.c=.o}

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf
AR		=	ar rcs

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re
