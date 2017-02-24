\/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 19:42:14 by hvillasa          #+#    #+#             */
/*   Updated: 2017/02/21 19:42:17 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"


//for this flag we can just use flag_i
//and reporpuse fx i_prec() for use of flag specifier
//such as " u D   "
//unsigned decimal (u)

//functions in ft_flagi should not be void and made ready
//for reuse
/*
	when nb == -1 return value is 4294967295
	when nb > -1 after this number is subtracted from 4294967295
		ex) nb = -10
			then conversion
			nb == 4294967295 - 9  = 4294967286
			nb == 4294967295 - 96 = 4294967200

			4294967295 == UINT_MAX
*/
intmax_t		u_prec(char *length_mod, va_list args)
{
	intmax_t nb;

	nb = i_prec(length_mod, args);
	if (nb < 0)
	{
		//get the conversion
	}
	return (nb);
 }


void flag_u(va_list args, char *fmt, int *fin_size)
{
	FMT *f;

	f = set();
	setForPrint(fmt, f);
	f->con_spec = 'u';
	while (*fmt)
	{
		if (ft_isdigit(*fmt) && *fmt != '0')
		{
			if (*(fmt - 1) == '.')
				f->precision = ft_digitInStr(&fmt);
			else
				f->min_width = ft_digitInStr(&fmt);
		}
		fmt++;
	}
	get_conversion(f, args);
	print_setlen(f, fin_size);
	//free(f);
}
