
#include "../includes/ft_printf.h"

char *get_Arg_type(char flag)
{
	IFTRUE((flag == 'c'), "int");
	IFTRUE((flag == 's'), "char*");
	return (NULL);
}

char arg_C(int c)
{
	return ((unsigned char)c);
}


int argCount(char *format)
{
	int i;

	i = 0;
	while (*format)
	{
		if (*format == '%')
		{
			i++;
			format++;
		}
		format++;
	}
	return (i);
}

char	*assets(va_list args, char *format)
{
	char		*str;
	size_t	aC;

	aC = argCount(format);
	if (!aC)
	{
		ft_putendl(format);
		return (format);
	}
	while (aC)
	{

	}

	return (NULL);
}

int ft_printf(char *format, ...)
{
	va_list	args;
	char		*asset;

	va_start(args, format);
	asset = assets(args, format);
	va_end(args);
	return (ft_strlen(asset));
}
#include <stdio.h>
int main(void)
{
	int len;
	char *s = "this is a %i%c %%o \n";
	//len = ft_printf(s);
	len = ft_strlen(s);
	printf("argcount:%i\t ft_len: %s\n", argCount(s), get_Arg_type('c'));
	return (0);
}
