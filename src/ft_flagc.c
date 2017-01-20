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
	size_t wht_sp;
	char	*fmtCp;
	FMT		*f;

	fmtCp = fmt;
	wht_sp = 0;
	f = set();
	while (*fmt)
	{
		if (*fmt == '-')
			f->neg = '-';
		if (ft_isdigit(*fmt) && *fmt != '0')
			f->min_width = ft_digitInStr(&fmt);
		if ((*fmt == 'l' && *(fmt + 1) == 'c') || *fmt == 'C')
		{
			ft_strcpy(f->length_mod, "l");
			//f->con = "wint_t";
		}
		if ((*fmt == 'c') && (*fmt != 'l'))
		{
			ft_strcpy(&f->con_spec, "c");
			get_conversion(f, args);
		}
		fmt++;
	}
	ft_printWhtSp(f, f->min_width, 1);
	*fin_size += f->min_width;
	free((void*)f);
}
