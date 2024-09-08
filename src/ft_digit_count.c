#include "ft_printf.h"

size_t	ft_digit_count(int n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
	
}