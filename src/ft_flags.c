/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 20:45:59 by hvillasa          #+#    #+#             */
/*   Updated: 2017/03/16 17:16:50 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*s_prec(va_list args)
{
	char *str;

	str = va_arg(args, char*);
	if (str == NULL)
		str = "(null)";
	return (str);
}

void	flag_s(va_list args, char *fmt, int *fin_size, FMT *f)
{
	setforprint(fmt, f);
	get_prec_min(f, fmt);
	get_conversion(f, args);
	f->arg_len = (int)ft_strlen(f->arg.s) - f->precision;
	f->arg_len = (f->arg_len < 0) ? 0 : f->arg_len;
	f->precision = (!f->precision || f->precision > f->arg_len) ?
	f->arg_len : f->precision;
	*fin_size += (f->min_width > f->precision) ? f->min_width : f->precision;
	f->precision = f->arg_len <= 0 ? 0 : f->precision;
	ft_print(f);
	free((void*)f);
}
