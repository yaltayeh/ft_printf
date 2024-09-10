#include "libft.h"
#include "ft_printf.h"
int main()
{
	char *nptr = ft_itoa_base(0, HEX_BASE);
	printf("%s\n", nptr);
	free(nptr);
}
