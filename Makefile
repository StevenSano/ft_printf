
FLAGS	= gcc -Wall -Wextra -Werror
SRC		= src/ft_printf.c

all:
	$(FLAGS) main.c $(SRC) includes/ft_printf.h  libft/libft.a
