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




void	flag_s(va_list args, char *fmt, int *fin_size, t_fmt *f)
{
	setforprint(fmt, f);
	get_prec_min(f, fmt);
	get_conversion(f, args);
	if (f->con_spec == 's')
		f->arg_len = (int)ft_strlen(f->arg.s);
	if (f->con_spec == 'S')
		f->arg_len = f->arg.wct == NULL ? 6 : ft_wcstrlen(f->arg.wct);
	else
		f->arg_len = (f->arg_len < 0) ? 0 : f->arg_len;
	f->precision = (!f->precision || f->precision > f->arg_len) ? f->arg_len : f->precision;
	if (!prec_set_zerostr(fmt) && f->con_spec == 'S' && f->precision < f->arg_len && f->arg.wct != NULL)
	{
		if (!f->min_width && f->precision < f->arg_len)
			*fin_size = ft_wcstrlenpr(f->arg.wct, f->precision);
		else
			*fin_size += (f->min_width > f->precision) ? f->min_width : f->precision;
	}
	else if (prec_set_zerostr(fmt) && f->min_width && (f->precision == f->arg_len))
		*fin_size += f->min_width;
	else
		*fin_size += (f->min_width > f->precision) ? f->min_width : f->precision;
	if (f->con_spec == 'S')
		f->arg_len = f->precision ? f->precision : ft_wcstrlen(f->arg.wct);
	else
		f->arg_len = f->precision ? f->precision : (int)ft_strlen(f->arg.s);
	if (prec_set_zerostr(fmt) && f->min_width && (f->precision == f->arg_len))
	{
		int min_width;
		//f->min_width += f->precision;
		min_width = f->min_width;
		while (min_width-- > 0)
			if (!f->zero)
				ft_putchar(' ');
			else
				ft_putchar('0');
		//ft_putWhtSp(f);
	}
	else
		ft_print(f);
	free((void*)f);
}
