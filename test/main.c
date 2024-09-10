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

int main()
{
	int a, b;

	/* Your test cases */
}

