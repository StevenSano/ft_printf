/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 16:55:23 by hvillasa          #+#    #+#             */
/*   Updated: 2017/03/16 17:33:23 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t		i_prec(char *length_mod, va_list args)
{
	intmax_t nb;

	nb = (intmax_t)va_arg(args, intmax_t);
	if (length_mod == NULL)
		return ((int)nb);
	else if (!ft_strcmp(length_mod, "hh"))
		return ((signed char)nb);
	else if (!ft_strcmp(length_mod, "h"))
		return ((short)nb);
	else if (!ft_strcmp(length_mod, "z"))
		return ((size_t)nb);
	else
		return (nb);
}

void	setforprint(char *fmt, FMT *f)
{
	while (*fmt)
	{
		if (*fmt == '-')
			f->neg = 1;
		else if (*fmt == ' ' && f->sp == 0)
			f->sp = 1;
		else if (*fmt == '+')
			f->pos = 1;
		else if (*fmt == '0' && !ft_isdigit(*(fmt - 1)) && *(fmt - 1) != '.')
			f->zero = 1;
		if (*fmt == 'h' && f->length_mod == NULL)
			f->length_mod = (*(fmt + 1) == 'h') ? "hh" : "h";
		if (*fmt == 'l' && f->length_mod == NULL)
			f->length_mod = (*(fmt + 1) == 'l') ? "ll" : "l";
		if (*fmt == 'j' && f->length_mod == NULL)
			f->length_mod = "j";
		if (*fmt == 'z' && f->length_mod == NULL)
			f->length_mod = "z";
		fmt++;
	}
}

static void	print_id(FMT *f)
{
	print_widthprec(f);
	if (f->arg.i < 0 && f->con_spec == 'i')
	{
		if (f->neg)
		{
			f->arg.i *= (f->precision) ? -1 : 1;
			print_conversion(f);
			f->zero = 0;
			ft_putWhtSp(f);
		}
		else
		{
			char *s;

			if (f->zero)
			{
				//
				f->min_width -= 1;
				ft_putchar('-');
			}
			s = ft_intmax_ttoa(f->zero ? f->arg.i * -1 : f->arg.i);
			f->arg_len = (int)ft_strlen(s);
			ft_putWhtSp(f);
			ft_putstr(s);
		}
	}
	else
		ft_print(f);
}

void	print_setlen(FMT *f, int *fin_size)
{
	if ((f->min_width == 0 && f->precision == 0))
	{
		if (f->pos && f->arg.i >= 0)
		{
			*fin_size += 1;
			ft_putchar('+');
		}
		if (f->arg.i > 0 && f->sp && f->con_spec == 'i' && !f->pos)
		{
			ft_putchar(' ');
			*fin_size += 1;
		}
		print_conversion(f);
		*fin_size += (f->con_spec == 'p' && f->arg.u == 0) ?
		 	f->arg_len + 2: f->arg_len;
	}
	else
	{
		print_id(f);
		f->width_prec_len = f->width_prec_len <= -1 ? 0 : f->width_prec_len;
		f->con_spec == 'i' || f->con_spec == 'u' ? get_lenprint_iu(f) :
		get_lenprint_oxXp(f, 0);

		*fin_size += f->arg_len + f->width_prec_len;
	}
}


void			flag_i(va_list args, char *fmt, int *fin_size, FMT *f)
{
	if (f->con_spec == 'i')
		setforprint(fmt, f);
	else if (f->con_spec == 'u' || f->con_spec == 'o' ||
	f->con_spec == 'x' || f->con_spec == 'X' || f->con_spec == 'p')
		setForPrint_uox(fmt, f);
	get_prec_min(f, fmt);
	get_conversion(f, args);
	if (prec_set_zero(fmt) && ((f->arg.i == 0 || f->arg.u == 0)))
	{
		if (f->hash && (f->con_spec != 'i' || f->con_spec != 'u')
				&& f->arg.u != 0)
		{
			get_lenprint_oxXp(f, 1);
			*fin_size += 1;
		}
		else
		{
			if (f->arg.i == 0 && f->con_spec == 'i' && f->precision)
				print_setlen(f, fin_size);
			else
			{
				ft_putWhtSp(f);
				if (f->con_spec == 'o' && f->hash)
					ft_putchar('0');
				*fin_size += (f->hash && f->con_spec == 'o') ? 1 :
					f->width_prec_len;
			}
		}
	}
	else
		print_setlen(f, fin_size);
	free((void*)f);
}
