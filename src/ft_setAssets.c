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
//	if (!(f->arg_type = (TYPE_OF*)malloc(sizeof(TYPE_OF))))
//		return (0);
	f->hash = 0;
	f->zero = 0;
	f->sp = 0;
	f->neg = 0;
	f->pos = 0;
	f->min_width = 0;
	f->precision = 0;
	f->length_mod = "";
	f->con_spec = '\0';
	//arg_type = TYPE_OF. //use for specifying type ex: char* , int long long
	return (f);
}

void	get_conversion(FMT *f, va_list args)
{
	if (f->con_spec == 'c')
		f->arg_type.c = va_arg(args, int);
	if (f->con_spec == 's')
		f->arg_type.s = va_arg(args, char*);


	//printf("%c\n", f->arg_type.c);exit(1);
}

void print_conversion(FMT *f)
{
	if (f->con_spec == 'c')
		ft_putchar(f->arg_type.c);

}
