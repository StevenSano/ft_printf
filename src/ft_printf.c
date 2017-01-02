
#include "../includes/ft_printf.h"


void assets(va_list args, char *format)
{
	char c;
	ft_putendl(format);
	c = va_arg(args, int);
	ft_putchar(c);
}



int ft_printf(char *format, ...)
{
	va_list args;

	va_start(args, format);
	assets(args, format);
	va_end(args);
	return (ft_strlen(format));
}
