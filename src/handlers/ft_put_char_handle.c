#include "ft_printf.h"

int	ft_put_char_handle(char c, int number)
{
	int	count;

	count = 0;
	count += ft_putchar(c);
	while (number && --number)
		count += ft_putchar(' ');
	return (count);
}