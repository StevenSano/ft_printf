#include "ft_printf.h"

void	get_asset(const char **fmt, va_list args, int *fin_size)
{
	size_t flags_len;
	char	*s;
  FMT * f;

  s = NULL;
	f = f_set();
	flags_len = 0;
	while (**fmt)
	{


		if (**fmt == F)
		{
			s = ft_strndup((*fmt) - flags_len, flags_len + 1);
			flag_mod(s, fin_size, f);
			break ;
		}
		else if ((**fmt == 'l' && *((*fmt) + 1) == 'c') || **fmt == 'C')
		{
			if (**fmt == 'l')
				(*fmt)++;
			f->con_spec = 'C';
			s = ft_strndup((*fmt) - flags_len, flags_len + 1);
			flag_wc(args, s, fin_size, f);
			break ;
		}
		else if ((**fmt == 'l' && *((*fmt) + 1) == 's') || **fmt == 'S')
		{
			if (**fmt == 'l')
				(*fmt)++;
			f->con_spec = 'S';
			s = ft_strndup((*fmt) - flags_len, flags_len + 1);
			flag_ls(args, s, fin_size, f);
			break ;
		}
		else if (**fmt == 'c')
		{
			f->con_spec = **fmt;
			s = ft_strndup((*fmt) - flags_len, flags_len + 1);
			flag_c(args, s, fin_size, f);
			break ;
		}

		else if (**fmt == 's')
		{
			f->con_spec = **fmt;
			s = ft_strndup((*fmt) - flags_len, flags_len + 1);
			flag_s(args, s, fin_size, f);
			break ;
		}
		else if (**fmt == 'i' || **fmt == 'd' ||
		**fmt == 'u' || **fmt == 'o' || **fmt == 'x' || **fmt == 'X')
		{
			s = ft_strndup((*fmt) - flags_len, flags_len + 1);
			f->con_spec = (**fmt == 'd') ? 'i' : **fmt;
			flag_i(args, s, fin_size, f);
			break ;
		}
		else if (**fmt == 'D' || **fmt == 'O' || **fmt == 'U')
		{
			s = ft_strndup((*fmt) - flags_len, flags_len);
			if (**fmt == 'D')
			{
				f->length_mod = "l";
				f->con_spec = 'i';
			}
			else if (**fmt == 'O')
			{
				f->length_mod = "l";
				f->con_spec = 'o';
			}
			else if (**fmt == 'U')
			{
				f->length_mod = "l";
				f->con_spec = 'u';
			}
			flag_i(args, s, fin_size, f);
			break ;
		}
		else if (**fmt == 'p')
		{
			s = ft_strndup((*fmt) - flags_len, flags_len);
			f->con_spec = 'p';
			flag_i(args, s, fin_size, f);
			break ;
		}
		else if (*((*fmt) + 1) == 0)
		{
			break;
		}
		(*fmt)++;
		flags_len++;
	}
}
