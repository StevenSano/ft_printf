/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 19:42:14 by hvillasa          #+#    #+#             */
/*   Updated: 2017/03/09 15:54:13 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t 		p_prec(va_list args)
{
 	uintmax_t	nb;

	nb = (uintmax_t)va_arg(args, void*);
	return (nb);
}

uintmax_t	u_prec(char *length_mod, va_list args)
{
 	uintmax_t nb;

	nb = (uintmax_t)va_arg(args, uintmax_t);
	if (length_mod == NULL)
		return ((unsigned)nb);
	else if (!ft_strcmp(length_mod, "hh"))
		return ((unsigned char)nb);
	else if (!ft_strcmp(length_mod, "h"))
		return ((unsigned short)nb);
	else if (!ft_strcmp(length_mod, "z"))
		 return ((size_t)nb);
	else
		return(nb);
}

void 	setForPrint_uox(char *fmt, FMT *f) //remove this fx
{
	while (*fmt)
	{
		if (*fmt == '#')
			f->hash = 1;
		if (*fmt == '-')
			f->neg = 1;
		if (*fmt == '0' && !ft_isdigit(*(fmt - 1)) && *(fmt -1) != '.')
			f->zero = 1;
		if (*fmt == 'h' && f->length_mod == NULL)
			f->length_mod = (*(fmt + 1) == 'h') ? "hh" : "h";
		if (*fmt == 'l' && f->length_mod == NULL)
			f->length_mod = (*(fmt + 1) == 'l') ? "ll" : "l";
		if (*fmt == 'j' && f->length_mod == NULL)
			f->length_mod = "j";
		if (*fmt == 'z' && f->length_mod == NULL)
			f->length_mod = "z";
		fmt++;
	}
}

/*
**	DOU     The long int argument is converted to signed decimal, unsigned octal,
**		  or unsigned decimal, as if the format had been ld, lo, or lu respec-
**		  tively.  These conversion characters are deprecated, and will eventu-
**		  ally disappear.
**
*/
