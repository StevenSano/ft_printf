# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/31 20:23:45 by hvillasa          #+#    #+#              #
#    Updated: 2016/12/24 21:09:07 by hvillasa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

SRC		= ft_strlen.c \
		  ft_strdup.c \
		  ft_strcpy.c \
		  ft_strncpy.c \
		  ft_putchar.c \
		  ft_putnbr.c \
		  ft_putstr.c \
		  ft_tolower.c \
		  ft_toupper.c \
		  ft_isprint.c \
		  ft_isascii.c \
		  ft_isupper.c \
		  ft_islower.c \
		  ft_isalpha.c \
		  ft_isdigit.c \
		  ft_isalnum.c \
		  ft_memset.c \
		  ft_bzero.c \
		  ft_memcpy.c \
		  ft_memccpy.c \
		  ft_memmove.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_strcat.c \
		  ft_strncat.c \
		  ft_strlcat.c \
		  ft_strchr.c \
		  ft_strrchr.c \
		  ft_strcmp.c \
		  ft_strncmp.c \
		  ft_atoi.c \
		  ft_isspace.c \
		  ft_strstr.c \
		  ft_strequ.c \
		  ft_strnequ.c \
		  ft_putendl.c \
		  ft_putchar_fd.c \
		  ft_putstr_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c \
		  ft_strnew.c \
		  ft_strclr.c \
		  ft_strdel.c \
		  ft_strjoin.c \
		  ft_memdel.c \
		  ft_memalloc.c \
		  ft_striter.c \
		  ft_striteri.c \
		  ft_strmap.c \
		  ft_strmapi.c \
		  ft_strnstr.c \
		  ft_strtrim.c \
		  ft_itoa.c \
		  ft_strsub.c \
		  ft_strsplit.c \
		  ft_lstnew.c \
		  ft_lstdelone.c \
		  ft_lstdel.c \
		  ft_lstadd.c \
		  ft_lstiter.c \
		  ft_lstmap.c \
		  ft_swap.c \
		  get_next_line.c \
		  ft_strndup.c \
		  ft_putnstr.c \
		  ft_intmax_ttoa.c \
		  ft_intmax_tlen.c \
		  ft_itoa_base.c \
		  ft_uintmax_ttoa.c \
		  ft_wctomb.c \
		  ft_strtouper.c \

OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: $(NAME), all, clean, fclean, re
