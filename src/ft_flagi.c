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

static	int		get_len(int n)
{
	int			len;

	len = 0;
	if (n <= 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void print_len_mod(int arg_i, char *length_mod)
{
	if (!ft_strcmp(length_mod, ""))
		ft_putnbr(arg_i);
	else if (!ft_strcmp(length_mod, "h"))
		ft_putnbr((short)arg_i);
	else if (!ft_strcmp(length_mod, "hh"))
		ft_putnbr((signed char)arg_i);

}

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
	else
	{

		ft_print(f);

	}
}

void			flag_i(va_list args, char *fmt, int *fin_size)
{
	FMT			*f;

	f = set();
	while (*fmt)	//write around the + flag!!
	{
		if (*fmt == '-')
			f->neg = 1;
		if (*fmt == '0')
			f->zero = 1;
		if (ft_isdigit(*fmt) && *(fmt - 1) != '.' && *fmt)
			f->min_width = ft_digitInStr(&fmt);
		if (*fmt == 'h' && *(fmt + 1) == 'h')
			f->length_mod = "hh"; //signed char
		if (*fmt == 'h' && *(fmt + 1) != 'h')
			f->length_mod = "h"; //short
		fmt++;
	}
	ft_strcpy(&f->con_spec, "i");
	get_conversion(f, args);
	f->precision = get_len(f->arg.i);
	print_id(f);
	*fin_size += (f->min_width) ? f->min_width : f->precision;
	free((void*)f);
}
