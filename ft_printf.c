/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 00:58:45 by hvillasa          #+#    #+#             */
/*   Updated: 2017/01/12 02:12:07 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/ft_printf.h"

/*static int		assets(va_list args, const char *format, char *pf_buf)
{
	char	*str;
	char	*tmp;
	int		int_tmp;
	int i = 0;
	int_tmp = 0;
	str = pf_buf;
	while (*format)
	{
		if (*format != '%')
			str[i++] = *format;
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				str[i++] = '%';
			else if (*format == 'c')
				flag_c(&(str[i++]), args);
			else if (*format == 's')
			{
				flag_s(&str[i++], args);
			}
			else if (*format == 'i' || *format == 'd')
			{
				tmp = ft_itoa(va_arg(args, int));
				while (*tmp)
					str[i++] = *tmp++;
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
					str[i++] = *tmp++;
				ft_strclr(tmp);
				
			}
		}
		format++;
	}
	str[i] = '\0';
	return (ft_strlen(str)); //length of final string
}*/
static int		assets(va_list args, const char *format)
{
	int		 fin_size;

	fin_size = 0;
	while (*format)
	{
		/*if (!(ft_strchr(format, '%')))
		{
			ft_putstr(format);
			return ((int)ft_strlen(format));
		}*/
		if (*format != F)
		{
			
			ft_putchar(*format);
			fin_size++;
		}
		if (*format == F)
		{
			format++;
			if (*format == F)
			{
				ft_putchar(F);
				fin_size++;
			}
			else if (*format == 'c')
				flag_c(args, &fin_size);
			else if (*format == 's')
				flag_s(args, &fin_size);
			else if (*format == 'i' || *format == 'd')
				flag_i(args, &fin_size);
		}
		format++;
	}
	return (fin_size);
}
int ft_printf(const char *format, ...)
{
//	char	pf_buf[BUFPF];
	int		asset;
	va_list args;

	va_start(args, format);
	asset = assets(args, format);
	va_end(args);
//	ft_putstr(pf_buf); //print returning string - set new str[1024]
	return (asset);
}

int main(void)
{
	int i = 0;
//	char *s = "this is i\n";
//	int i = (int)(ft_strchr(s, '%') - s);
//	char *str = ft_strndup(s, i);
//	i = ft_printf("%%\nchar:%c\nthis is a new str:%s\nmore text\n", 'T', "love");
//	ft_printf("int:i\nunsigned:%D\n", 42, -420247);
//	i = ft_printf("str:%s\n%s\n", "ABcd","lol"); //
	i = ft_printf("int:%i\tdec:%d\n", 42, -420);
	printf("%4c strlen:%i\n", '^', i);
	return (0);
}
