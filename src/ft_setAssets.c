/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setAssets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 11:28:55 by hvillasa          #+#    #+#             */
/*   Updated: 2017/01/18 10:58:08 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

struct fmt *set(void)
{
	FMT *f;

	IFTRUE(!(f = (FMT*)malloc(sizeof(f))), 0);
	IFTRUE(!(f->length_mod = ft_strnew(2)), 0);
	f->hash = 0;
	f->zero = 0;
	f->sp = 0;
	f->neg = 0;
	f->pos = 0;
	f->min_width = 0;
	f->precision = 0;
	f->length_mod = "00";
	f->con_spec = '\0';
	f->arg_len = 0;
	return (f);
}

void	get_conversion(FMT *f, va_list args)
{

	if (f->con_spec == 'c')
		f->arg.c = va_arg(args, int);
	else if (f->con_spec == 'C')
		f->arg.wit = va_arg(args, wint_t); //use unsigned int instead
	else if (f->con_spec == 's')
		f->arg.s = va_arg(args, char*);
	else if (f->con_spec == 'S')
		f->arg.wct = va_arg(args, wchar_t*); //
	else if (f->con_spec == 'i')
		f->arg.i = i_prec(f->length_mod, args);
}

void print_conversion(FMT *f)
{
	if (f->con_spec == 'c')
		ft_putchar(f->arg.c);
	if (f->con_spec == 'C')
		ft_putchar(f->arg.wit);
	if (f->con_spec == 's')
		ft_putstr(ft_strndup(f->arg.s, f->precision));
	if (f->con_spec == 'S')
		ft_putstr(ft_strndup((char*)f->arg.wct, f->precision)); //convert wide char to mbchar
	if (f->con_spec == 'i')
		ft_putstr(ft_intmax_ttoa(f->arg.i));
}

void print_set(FMT *f)
{

	printf("\n #: %i\n 0: %i\nsp: %i\n -: %i\n +: %i\nmin_width: %i\nprecission: %i\nlength modifier: %s\ncon_specifier: %c\narg_len: %i\n",
	f->hash,
	f->zero,
	f->sp,
	f->neg,
	f->pos,
	f->min_width,
	f->precision,
	f->length_mod,
	f->con_spec,
	f->arg_len
	);
	//f->arg.
}
