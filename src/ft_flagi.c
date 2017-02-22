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

void 	setForPrint(char *fmt, FMT *f)
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

}

void 	print_id(FMT *f)
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
				f->precision += 1;
			}
			ft_putWhtSp(f);
			ft_putstr(ft_intmax_ttoa(f->zero ? f->arg.i * -1 : f->arg.i));
		}
		f->min_width -= 1;
	}
	else
		ft_print(f);
}

void 	print_setlen(FMT *f, int *fin_size)
{
	if (f->min_width == 0 && f->precision == 0)
	{
		//f->arg_len = ft_intmax_tlen(f->arg.i);
		*fin_size += (f->pos && f->arg.i > -1) ?
		ft_intmax_tlen(f->arg.i) + 1 : ft_intmax_tlen(f->arg.i);
		if (f->pos && f->arg.i >= 0) //make macro to return single value
			ft_putchar('+');
		print_conversion(f);
	}
	else
	{
		//puts("here");
		//add a counter to the structure and pass it to every while loop that prints
		//also create function to hold while loops.
		f->arg_len = ft_intmax_tlen(f->arg.i);
		print_id(f);
		if (f->min_width <= f->arg_len)
			f->min_width = (f->pos && f->arg.i >= 0) ?
			f->arg_len + 1 : f->arg_len;
		if (f->precision <= f->arg_len)
			f->precision = (f->pos && f->arg.i >= 0) ?
			f->arg_len + 1 : f->arg_len;
		*fin_size += (!f->precision) ? f->min_width : f->precision;
	}
}

void			flag_i(va_list args, char *fmt, int *fin_size)
{
	FMT			*f;

	f = set();
	setForPrint(fmt, f);
	f->con_spec = 'i';
	while (*fmt)
	{
		if (ft_isdigit(*fmt) && *fmt != '0')
		{
			if (*(fmt - 1) == '.')
				f->precision = ft_digitInStr(&fmt);
			else
				f->min_width = ft_digitInStr(&fmt);
		}
		fmt++;
	}
	get_conversion(f, args);
	print_setlen(f, fin_size);
	free(f);
}
