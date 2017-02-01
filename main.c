#include "src/ft_printf.h"



void test_int(intmax_t imt)
{
	//int i, f;
	char *s = "j: %ji\n";
	intmax_t hh;
	hh = imt;
	//long l = (long)imt;
	//long long ll = (long long)imt;
	//size_t z = (size_t)imt;
	int i = ft_printf(s, hh);printf("\n|len:%i|\n\n", i);
	int f =    printf(s, hh);printf("\n|len:%i|\n\n", f);
}

#include <stdio.h>/*
int main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Argument count != 2!\n");
		return (0);
	}

	test_int((intmax_t)atoi(av[1]));
	return (0);
}*/

int main(void)
{
	intmax_t i = -128;
	ft_printf("%hhi\n", (signed char)i);
	   printf("%hhi\n", (signed char)i);

	//test_int(i);
	return (0);
}
