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
	return (i);
}

void	ft_putWhtSp(FMT *f)
{
	int min_width;

	min_width = f->min_width - f->precision;
	while (min_width > 0)
	{
		if (f->zero && !f->neg)
			ft_putchar('0');
		else
			ft_putchar(' ');
		min_width--;
	}
}

void	ft_print(FMT *f)
{
	if(f->neg)
	{
		print_conversion(f);
		ft_putWhtSp(f);
	}
	else
	{
		ft_putWhtSp(f);
		print_conversion(f);
	}
}
