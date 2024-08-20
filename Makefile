# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anquesad <anquesad@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/11 16:12:00 by anquesad          #+#    #+#              #
#    Updated: 2024/08/11 18:35:23 by anquesad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libftprintf.a
INCLUDE = ft_printf.h

SRC     =       ft_printf.c \
                        ft_putchar.c \
                        ft_putstr.c \
                        ft_putnbr.c \
                        ft_pointer.c 
OBJ             =       ${SRC:.c=.o}

CC              =       gcc
CFLAGS  =       -Wall -Wextra -Werror
RM              =       rm -rf
AR              =       ar rcs

.c.o:
        $(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJ)
        $(AR) $(NAME) $(OBJ)

all: $(NAME)

clean:
        $(RM) $(OBJ)

fclean: clean
        $(RM) $(NAME)

re:             fclean all

.PHONY: all clean fclean re
