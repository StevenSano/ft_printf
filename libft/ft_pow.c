#include "libft.h"

int ft_pow(int nb, int pow)
{
	return (pow == 0 ? 1 : nb * ft_pow(nb, pow - 1));
}
