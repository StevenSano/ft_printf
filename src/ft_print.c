#include "ft_printf.h"

static void print_noneg(FMT *f)
{
	if (f->zero && (f->con_spec != 'i' && f->con_spec != 'u' && f->con_spec != 'c' && f->con_spec != 's'))
	{
		f->zero = 0;
		get_lenprint_oxXp(f, 1);
		f->zero = 1;
	}
	if (f->con_spec != 'S' && f->con_spec != 's' && f->con_spec != 'c' && f->con_spec != 'C')
		f->con_spec == 'i' || f->con_spec == 'u' ? get_lenprint_iu(f) :
		get_lenprint_oxXp(f, 0);
	if (f->con_spec == 'i' && f->sp && f->zero && (f->min_width && f->precision > f->min_width))
	{
		f->width_prec_len += 1;
		f->min_width -= 1;
		ft_putchar(' ');
	}
	if(f->zero && f->sp && f->min_width && !f->precision && f->con_spec == 'i')
	{
		f->width_prec_len += 1;
		f->min_width -= 1;
		ft_putchar(' ');
	}
}

void	ft_print(FMT *f)
{
	if (f->neg)
	{
		if (f->con_spec == 'i' && f->pos && f->arg.i >= 0)
			ft_putchar('+');
		if ((f->con_spec == 'o' || f->con_spec == 'x' || f->con_spec == 'X'))
			get_lenprint_oxXp(f, 1);
		print_conversion(f);
		ft_putWhtSp(f);
	}
	else
	{
		print_noneg(f);
		ft_putWhtSp(f);
		print_conversion(f);
	}
}
