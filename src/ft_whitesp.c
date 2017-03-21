/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whitesp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 18:10:52 by hvillasa          #+#    #+#             */
/*   Updated: 2017/03/16 18:01:44 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	prec_set_zero(char *fmt)
{
	size_t d;

	d = 0;
	while (*fmt)
	{
		if (*fmt == '.')
			d = 1;
		fmt++;
	}
	return (d);
}

size_t		ft_digitInStr(char **fmt)
{
	char	*i_str;
	int		i;

	i = 0;
	while (**fmt)
	{
		if (ft_isdigit(**fmt))
		{
			while (ft_isdigit(**fmt))
			{
				i++;
				(*fmt)++;
			}
			break ;
		}
		(*fmt)++;
	}
	i_str = ft_strndup((*fmt) - i, i);
	i = ft_atoi(i_str);
	free((void*)i_str);
	return (i);
}

void	ft_putWhtSp(FMT *f)
{
	int min_width;

	min_width = (f->con_spec != 's') ? f->min_width - f->arg_len :
		f->min_width - f->arg_len;
	f->width_prec_len += (min_width <= 0) ? 0 : min_width;
	if (f->pos && f->arg.i >= 0)
		min_width -= 1;
	if (f->zero)
	{
		if (f->con_spec == 'i' && f->pos && !f->neg && f->arg.i >= 0
				&& !f->precision)
			ft_putchar('+');
		while (min_width-- > 0)
			if ((f->con_spec != 'c' || f->con_spec != 's') && f->neg)
				ft_putchar(' ');
			else
				ft_putchar('0');
	}
	else
	{
		while (min_width-- > 0)
			ft_putchar(' ');
		if (f->pos && !f->neg && f->arg.i >= 0)
			ft_putchar('+');
		if ((f->con_spec == 'o' || f->con_spec == 'x' || f->con_spec == 'X' ||
		f->con_spec == 'p') && f->hash && !f->neg)
			get_lenprint_oxXp(f, 1);
	}
	f->min_width = (f->min_width < f->arg_len) ? f->arg_len : f->min_width;
}

void	ft_print(FMT *f)
{
	if (f->neg)
	{
		if (f->con_spec == 'i' && f->pos && f->arg.i >= 0)
			ft_putchar('+');
		if (f->con_spec == 'o' || f->con_spec == 'x' || f->con_spec == 'X'
			|| f->con_spec == 'p')
			get_lenprint_oxXp(f, 1);
		print_conversion(f);
		ft_putWhtSp(f);
	}
	else
	{
		if (f->zero && (f->con_spec != 'i' && f->con_spec != 'u'))
		{
			f->zero = 0;
			get_lenprint_oxXp(f, 1);
			f->zero = 1;
		}
		if (f->con_spec != 's' && f->con_spec != 'c' && f->con_spec != 'C')
			f->con_spec == 'i' || f->con_spec == 'u' ? get_lenprint_iu(f) :
			get_lenprint_oxXp(f, 0);
		ft_putWhtSp(f);
		print_conversion(f);
	}
}
