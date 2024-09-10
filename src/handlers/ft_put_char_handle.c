#include "ft_printf.h"

int	ft_put_char_handle(t_input in, t_flags flags, int number)
{
	int	count;
	int	c;

	c = in.c;
	count = 0;
	count += ft_putchar(c);
	
	// flags after
	while (--number > 0)
		count += ft_putchar(' ');
	return (count);

}