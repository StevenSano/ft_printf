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

	size = 0;
	if (wct == NULL)
		ft_putstr("(null)");
	else
	{
		while(*wct && len > 0)
		{
				size = ft_wctomb(mb, *wct);
				if (size > len)
					break;
				write(1, mb, size);
				len -= size;
				wct++;
			}
		}
}

int ft_wcstrlen(wchar_t *wct)
{
	int size;
	char mb[4];

	size = 0;
	while (*wct)
	{
		size += ft_wctomb(mb, *wct);
		wct++;
	}
	return (size);
}

int ft_wcstrlenpr(wchar_t *wct, int len)
{
	int size;
	char mb[4];

	size = 0;
	while (*wct && len > 0)
	{

		size += ft_wctomb(mb, *wct);
		if (size < len)
			break;
		wct++;
		len -= size;
	}
	return (size);
}
size_t	prec_set_zerostr(char *fmt)
{
	size_t d;

	d = 0;
	while (*fmt)
	{
		if (*fmt == '.' && (!ft_isdigit(*(fmt + 1)) || *(fmt + 1) == '0'))
			d = 1;
		fmt++;
	}
	return (d);
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
