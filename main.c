#include "includes/ft_printf.h"

double average(int num, ...)
{
	va_list args;
	double sum = 0;

	va_start(args, num); //store all values after num
	for (int x = 0; x < num; x++)
		sum += va_arg(args, int);	//va_arg take a va_list and a variable type and returns nextargument
	va_end(args); //clean up
	return (sum/num);
}

void printstr_(int count, ...)
{
	va_list a_list;
	int		i;

	i = 0;
	va_start(a_list, count);
	while (i < count)
	{
		ft_putendl(va_arg(a_list, char*));
		i++;
	}
	va_end(a_list);
}

int main(void)
{
//	char	*s = "OOOOOOCC####$%^^^^*#@#KKKKK^&^%4343242dd";
//	int		i = 1200100;
//	char	c = '&';
	/*int a = average(2, 10, 10);

	int p = printf(s, a); //11 characters in fotmat string
	printf("%i\n", p);
	printstr_(4, "a0", "a1", "a2", "a3");*/
	//printf("hello: %s\n", "hector");
//	int pf; // printf("lo\t%c\t%i\n", 'x', 1);
//	pf = printf("%s %i %c", s, i, c);
//	printf("\npf len:%i\n", pf);
//	ft_putchar('\n');
	ft_printf("ft format-> char:\n");
	printf("\n\nformat-> char:\n\n");
	return (0);
}
