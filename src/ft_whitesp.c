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

#include "../inc/ft_printf.h"

size_t		ft_digitInStr(char **fmt)
{
	char	*i_str;
	int		i;

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
	i = ft_atoi(i_str);
	free((void*)i_str);
	return (i);
}

void	ft_putWhtSp(FMT *f)
{
	int min_width;
	min_width = f->min_width -  f->arg_len;
	min_width -= (f->pos ||  f->arg.i < 0) ? 1 : 0;
	if (f->zero)
	{
		if (f->con_spec == 'i' && f->pos && !f->neg && f->arg.i >= 0)
			ft_putchar('+');
		while (min_width-- > 0)
			if (f->con_spec == 'i' && f->neg && f->arg.i > 0)
				ft_putchar(' ');
			else
				ft_putchar('0');
	}
	else
	{
		while (min_width-- > 0)
			ft_putchar(' ');
		if (f->pos && !f->neg && f->arg.i >= 0)
			ft_putchar('+');
	}
}

void	ft_print(FMT *f)
{

	if(f->neg)
	{
		if (f->con_spec == 'i' && f->pos && f->arg.i >= 0)
			ft_putchar('+');
		print_conversion(f);
		ft_putWhtSp(f);
	}
	else
	{
		ft_putWhtSp(f);
		print_conversion(f);
	}
}
