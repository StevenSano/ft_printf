#include "includes/ft_printf.h"

double average(int num, ...)
{
	va_list args;
	double sum = 0;
	
	va_start(args, num); //store all values after num
	for (int x = 0; x < num; x++)
		sum += va_arg(args, int);
	va_end(args);
	return (sum/num);
}


int main(void)
{

	int a = average(3, 10, 10, 10);

	printf("%i\n", a);
	//printf("hello: %s\n", "hector");
	return (0);
}
