/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 01:06:14 by hvillasa          #+#    #+#             */
/*   Updated: 2017/01/18 10:50:49 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>

# include "../libft/libft.h"
# include <stdarg.h>
#include <wchar.h>
#include <stdint.h> // for intmax_t

#define F '%'

typedef union type_of
{
	unsigned char 	c;
	wint_t			wit;
	char			*s;
	wchar_t			*wct;
	intmax_t		i;
}			TYPE_OF;


typedef struct	fmt
{
	char		hash;
	char		zero;
	char		sp;
	char		neg;
	char		pos;
	int			min_width;
	int			precision;
	char		*length_mod;
	char		con_spec;
	TYPE_OF 	arg;
}				FMT;

int		ft_printf(const char *format, ...);

/*
** %[flag][min width][precision][length modifier][conversion specifier]
** flags & c
*/
void	flag_mod(int *fin_size);
void 	flag_c(va_list args, char *fmt, int *fin_size);
void	flag_s(va_list args, char *fmt, int *fin_size);
/*
**	ft_flagi.c
*/
intmax_t 	i_prec(char *length_mod, intmax_t nb);
void		flag_i(va_list args, char *fmt, int *fin_size);
void 		print_len_mod(int arg_i, char *length_mod);
/*
**	ft_whitesp.c
*/
size_t	ft_digitInStr(char **fmt); //fids first ints in a str
void 	ft_putWhtSp(FMT *f);
void	ft_print(FMT *f);
/*
**ft_setAssets.c
*/
void 	print_set(FMT *f);
struct 	fmt *set(void);
void 	get_conversion(FMT *f, va_list args);
void 	print_conversion(FMT *f);

#endif
