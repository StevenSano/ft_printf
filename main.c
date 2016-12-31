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


int main(void)
{

	int a = average(2, 10, 10);

	int p = printf("average:%i\n", a); //11 characters in fotmat string
	printf("%i\n", p);
	//printf("hello: %s\n", "hector");
	return (0);
}
