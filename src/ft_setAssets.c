/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setAssets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 11:28:55 by hvillasa          #+#    #+#             */
/*   Updated: 2017/03/16 17:54:30 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

struct fmt	*f_set(void)
{
	FMT		*f;

	IFTRUE(!(f = (FMT*)malloc(sizeof(FMT))), 0);
	f->hash = 0;
	f->zero = 0;
	f->sp = 0;
	f->neg = 0;
	f->pos = 0;
	f->min_width = 0;
	f->precision = 0;
	f->length_mod = NULL;
	f->con_spec = 0;
	f->arg_len = 0;
	f->width_prec_len = 0;
	return (f);
}

void		get_conversion(FMT *f, va_list args)
{
	if (f->con_spec == 'c')
		f->arg.c = (unsigned char)va_arg(args, int);
	else if (f->con_spec == 'C')
		f->arg.wit = va_arg(args, wint_t);
	else if (f->con_spec == 's')
		f->arg.s = s_prec(args);
	else if (f->con_spec == 'S')
		f->arg.wct = va_arg(args, wchar_t*);
	else if (f->con_spec == 'i' || f->con_spec == 'D')
		f->arg.i = i_prec(f->length_mod, args);
	else if (f->con_spec == 'u' || f->con_spec == 'o' ||
		f->con_spec == 'x' || f->con_spec == 'X')
		f->arg.u = u_prec(f->length_mod, args);
	else if (f->con_spec == 'p')
		f->arg.u = p_prec(args);
}

static char	*str_to_uper(char *toup)
{
	int		i;

	i = 0;
	while (*toup)
	{
		if (*toup >= 'a' && *toup <= 'z')
			*toup = ft_toupper(*toup);
		toup++;
		i++;
	}
	return (toup - i);
}

char	*get_lenprint_iu(FMT *f)
{
	char *str;

	if (f->con_spec == 'i')
			str = ft_intmax_ttoa(f->arg.i);
	else
	{
		if (f->arg.u == 0)
			str = "0";
		else
			str = ft_uintmax_ttoa(f->arg.u);
	}
	f->arg_len = (int)ft_strlen(str);
	return (str);
}

char	*get_lenprint_oxXp(FMT *f, char r)
{
	char *str;

	if (f->con_spec == 'o')
		str = ft_itoa_base(f->arg.u, 8);
	if (f->con_spec == 'x' || f->con_spec == 'p')
		str = ft_itoa_base(f->arg.u, 16);
	if (f->con_spec == 'X')
		str = str_to_uper(ft_itoa_base(f->arg.u, 16));
	f->arg_len = (int)ft_strlen(str);
	if (f->hash || f->con_spec == 'p')
	{
		if ((r == 1 || (f->min_width == 0 && f->precision == 0)))
		{
			if (f->con_spec == 'o')
				ft_putstr("0");
			else if ((f->con_spec == 'x' || f->con_spec == 'p')
					&& f->arg.u != 0)
				ft_putstr("0x");
			else if ((f->con_spec == 'X') && f->arg.u != 0)
				ft_putstr("0X");
		}
		if (f->arg.u > 0)
			f->arg_len += (f->con_spec == 'x' || f->con_spec == 'X' ||
			f->con_spec == 'p') ? 2 : 1;
	}
	return (str);
}

void	print_conversion(FMT *f)
{
	if (f->con_spec == 'c')
		ft_putchar(f->arg.c);
	else if (f->con_spec == 'C')
		print_wc(f);
	else if (f->con_spec == 's')
		ft_putstr(ft_strndup(f->arg.s, f->arg_len <= 0 ? 0 : f->precision));
	else if (f->con_spec == 'S')
		{}//ft_putstr(ft_strndup((char*)f->arg.wct, f->precision));
	else if (f->con_spec == 'i' || f->con_spec == 'u')
		ft_putstr(get_lenprint_iu(f));
	else if (f->con_spec == 'o' || f->con_spec == 'x' || f->con_spec == 'X')
		ft_putstr(get_lenprint_oxXp(f, 0));
	else if (f->con_spec == 'p')
		ft_putstr(get_lenprint_oxXp(f, 1));
}
