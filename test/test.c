// #include "libft.h"
// #include "ft_printf.h"
#include <stdio.h>

void test(void **out)
{
	char	*x;
	char	*y;

	printf("%p,  %p\n", &x, &y);
	out[0] = &x;
	out[1] = &y;
}

int main()
{
	void *out[2];
	test(out);
	printf("%p,  %p\n", out[0], out[1]);
	printf("%zu,  %zu\n", sizeof(out), sizeof(out[0]));
}
