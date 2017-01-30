#include "src/ft_printf.h"



void test_int(intmax_t imt)
{
	int i, f;
	int hh = (int)imt;
	i = ft_printf("%+i\n", hh);printf("\n|len:%i|\n\n", i);
	f =    printf("%+i\n", hh);printf("\n|len:%i|\n\n", f);
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("To Manny arguments!\n");
		return (0);
	}
	test_int(ft_atoi(av[1]));
	return (0);
}
