#include "ft_printf.h"

static void ft_upper(unsigned int i, char *s)
{
	(void)i;
	*s = ft_toupper(*s);
}

int	ft_main(t_input input, t_flags flags, int number, \
			int is_upper, int (*handle)(t_input, char **))
{
	int		count;
	char	*out[2];
	size_t	len0;
	size_t	len1;

	count = 0;
	len0 = 0;
	len1 = 0;
	ft_bzero(out, sizeof(out));

	handle(input, out);
	if (flags & SHARP)
		out[1] = ft_strdup("0x");
	
	if (out[0])
		len0 = ft_strlen(out[0]);
	if (out[1])
		len1 = ft_strlen(out[1]);

	if (out[1])
	{
		if (is_upper)
			ft_striteri(out[1], ft_upper);
		count += ft_putstr(out[1]);
		free(out[1]);
	}

	if (flags & DOT)
		while (number > count + len0 - len1)
			count += ft_putchar('0');
	else if (flags & ZERO)
		while (number > (count + len0))
			count += ft_putchar('0');

	if (flags & PLUS && input.i32 >= 0)
		count += write(1, "+", 1);
	else if (flags & SPACE && input.i32 >= 0)
		count += write(1, " ", 1);
	if (out[0])
	{
		if (is_upper)
			ft_striteri(out[0], ft_upper);
		count += ft_putstr(out[0]);
		free(out[0]);
	}

	
	if (flags & MINUS)
	{
		while (number > count)
			count += ft_putchar(' ');
	}

	return (count);
}