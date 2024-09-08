#include "libft.h"
#include "ft_printf.h"
#include <limits.h>

#define CASE "% 4s", "te"
#define TEST "\n"CASE

int main()
{
	int a = ft_printf(TEST);
	int b = printf   (TEST);
	ft_printf("\n%d == %d\n", a, b);
}