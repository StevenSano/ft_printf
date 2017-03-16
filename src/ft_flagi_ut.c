/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagi_ut.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 22:42:34 by hvillasa          #+#    #+#             */
/*   Updated: 2017/03/09 15:51:25 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void check_noneg(int min_width, FMT *f)
{
	if (f->min_width > f->precision)
	{
		min_width = (f->precision  < f->arg_len) ?
		f->min_width - f->arg_len : f->min_width - f->precision;
		min_width -= (f->pos || f->arg.i < 0) ? 1 : 0;
		if (min_width == 1)
			min_width = 0;
		if (f->hash && (f->con_spec != 'i' && f->con_spec != 'u'))
			f->min_width += (f->con_spec == 'x' || f->con_spec == 'X' ||
			f->con_spec == 'p' ) ? 2 : 1;

		f->width_prec_len += min_width;
		while (min_width-- > 0)
			ft_putchar(' ');
		if (f->pos && f->arg.i >= 0)
			ft_putchar('+');
	}
	f->zero = 1;
	f->min_width = (f->pos || f->arg.i < 0) ? 1 : 0;
	if (f->arg.i < 0 && !f->min_width)
		f->precision++;
	if (f->hash)
		f->min_width += (f->con_spec == 'x' || f->con_spec == 'X' ||
		f->con_spec == 'p' ) ? 2 : 1;
	f->min_width += f->precision;
}

void 	print_widthPrec(FMT *f)
{
	int min_width;

	min_width = 0;
	//f->zero = (f->zero && f->precision == 0) ? 0 : 1;
	if (f->precision)
	{
		f->con_spec == 'i' || f->con_spec == 'u' ? get_lenprint_iu(f) :
		get_lenprint_oxXp(f, 0);
		if (!f->neg)
			check_noneg(min_width, f);
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
				if (f->hash)
					min_width +=(f->con_spec == 'x' || f->con_spec == 'X' ||
				f->con_spec == 'p' ) ? 2 : 1;
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
