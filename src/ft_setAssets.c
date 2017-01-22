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

	if(!(f = (FMT*)malloc(sizeof(f))))
		return (0);
	if(!(f->length_mod = ft_strnew(2)))
		return (0);

	f->hash = 0;
	f->zero = 0;
	f->sp = 0;
	f->neg = 0;
	f->pos = 0;
	f->min_width = 0;
	f->precision = 0;
	f->length_mod = "";
	f->con_spec = '\0';
	//arg = TYPE_OF. //use for specifying type ex: char* , int long long
	return (f);
}

void	get_conversion(FMT *f, va_list args)
{

	if (f->con_spec == 'c')
		f->arg.c = va_arg(args, int);
	if (f->con_spec == 's')
		f->arg.s = va_arg(args, char*);

	//printf("%s\n", f->arg.s);exit(1);//send to another function to handle printing strings
	//printf("%c\n", f->arg_type.c);exit(1);
}

void print_conversion(FMT *f)
{
	if (f->con_spec == 'c')
		ft_putchar(f->arg.c);
	if (f->con_spec == 's')
		ft_putstr(ft_strndup(f->arg.s, f->precision));
}


void print_set(FMT *f)
{

	printf("\n%i\n%i\n%i\n%i\n%i\n%i\n%i\n%s\n%c\n",
	f->hash,
	f->zero,
	f->sp,
	f->neg,
	f->pos,
	f->min_width,
	f->precision,
	f->length_mod,
	f->con_spec
	);
	//f->arg.
}
