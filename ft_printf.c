/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 00:58:45 by hvillasa          #+#    #+#             */
/*   Updated: 2017/01/17 17:28:27 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/ft_printf.h"

static void	get_asset(const char **fmt, va_list args, int *fin_size)
{
	size_t  flags_len;

	flags_len = 0;
	while (**fmt)
	{
		if (**fmt == F)
		{
			flag_mod(fin_size);
			break;
		}
		else if (**fmt == 'c' || **fmt == 'C')
		{
			flag_c(args, ft_strndup((*fmt) - flags_len, flags_len + 1), fin_size);
			break;
		}
		else if (**fmt == 's' || **fmt == 'S')
		{
			flag_s(args, ft_strndup((*fmt) - flags_len, flags_len + 1), fin_size);
			break;
		}
		else if (**fmt == 'i' || **fmt == 'd')
		{
			flag_i(args, ft_strndup((*fmt) - flags_len, flags_len + 1), fin_size);
			break;
		}
		(*fmt)++;
		flags_len++;
	}

}

static int		assets(va_list args, const char *format)
{
	int		 fin_size;

	fin_size = 0;
	while (*format)
	{
		if (*format != F)
		{
			ft_putchar(*format);
			fin_size++;
		}
		if (*format == F)
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

int ft_printf(const char *format, ...)
{
	int		asset;
	va_list args;

	va_start(args, format);
	asset = assets(args, format);
	va_end(args);
	return (asset);
}
