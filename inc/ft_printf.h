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
	unsigned char	c;
	char			*s;
	wchar_t			*wct;
	wint_t			wit;
	intmax_t		i;
	uintmax_t		u;
}				TYPE_OF;

typedef struct	s_fmt
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
}				t_fmt;

int				ft_printf(const char *format, ...);
void			get_asset(const char **fmt, va_list args, int *fin_size);
/*
** %[flag][min width][precision][length modifier][conversion specifier]
** flags & c
*/
void 			print_wc(t_fmt *f, char p);
void			flag_mod(char *fmt, int *fin_size, t_fmt *f);
void			flag_c(va_list args, char *fmt, int *fin_size, t_fmt *f);
void			flag_wc(va_list args, char *fmt, int *fin_size, t_fmt *f);

/*
**	ft_flags.c
*/
void 			print_ls(wchar_t *wct, int len);
int 			ft_wcstrlen(wchar_t *wct);
wchar_t 		*ls_prec(va_list args);
char			*s_prec(va_list args);
void			flag_s(va_list args, char *fmt, int *fin_size, t_fmt *f);
/*
**	ft_flagi.c
*/
void			flag_i(va_list args, char *fmt, int *fin_size, t_fmt *f);
intmax_t		i_prec(char *length_mod, va_list args);
void			print_setlen(t_fmt *f, int *fin_size);
void			setforprint(char *fmt, t_fmt *f);
/*
**	ft_flagi_ut.c
*/
void			print_widthprec(t_fmt *f);
/*
**	ft_flagu.c
*/
void			get_prec_min(t_fmt *f, char *fmt);
unsigned long	p_prec(va_list args);
unsigned long	u_prec(char *length_mod, va_list args);
void			setForPrint_uox(char *fmt, t_fmt *f);
intmax_t		D_prec(char *length_mod, va_list args);
/*
**	ft_whitesp.c«»
*/
size_t			prec_set_zero(char *fmt);
size_t			ft_digitInStr(char **fmt);
void			ft_putWhtSp(t_fmt *f);
void			ft_print(t_fmt *f);
/*
**	ft_setAssets.c
*/
char			*get_lenprint_iu(t_fmt *f);
char			*get_lenprint_oxXp(t_fmt *f, char r);
struct s_fmt	*f_set(void);
void			get_conversion(t_fmt *f, va_list args);
void			print_conversion(t_fmt *f);

#endif
