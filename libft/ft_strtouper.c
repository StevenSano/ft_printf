
#include "libft.h"

char	*ft_strtouper(char *toup)
{
	int		i;

	i = 0;
	while (*toup)
	{
		if (*toup >= 'a' && *toup <= 'z')
			*toup = ft_toupper(*toup);
		toup++;
		i++;
	}
	return (toup - i);
}
