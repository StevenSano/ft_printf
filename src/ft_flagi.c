/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 16:55:23 by hvillasa          #+#    #+#             */
/*   Updated: 2017/01/24 16:55:28 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void 	print_id(FMT *f)
{
	if (f->zero && !f->neg)
	{
		if (f->arg.i < 0)
		{
			ft_putchar('-');
			ft_putWhtSp(f);
			ft_putnbr(f->arg.i *= -1);
		}
		else
		{
			ft_putWhtSp(f);
			ft_putnbr(f->arg.i);
		}
	}
	else if (f->pos && f->arg.i >= 0)
	{
		//	either convert number to string for output or
		//	make function put_intmax_t(intmax_t nb) or
		//f->precision++;
		//ft_putchar('+');
		//ft_putWhtSp(f);
		//ft_putnbr(f->arg.i);

		ft_putstr(ft_intmax_ttoa(f->arg.i));

	}
	else
	{
		ft_print(f);
		//ft_putstr(ft_intmax_ttoa(i_prec(f , f->arg.i)));

	}
}

intmax_t i_prec(char *length_mod, va_list args)
{
	intmax_t nb;

	nb = va_arg(args, intmax_t);
	if (!ft_strcmp(length_mod, "hh"))
		nb = (signed char)nb;
	else if (!ft_strcmp(length_mod, "h"))
		nb = (short)nb;
	else if (!ft_strcmp(length_mod, "l"))
		nb = (long)nb;
	else if (!ft_strcmp(length_mod, "ll"))
		nb = (long long)nb;
	else if (!ft_strcmp(length_mod, "j"))
		;
	else if (!ft_strcmp(length_mod, "z"))
		nb = (size_t)nb;
	else
		nb = (int)nb;
//	f->precision = ft_intmax_tlen(nb);
	return (nb);
}

void			flag_i(va_list args, char *fmt, int *fin_size)
{
	FMT			*f;

	f = set();
	while (*fmt)	//write around the + flag!!
	{
		if (*fmt == '-')
			f->neg = 1;
		else if (*fmt == '+')
			f->pos = 1;
		else if (*fmt == '0')
			f->zero = 1;
		else if (ft_isdigit(*fmt) && *(fmt - 1) != '.' && *fmt)
			f->min_width = ft_digitInStr(&fmt);
		else if (*fmt == 'h' && *(fmt++) == 'h')
			f->length_mod = "hh";
		else if (*fmt == 'h' && *(fmt + 1) != 'h')
			f->length_mod = "h";
		else if (*fmt == 'l' && *(fmt++) == 'l')
			f->length_mod = "ll";
		else if (*fmt == 'l' && *(fmt + 1) != 'l')
			f->length_mod = "l";
		fmt++;
	}
	ft_strcpy(&f->con_spec, "i");
	get_conversion(f, args);
	f->precision = ft_intmax_tlen(f->arg.i);

	print_set(f);
	print_id(f);
	*fin_size += (f->min_width) ? f->min_width : f->precision;
	free((void*)f);
}
