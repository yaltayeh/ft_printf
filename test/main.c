#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

#define print(x, ...) \
	printf("ft_printf(\"%s\", %s)\n", x, #__VA_ARGS__);\
	a = printf("'"x"'\n", __VA_ARGS__); \
	b = ft_printf("'"x"'\n", __VA_ARGS__); \
	printf("%d == %d\n", a, b);	

#define TEST(i, x)\
	printf("\n%d: ", i);\
	x
	
#define _ft_printf(x, ...) \
	TEST(0, print(x, __VA_ARGS__));


int main()
{
	int a, b;
	_ft_printf("42%53lc42", (char)14);
}

/*
Total     OK: 667  KO: 364
Total     OK: 670  KO: 361
Total     OK: 679  KO: 352
Total     OK: 681  KO: 350
Total     OK: 716  KO: 315

*/

