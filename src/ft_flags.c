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

wchar_t *ls_prec(va_list args)
{
	wchar_t *wstr;

	wstr = va_arg(args, wchar_t*);
	return (wstr);
}

void print_ls(wchar_t *wct, int len)
{
	int size;
	char mb[4];

	len += 1;
	size = 0;
	if (wct == NULL)
		ft_putstr("(null)");
	else
	{
		while(*wct)
		{
				size = ft_wctomb(mb, *wct);
				write(1, mb, size);
				wct++;
			}
		}
}

int ft_wcstrlen(wchar_t *wct)
{
	int len;
	char mb[4];

	len = 0;
	while (*wct)
	{
		len += ft_wctomb(mb, *wct);
		wct++;
	}
	return (len);
}

void	flag_s(va_list args, char *fmt, int *fin_size, FMT *f)
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

	f->precision = (!f->precision || f->precision > f->arg_len) ?
	f->arg_len : f->precision;
	*fin_size += (f->min_width > f->precision) ? f->min_width : f->precision;
	if (f->con_spec == 'S')
		f->arg_len = f->precision ? f->precision : ft_wcstrlen(f->arg.wct);
	else
		f->arg_len = f->precision ? f->precision : (int)ft_strlen(f->arg.s);
	ft_print(f);
	free((void*)f);
}
