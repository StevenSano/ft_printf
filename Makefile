# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/08 10:28:09 by hvillasa          #+#    #+#              #
#    Updated: 2017/01/18 20:50:59 by hvillasa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = ft_printf
FLAGS = gcc -Wall -Wextra -Werror
LIB   = libft/libft.a

SRC = ft_printf.c \
	  src/ft_flagc.c \
	  src/ft_flags.c \
	  src/ft_flagi.c \
	  src/ft_flagi_ut.c \
	  src/ft_whitesp.c \
	  src/ft_setAssets.c \

all:
	$(FLAGS) -g main.c $(SRC) $(LIB) -o $(NAME)

clean:
	rm -rf $(NAME)

.PHONY: all, clean
