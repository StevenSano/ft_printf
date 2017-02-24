#include "libft.h"

static int	nbr_base_len(int nbr, int base)
{
	int len;

	len = 0;
	while (nbr != 0)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

char		*ft_itoa_base(unsigned int nbr, int base)
{
	char	*str;
	char	*tab;
	int		len;
	int		i;

	if (nbr == 0)
		return (ft_strdup("0"));
	tab = ft_strdup("0123456789abcdef");
	len = nbr_base_len(nbr, base);
	str = ft_strnew(nbr);
	i = 1;
	while (nbr != 0)
	{
		str[len - i] = tab[nbr % base];
		nbr /= base;
		i++;
	}
	str[len] = '\0';
	return (str);
}
