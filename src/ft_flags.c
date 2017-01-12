/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 09:54:07 by hvillasa          #+#    #+#             */
/*   Updated: 2017/01/12 02:02:38 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			flag_c(va_list args, int *fin_size)
{
	ft_putchar(((unsigned char)va_arg(args, int)));
	*fin_size += 1;
}

void			flag_s(va_list args, int *fin_size)
{
	char		*tmp;

	tmp = va_arg(args, char*);
	*fin_size += ft_strlen(tmp);
	ft_putstr(tmp);
}
void			flag_i(va_list args, int *fin_size)
{
	char		*tmp;

	tmp = ft_itoa(va_arg(args, int));
	*fin_size += ft_strlen(tmp);
	ft_putstr(tmp);
}
