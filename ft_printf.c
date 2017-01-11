/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 00:58:45 by hvillasa          #+#    #+#             */
/*   Updated: 2017/01/10 21:32:52 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/ft_printf.h"

int		assets(va_list args, const char *format, char *pf_buf)
{
	char	*str;
	char	*tmp;
	int		int_tmp;

	int_tmp = 0;
	str = pf_buf;
	while (*format)
	{
		if (*format != '%')
			*str++ = *format;
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				*str++ = '%';
			else if (*format == 'c' || *format == 'C')
				*str++ = (unsigned char)va_arg(args, int);
			else if (*format == 's' || *format == 'S')
			{
				tmp = ft_strdup(va_arg(args, char*));
				while (*tmp)
					*str++ = *tmp++;
				ft_strclr(tmp);
			}
			else if (*format == 'i' || *format == 'd')
			{
				tmp = ft_itoa(va_arg(args, int));
				while (*tmp)
					*str++ = *tmp++;
				ft_strclr(tmp);
			}
			else if (*format == 'D')
			{
				int_tmp = va_arg(args, int);
				if (int_tmp < 0)
					int_tmp *= -1;
				else
					tmp = ft_itoa(int_tmp);
				while (*tmp)
					*str++ = *tmp++;
				ft_strclr(tmp);
				
			}
		}
		format++;
	}
	*str = '\0';
	return (ft_strlen(str)); //length of final string
}

int ft_printf(const char *format, ...)
{
	char	pf_buf[BUFPF];
	int		asset;
	va_list args;

	va_start(args, format);
	asset = assets(args, format, pf_buf);
	va_end(args);
	ft_putstr(pf_buf); //print returning string - set new str[1024]
	return (asset);
}

int main(void)
{
//	char *s = "this is i\n";
//	int i = (int)(ft_strchr(s, '%') - s);
//	char *str = ft_strndup(s, i);
	ft_printf("%%\nchar:%C\nthis is a new str:%S\nmore text\n", 'T', "love");
	ft_printf("int:i\nunsigned:%D\n", 42, -420247);
	return (0);
}
