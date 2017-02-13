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

intmax_t		i_prec(char *length_mod, va_list args)
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
	else if (!ft_strcmp(length_mod, "i"))
		nb = (int)nb;
	return (nb);
 }

static void 	setForPrint(char *fmt, FMT *f)
{
	while (*fmt)
	{
		if (*fmt == '-')
			f->neg = 1;
		else if (*fmt == '+')
			f->pos = 1;
		else if (*fmt == '0' && !ft_isdigit(*(fmt - 1)) && *(fmt -1) != '.')
			f->zero = 1;
		if (*fmt == 'h' && !ft_strcmp(f->length_mod, "00"))
			f->length_mod = (*(fmt + 1) == 'h') ? "hh" : "h";
		if (*fmt == 'l' && !ft_strcmp(f->length_mod, "00"))
			f->length_mod = (*(fmt + 1) == 'l') ? "ll" : "l";
		if (*fmt == 'j' && !ft_strcmp(f->length_mod, "00"))
			f->length_mod = "j";
		fmt++;
	}
	f->con_spec = 'i';
}

static void 	print_id(FMT *f)
{
	print_widthPrec(f);
	if (f->arg.i < 0)
	{
		f->min_width += 1;
		if(f->neg)
		{
			f->arg.i *= (f->precision) ? -1 : 1;
			print_conversion(f);
			f->zero = 0;
			ft_putWhtSp(f);
		}
		else
		{
			if(f->zero)
			{
				ft_putchar('-');
				f->min_width -= 1;
			}
			ft_putWhtSp(f);
			ft_putstr(ft_intmax_ttoa(f->zero ? f->arg.i * -1 : f->arg.i));
		}
	}
	else
		ft_print(f);
}

static void 	print_setlen(FMT *f, int *fin_size)
{
	if (!f->precision || (!f->min_width && !f->precision)) //|| (!f->min_width || !f->precision))
	{
		//puts("1.here");//exit(22);
		*fin_size += (f->pos && f->arg.i > -1) ?
		ft_intmax_tlen(f->arg.i) + 1 : ft_intmax_tlen(f->arg.i);
		if (f->pos && f->arg.i >= 0)
			ft_putchar('+');
		print_conversion(f);
	}
	else
	{
		//puts("2.here");//exit(22);
		f->arg_len = ft_intmax_tlen(f->arg.i);
		print_id(f);
		*fin_size += (!f->precision) ? f->min_width : f->precision;
	}
}

void			flag_i(va_list args, char *fmt, int *fin_size)
{
	FMT			*f;

	f = set();
	setForPrint(fmt, f);
	while (*fmt++)
	{
		if (ft_isdigit(*fmt) && *fmt != '0')
		{
			if (*(fmt - 1) == '.')
				f->precision = ft_digitInStr(&fmt);
			else
				f->min_width = ft_digitInStr(&fmt);
		}
	}
	get_conversion(f, args);
	print_setlen(f, fin_size);
	//free(f);
}
