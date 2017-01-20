*/ ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 20:48:07 by hvillasa          #+#    #+#             */
/*   Updated: 2017/01/18 20:48:08 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "printf.h"

void			flag_i(va_list args, int *fin_size)
{
	char		*tmp;

	tmp = ft_itoa(va_arg(args, int));
	*fin_size += ft_strlen(tmp);
	ft_putstr(tmp);
}
