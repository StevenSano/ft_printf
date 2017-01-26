/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 09:54:07 by hvillasa          #+#    #+#             */
/*   Updated: 2017/01/18 10:34:34 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			flag_mod(int *fin_size)
{
	ft_putchar(F);
	*fin_size += 1;
}

void flag_c(va_list args, char *fmt, int *fin_size)
{
	FMT		*f;

	f = set();
	while (*fmt)
	{
		if (*fmt == '-')
			f->neg = 1;
		if (ft_isdigit(*fmt) && *fmt != '0')
			f->min_width = ft_digitInStr(&fmt);
		if (*fmt == 'c' || *fmt == 'C')
		{
			if (*fmt == 'C' || *(fmt - 1) == 'l')
				ft_strcpy(&f->con_spec, "C");	//add condition to check if within ascii
			else
				ft_strcpy(&f->con_spec, "c");
			get_conversion(f, args);
		}
		fmt++;
	}
	f->precision = 1;
	ft_print(f);
	*fin_size += f->min_width ? f->min_width : 1;
	free((void*)f);
}
