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
			flag_s(args, ft_strndup((*fmt) - flags_len, flags_len + 1), fin_size); // remodify for str
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

int main(void)
{
//	char *s = "this is i\n";
//	int i = (int)(ft_strchr(s, '%') - s);
//	char *str = ft_strndup(s, i);
//	i = ft_printf("%%\nchar:%c\nthis is a new str:%s\nmore text\n", 'T', "love");
//	ft_printf("int:i\nunsigned:%D\n", 42, -420247);
//	i = ft_printf("str:%s\n%s\n", "ABcd","lol"); //
//i = ft_printf("%%int:%i\tdec:%d\n", 42, -420);
//	printf("%4c strlen:%i\n", '^', i);
	//int i;//, f;

	//i = ft_printf("**%s**\n", "HSV");//, 'i',"love code");// printf("\n%i\n", i);
	//f =    printf("**%2s**\n", "HSV"); printf("\n%i\n", f);
	int i, f;
	const char *s = "**%3c**%10s**\n";
	i = ft_printf(s, 'A', "ssss"); printf("\n|len:%i|\n\n", i);
	f =    printf(s, 'A', "ssss"); printf("\n|len:%i|\n\n", f);
	//i = ft_printf("**%4.33s**\n**|%-4.1s|**\n", "HSV", "ABC");printf("\n|len:%i|\n\n", i);
	//f =    printf("**%4.33s**\n**|%-4.1s|**\n", "HSV", "ABC");printf("\n|len:%i|\n\n", f);
	return (0);
}
