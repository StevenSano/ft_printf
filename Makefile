# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/08 10:28:09 by hvillasa          #+#    #+#              #
#    Updated: 2017/03/09 16:03:56 by hvillasa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= 	src/ft_printf.c \
			src/ft_print.c \
			src/ft_flagc.c \
	  		src/ft_flags.c \
	  		src/ft_flagi.c \
	  		src/ft_flagi_ut.c \
	  		src/ft_flagu.c \
	  		src/ft_whitesp.c \
	  		src/ft_setAssets.c \
			src/ft_getasset.c \
			libft/ft_strlen.c \
			libft/ft_strdup.c \
			libft/ft_strcpy.c \
			libft/ft_strncpy.c \
			libft/ft_putchar.c \
			libft/ft_putnbr.c \
			libft/ft_putstr.c \
			libft/ft_tolower.c \
			libft/ft_toupper.c \
			libft/ft_isprint.c \
			libft/ft_isascii.c \
			libft/ft_isupper.c \
			libft/ft_islower.c \
			libft/ft_isalpha.c \
			libft/ft_isdigit.c \
			libft/ft_isalnum.c \
			libft/ft_memset.c \
			libft/ft_bzero.c \
			libft/ft_memcpy.c \
			libft/ft_memccpy.c \
			libft/ft_memmove.c \
			libft/ft_memchr.c \
			libft/ft_memcmp.c \
			libft/ft_strcat.c \
			libft/ft_strncat.c \
			libft/ft_strlcat.c \
			libft/ft_strchr.c \
			libft/ft_strrchr.c \
			libft/ft_strcmp.c \
			libft/ft_strncmp.c \
			libft/ft_atoi.c \
			libft/ft_isspace.c \
			libft/ft_strstr.c \
			libft/ft_strequ.c \
			libft/ft_strnequ.c \
			libft/ft_putendl.c \
			libft/ft_putchar_fd.c \
			libft/ft_putstr_fd.c \
			libft/ft_putendl_fd.c \
			libft/ft_putnbr_fd.c \
			libft/ft_strnew.c \
			libft/ft_strclr.c \
			libft/ft_strdel.c \
			libft/ft_strjoin.c \
			libft/ft_memdel.c \
			libft/ft_memalloc.c \
			libft/ft_striter.c \
			libft/ft_striteri.c \
			libft/ft_strmap.c \
			libft/ft_strmapi.c \
			libft/ft_strnstr.c \
			libft/ft_strtrim.c \
			libft/ft_itoa.c \
			libft/ft_strsub.c \
			libft/ft_strsplit.c \
			libft/ft_lstnew.c \
			libft/ft_lstdelone.c \
			libft/ft_lstdel.c \
			libft/ft_lstadd.c \
			libft/ft_lstiter.c \
			libft/ft_lstmap.c \
			libft/ft_swap.c \
			libft/ft_strndup.c \
			libft/ft_putnstr.c \
			libft/ft_intmax_ttoa.c \
			libft/ft_intmax_tlen.c \
			libft/ft_uintmax_ttoa.c \
			libft/ft_itoa_base.c \
			libft/ft_wctomb.c \
			libft/ft_strtouper.c \

.PHONY: all, clean, fclean, re

NAME	= libftprintf.a
CC		= gcc
FLAGS	= -Wall -Wextra -Werror

OBJ		= $(SRC:.c=.o)

all: $(NAME)

#$(NAME):
#		make -C libft/ fclean && make -C libft/
#		$(CC) -c $(FLAGS) $(SRC) -Iinc/
#		ar rc $(NAME) $(OBJ) $(OBJLIB)
#		ranlib $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $^

%.o : %.c
	@$(CC) $(FLAGS) -Iinc -o $@ -c $^



clean:
	@make clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)


re: fclean all
