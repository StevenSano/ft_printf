#include "src/ft_printf.h"



void test_int(intmax_t imt)
{
	//int i, f;
	char *s = "hh: %+010hhi\nh: %+hi\n";
	signed char hh = (signed char)imt;
	short h = (short)imt;
	//long l = (long)imt;
	//long long ll = (long long)imt;
	//size_t z = (size_t)imt;
	int i = ft_printf(s, hh, h);printf("\n|len:%i|\n\n", i);
	int f =    printf(s, hh, h);printf("\n|len:%i|\n\n", f);
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Argument count != 2!\n");
		return (0);
	}
	test_int(ft_atoi(av[1]));
	return (0);
}
