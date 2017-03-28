#include "ft_printf.h"

static void set_ulong(const char **fmt, FMT *f, size_t flags_len, va_list args,
	int *fin_size)
{
	f->length_mod = "l";
	if (**fmt == 'D')
		f->con_spec = 'i';
	else if (**fmt == 'O')
		f->con_spec = 'o';
	else if (**fmt == 'U')
		f->con_spec = 'u';
	flag_i(args, ft_strndup((*fmt) - flags_len, flags_len), fin_size, f);
}

static void set_lcc(const char **fmt, FMT *f, size_t flags_len, va_list args,
	int *fin_size)
{
	if (**fmt == 'l')
	{
		(*fmt)++;
		f->con_spec = 'C';
	}
	else
		f->con_spec = **fmt;
	if (**fmt == 'C')
		flag_wc(args, ft_strndup((*fmt) - flags_len, flags_len), fin_size, f);
	else
		flag_c(args, ft_strndup((*fmt) - flags_len, flags_len), fin_size, f);
}

static void set_lss(const char **fmt, FMT *f, size_t flags_len, va_list args,
	int *fin_size)
{
	if (**fmt == 'l')
	{
		(*fmt)++;
		f->con_spec = 'S';
	}
	else
		f->con_spec = **fmt;
	flag_s(args, ft_strndup((*fmt) - flags_len, flags_len), fin_size, f);
}

void	get_asset(const char **fmt, va_list args, int *fin_size)
{
	size_t flags_len;
 	FMT * f;

	f = f_set();
	flags_len = 0;
	while (**fmt)
	{
		if (**fmt == '%')
		{
			flag_mod( ft_strndup((*fmt) - flags_len, flags_len + 1), fin_size, f);
			break ;
		}
		else if (((**fmt == 'l' && *((*fmt) + 1) == 'c') || **fmt == 'C') || **fmt == 'c')
		{
			set_lcc(fmt, f, flags_len, args, fin_size);
			break ;
		}
		else if (((**fmt == 'l' && *((*fmt) + 1) == 's') || **fmt == 'S') || **fmt == 's')
		{
			set_lss(fmt, f, flags_len, args, fin_size);
			break ;
		}
		else if (**fmt == 'i' || **fmt == 'd' || **fmt == 'p' || **fmt == 'u' || **fmt == 'o' || **fmt == 'x' || **fmt == 'X')
		{
			f->con_spec = (**fmt == 'd') ? 'i' : **fmt;
			flag_i(args, ft_strndup((*fmt) - flags_len, flags_len), fin_size, f);
			break ;
		}
		else if (**fmt == 'D' || **fmt == 'O' || **fmt == 'U')
		{
			set_ulong(fmt, f, flags_len, args, fin_size);
			break ;
		}
		else if (*((*fmt) + 1) == 0)
			break ;
		(*fmt)++;
		flags_len++;
	}
}
