#include <unistd.h>

void	ft_putnstr(char *s, size_t len)
{
	while (*s && len)
	{
		write(1, &(*s++), 1);
		len--;
	}
}
