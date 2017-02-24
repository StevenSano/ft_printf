/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagi_ut.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 22:42:34 by hvillasa          #+#    #+#             */
/*   Updated: 2017/02/08 22:42:36 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*void while_put(int width, char sz, int *str_len)
{
	while (width-- > 0)
	{
		ft_putchar(sz);
		str_len++;
	}
}
*/
static void check_neg(int min_width, FMT *f)
{
	if (f->min_width > f->precision)
	{
		min_width = (f->precision  <= f->arg_len) ?
		f->min_width - f->arg_len : f->min_width - f->precision;
		min_width -= (f->pos || f->arg.i < 0) ? 1 : 0;
		while (min_width-- > 0)
			ft_putchar(' ');
		if (f->pos && f->arg.i >= 0)
			ft_putchar('+');
	}
	f->zero = 1;
	f->min_width = (f->pos || f->arg.i < 0) ? 1 : 0;
	if (f->arg.i < 0 && !f->min_width)
		f->precision++;
	f->min_width += f->precision;
}

void 	print_widthPrec(FMT *f)
{
	int min_width;

	min_width = 0;
	if (f->precision > 0)
	{
		if (!f->neg)
			check_neg(min_width, f);
		else
		{
			if (f->pos && f->arg.i >= 0)
				ft_putchar('+');
			if (f->min_width > f->precision)
			{
				min_width = (f->precision <= f->arg_len) ?
				0 : f->precision - f->arg_len;
				f->min_width -= f->pos ? min_width + 1 : min_width;
				if ((f->pos || f->arg.i < 0) && f->arg.i < 0)
				{
					ft_putchar('-');
					f->min_width -= 1;
				}
				while (min_width-- > 0)
					ft_putchar('0');
				f->pos = 0;
			}
			else
			{
				f->min_width = f->precision;
				f->zero = 1;
				f->pos = 0;
				f->neg = 0;
			}
		}
	}
}
