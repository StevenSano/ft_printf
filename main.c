#include "inc/ft_printf.h"



#include <stdio.h>

void check_exit(char *s)
{
	puts(s);
	exit(3);

}

void test_id(char *s, intmax_t m)
{
	int i = ft_printf(s, m, m, m, m, m, m, m, m, m, m, m, m);
	int f =    printf(s, m, m, m, m, m, m, m, m, m, m, m, m);
	printf("|len:%i|\t|len:%i|\n", i, f);
	puts("\nNEGETIVE TEST\n");
	m *= -1;
	pid_t frk = fork();
	if (frk > 0 )
	{
		i = ft_printf(s, m, m, m, m, m, m, m, m, m, m, m, m);
		f =    printf(s, m, m, m, m, m, m, m, m, m, m, m, m);
		printf("|len:%i|\t|len:%i|\n", i, f);
	}
}


int main(void)
{
	char *s;
	intmax_t m;// = 9223372036854775807;
	//****wrong cases
	//s = "%29ji\n";
	//s = "%-30ji\n";
	//s = "%030ji\n";
	//s = "%+030ji\n";
	//s = "%+30ji\n";
	//s = "1.%+3.5ji\n";
	//s = "1.%+6.5ji\n";
	//s = "1.%+05.4ji\n2.%+05ji\n3.%+03.5ji\n";
	//s = "1.%+-1ji\n2.%-5ji\n3.%+05ji\n4.%-+05ji\n";//
	//s = "%+-30ji\n";
	//s = "%-+030ji\n";
	//s = "%+-30.29ji\n";
	//s = "%-+22.22ji\n";
	//s = "%+-ji\n";
	//s = "%i\n%i\n%i\n";//%lli\n%lli\n";
	//s = "1.%+-4.2i\n";
	//s = "1.%+-05.1ji\n2.%-+ji\n3.%-+ji\n";
	//s = "**%lli**\t**%-i**\t**%+i**\t**%0hhi**\t**%0-+i**\t**%-+ji**\t**%0+lli**\t**%0-i**\n";
	//s = "1.%-+0i\n2.%-5ji\n3.%+05ji\n
	//s = "4.%20i**\n";	//error on: m = -1233;
	//s = "5.%-20i**\n";	//error on: m = -1233;
	//s = "6.%+-11.10i**";
	//s = "**%7i**\n";

	//***pass cases
	s = "**%lli**\t**%li**\t**%+-0ji**\n";
	s = "**%010i**\n";
	s = "**%0-hhi**\n";
	m = 130;
	test_id(s, m);
	return (0);
}
