/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 09:54:07 by hvillasa          #+#    #+#             */
/*   Updated: 2017/03/09 15:50:46 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void flag_mod(char *fmt, int *fin_size, FMT *f)
{
	setForPrint(fmt, f);
	get_prec_min(f, fmt);
	f->precision = 0;
	f->arg_len = 1;
	if (f->neg)
		ft_putchar('%');
	if (f->min_width)
		ft_putWhtSp(f);
	if (!f->neg)
		ft_putchar('%');
	*fin_size += f->min_width ? f->min_width : 1;
}

void get_prec_min(FMT *f, char *fmt)
{
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
}

void flag_c(va_list args, char *fmt, int *fin_size, FMT *f)
{
	setForPrint(fmt, f);
	get_prec_min(f, fmt);
	get_conversion(f, args);
	f->arg_len = 1;
	ft_print(f);
	*fin_size += f->min_width ? f->min_width : f->arg_len;
	free((void*)f);
}
