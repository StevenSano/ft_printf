/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 01:06:14 by hvillasa          #+#    #+#             */
/*   Updated: 2017/03/16 18:52:52 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <wchar.h>
# include <stdint.h>

# define F '%'

typedef union	type_of
{
	unsigned char c;
	char			*s;
	wchar_t			*wct;
	wint_t			wit;
	intmax_t		i;
	uintmax_t		u;
}				TYPE_OF;

typedef struct	fmt
{
	char	hash;
	char	zero;
	char	sp;
	char	neg;
	char	pos;
	int		min_width;
	int		precision;
	char	*length_mod;
	char	con_spec;
	TYPE_OF	arg;
	int		arg_len;
	int		width_prec_len;
}				FMT;

int				ft_printf(const char *format, ...);

/*
** %[flag][min width][precision][length modifier][conversion specifier]
** flags & c
*/
char 			*print_wc(FMT *f);
void			flag_mod(char *fmt, int *fin_size, FMT *f);
void			flag_c(va_list args, char *fmt, int *fin_size, FMT *f);
/*
**	ft_flags.c
*/
void			flag_wc(va_list args, char *fmt, int *fin_size, FMT *f);
char			*s_prec(va_list args);
void			flag_s(va_list args, char *fmt, int *fin_size, FMT *f);
/*
**	ft_flagi.c
*/
void			flag_i(va_list args, char *fmt, int *fin_size, FMT *f);
intmax_t		i_prec(char *length_mod, va_list args);
void			print_setlen(FMT *f, int *fin_size);
void			setforprint(char *fmt, FMT *f);
/*
**	ft_flagi_ut.c
*/
void			print_widthprec(FMT *f);
/*
**	ft_flagu.c
*/
void			get_prec_min(FMT *f, char *fmt);
unsigned long	p_prec(va_list args);
unsigned long	u_prec(char *length_mod, va_list args);
void			setForPrint_uox(char *fmt, FMT *f);
intmax_t		D_prec(char *length_mod, va_list args);
/*
**	ft_whitesp.c«»
*/
size_t	prec_set_zero(char *fmt);
size_t			ft_digitInStr(char **fmt);
void			ft_putWhtSp(FMT *f);
void			ft_print(FMT *f);
/*
**	ft_setAssets.c
*/
char			*get_lenprint_iu(FMT *f);
char			*get_lenprint_oxXp(FMT *f, char r);
struct fmt		*f_set(void);
void			get_conversion(FMT *f, va_list args);
void			print_conversion(FMT *f);

#endif
