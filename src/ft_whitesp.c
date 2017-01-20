/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whitesp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 18:10:52 by hvillasa          #+#    #+#             */
/*   Updated: 2017/01/19 00:08:55 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_digitInStr(char **fmt)
{
	char	*i_str;
	size_t	i;

	i = 0;
	while (**fmt)
	{
		if (ft_isdigit(**fmt))
		{
			while (ft_isdigit(**fmt))
			{
				i++;
				(*fmt)++;
			}
			break;
		}
		(*fmt)++;
	}
	i_str = ft_strndup((*fmt) - i, i);
	i = (size_t)ft_atoi(i_str);
	free((void*)i_str);
//	printf("%lu\n", wht_sp);
	return (i);
}

size_t isMainFlag(char c)
{
	char *mainFlags;

	mainFlags = MAIN_FLAGS;
	while (*mainFlags)
	{
		if (c == *mainFlags)
			return (1);
		mainFlags++;
	}
		return (0);
}



//only for char and maybe char*
static void	ft_putWhtSp(size_t wht_sp, size_t arg_len)
{
	wht_sp -= arg_len;
	while (wht_sp)
	{
		ft_putchar(' ');
		wht_sp--;
	}

}

void	ft_printWhtSp(FMT *f, size_t wht_sp, size_t arg_len)
{
	char *s;

	s = &f->con_spec;
	if(f->neg == '-')
	{
		//if (f->length_mod)
		//	ft_putendl(f->con);//wide character to multibyte va_arg(args, wint_t)
		//else
		print_conversion(f);
		ft_putWhtSp(wht_sp, arg_len);
	}
	else
	{
		ft_putWhtSp(wht_sp, arg_len);
		//if (f->length_mod)
		//	ft_putendl(f->length_mod);//wide character to multibyte va_arg(args, wint_t)
		//else
		//ft_putstr(f->arg_type.c);//printf("%s\n", "here\n");exit(1);
		print_conversion(f);
	}

}
