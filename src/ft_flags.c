/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 20:45:59 by hvillasa          #+#    #+#             */
/*   Updated: 2017/01/18 20:46:01 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			flag_s(va_list args, char *fmt, int *fin_size)
{
	FMT 		*f;
	char		*tmp;

	f = set();
	while (*fmt)
	{
		if (*fmt == '-')
			f->neg = '-';
		if (ft_isdigit(*fmt))
			f->min_width = ft_digitInStr(&fmt);//printf("%i\n", f->min_width);printf("%c\n", *fmt);
		if (*fmt == '.' && ft_isdigit(*(fmt + 1)))
			f->precision = ft_digitInStr(&fmt);//printf("%i\n", f->precision);exit(1);
		fmt++;
	}
	//ft_printWhtSp(f, 0, ft_strlen(f->type_of));
	tmp = va_arg(args, char*);
	*fin_size += ft_strlen(tmp);
	ft_putstr(tmp);
}
