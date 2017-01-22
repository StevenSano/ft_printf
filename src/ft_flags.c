/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 20:45:59 by hvillasa          #+#    #+#             */
/*   Updated: 2017/01/18 20:46:01 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_prec(int precision, int slen)
{
	if (!precision || precision > slen)
		precision = slen;
	return (precision);
}


/*
**	create a new function that holds all checks
**	and pass through ft_striter()
*/
void			flag_s(va_list args, char *fmt, int *fin_size)
{
	FMT 		*f;

	f = set();
	while (*fmt)
	{
		if (*fmt == '-')
			f->neg = 1;
		if (ft_isdigit(*fmt))
			f->min_width = ft_digitInStr(&fmt);
		if (*fmt == '.' && ft_isdigit(*(fmt + 1))) //ft_putchar(*fmt);exit(1);
			f->precision = ft_digitInStr(&fmt);
		if (*fmt == 's' && *(fmt - 1) != 'l')
		{
			ft_strcpy(&f->con_spec, "s");
			get_conversion(f, args);
		}
		fmt++;
	}
	f->precision = check_prec(f->precision, (int)ft_strlen(f->arg.s));
	ft_print(f);
	*fin_size += (f->min_width && f->min_width > f->precision) ?
	f->min_width : f->precision;
	free((void*)f);
}
