# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/08 10:28:09 by hvillasa          #+#    #+#              #
#    Updated: 2017/01/11 10:09:11 by hvillasa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FLAGS = gcc -Wall -Wextra -Werror
LIB = libft/libft.a
SRC = ft_printf.c \
	  src/ft_flags.c

all:
	$(FLAGS) $(SRC) $(LIB)

clean:
	rm -rf ./a.out

.PHONY: all, clean
