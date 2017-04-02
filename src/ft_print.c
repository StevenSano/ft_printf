/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 01:06:14 by hvillasa          #+#    #+#             */
/*   Updated: 2017/03/16 18:52:52 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void print_noneg_ifisp(t_fmt *f)
{
	if (f->con_spec == 'i' && f->sp && f->zero && (f->min_width &&
		f->precision > f->min_width))
	{
		f->width_prec_len += 1;
		f->min_width -= 1;
		ft_putchar(' ');
	}
	else if(f->zero && f->sp && f->min_width && !f->precision &&
		f->con_spec == 'i')
	{
		f->width_prec_len += 1;
		f->min_width -= 1;
		ft_putchar(' ');
	}
}

static void print_noneg(t_fmt *f)
{
	if (f->zero && (f->con_spec != 'i' && f->con_spec != 'u' &&
		f->con_spec != 'c' && f->con_spec != 's'&& f->con_spec != 'S' ))
	{
		f->zero = 0;
		get_lenprint_oxXp(f, 1);
		f->zero = 1;
	}
	else if (f->con_spec != 'S' && f->con_spec != 's' && f->con_spec != 'c' &&
		f->con_spec != 'C')
		f->con_spec == 'i' || f->con_spec == 'u' ? get_lenprint_iu(f) :
		get_lenprint_oxXp(f, 0);
	print_noneg_ifisp(f);
}

void	ft_print(t_fmt *f)
{
	if (f->neg)
	{
		if (f->con_spec == 'i' && f->pos && f->arg.i >= 0)
			ft_putchar('+');
		if ((f->con_spec == 'o' || f->con_spec == 'x' || f->con_spec == 'X'))
			get_lenprint_oxXp(f, 1);
		print_conversion(f);
		ft_putWhtSp(f);
	}
	else
	{
		print_noneg(f);
		ft_putWhtSp(f);
		print_conversion(f);
	}
}
