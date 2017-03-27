/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 00:58:45 by hvillasa          #+#    #+#             */
/*   Updated: 2017/03/16 17:46:06 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	assets(va_list args, const char *format)
{
	int			fin_size;

	fin_size = 0;
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format);
			fin_size++;
		}
		if (*format == '%')
		{
			format++;
			get_asset(&format, args, &fin_size);
		}
		format++;
	}
	return (fin_size);
}

/*
** %[flag][min width][precision][length modifier][conversion specifier]
*/

int	ft_printf(const char *format, ...)
{
	int		asset;
	va_list args;

	va_start(args, format);
	asset = assets(args, format);
	va_end(args);
	return (asset);
}
