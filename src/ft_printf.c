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

static void	get_asset(const char **fmt, va_list args, int *fin_size)
{
	size_t flags_len;
	FMT * f;

	f = f_set();
	flags_len = 0;
	while (**fmt)
	{
		char	*s;

		if (**fmt == F)
		{
			s = ft_strndup((*fmt) - flags_len, flags_len + 1);
			flag_mod(s, fin_size, f);
			break ;
		}
		else if (**fmt == 'c' || **fmt == 'C')
		{
			f->con_spec = **fmt;
			s = ft_strndup((*fmt) - flags_len, flags_len + 1);
			flag_c(args, s, fin_size, f);
			break ;
		}
		else if (**fmt == 's' || **fmt == 'S')
		{
			f->con_spec = **fmt;
			s = ft_strndup((*fmt) - flags_len, flags_len + 1);
			flag_s(args, s, fin_size, f);
			break ;
		}
		else if (**fmt == 'i' || **fmt == 'd' ||
		**fmt == 'u' || **fmt == 'o' || **fmt == 'x' || **fmt == 'X')
		{
			s = ft_strndup((*fmt) - flags_len, flags_len + 1);
			f->con_spec = (**fmt == 'd') ? 'i' : **fmt;
			flag_i(args, s, fin_size, f);
			break ;
		}
		else if (**fmt == 'D' || **fmt == 'O' || **fmt == 'U')
		{
			s = ft_strndup((*fmt) - flags_len, flags_len);
			if (**fmt == 'D')
			{
				f->length_mod = "l";
				f->con_spec = 'i';
			}
			else if (**fmt == 'O')
			{
				f->length_mod = "l";
				f->con_spec = 'o';
			}
			else if (**fmt == 'U')
			{
				f->length_mod = "l";
				f->con_spec = 'u';
			}
			flag_i(args, s, fin_size, f);
			break ;
		}
		else if (**fmt == 'p')
		{
			s = ft_strndup((*fmt) - flags_len, flags_len);
			f->con_spec = 'p';
			flag_i(args, s, fin_size, f);
			break ;
		}
		(*fmt)++;
		flags_len++;
	}
}

static int	assets(va_list args, const char *format)
{
	int			fin_size;

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

int	ft_printf(const char *format, ...)
{
	int		asset;
	va_list args;

	va_start(args, format);
	asset = assets(args, format);
	va_end(args);
	return (asset);
}
