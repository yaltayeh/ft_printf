#include "ft_printf.h"

int	ft_decimal_handle(t_handler_input in, char **out)
{
	int	num;

	num = in.i32;
	if (num < 0)
		out[1] = ft_strdup("-");
	out[0] = ft_itoa(num, 0);
	return (1);
}

size_t	ft_u_decimal_handle(unsigned int u32, t_flags flags, int *numbers)
{
	char	*decimal;
	size_t	count;
	size_t	len;

	count = 0;
	decimal = ft_itoa_base((unsigned long)u32, DECIMAL_BASE);
	len = ft_strlen(decimal);
	count += len;
	if ((flags & ZERO) && (flags & DOT))
	{
		ft_blank_apply(numbers[5], numbers[4]);
		count += ft_zero_apply(numbers[4], count);
	}
	else if (flags & ZERO)
		count += ft_zero_apply(numbers[5], count);
	else if (flags & DOT)
		count += ft_zero_apply(numbers[4], count);
	ft_putstr(decimal);
	if (flags & MINUS)
		count += ft_blank_apply(numbers[3], count);
	free(decimal);
	return (count);
}

size_t	ft_hex_handle(unsigned int u32, t_flags flags, int *numbers, int upper)
{
	char	*hex;
	size_t	count;
	size_t	len;

	count = 0;
	if (upper)
		hex = ft_itoa_base(u32, HEX_BASE_UPPER);
	else
		hex = ft_itoa_base(u32, HEX_BASE);
	len = ft_strlen(hex);
	count += len;
	count += !!(flags & SHARP) * 2;

	if (flags & ZERO)
		count += ft_zero_apply(numbers[5], count);
	if (flags & DOT)
		count += ft_zero_apply(numbers[4], count);
	if (flags & NUMBER && !(flags & (DOT | ZERO)))
		count += ft_blank_apply(numbers[6], count);
	if (flags & SHARP)
		ft_sharp_apply(upper);
	ft_putstr(hex);
	if (flags & MINUS)
		count += ft_blank_apply(numbers[3], count);
	free(hex);
	return (count);
}

size_t	ft_percent_handle(t_flags flags, int *numbers)
{
	size_t	count;

	count = 0;
	if ((flags & NUMBER) && !(flags & MINUS))
	{
		while (--numbers[6] > 0)
		{
			ft_putchar(' ');
			count++;
		}
	}
	ft_putchar('%');
	count++;
	if (flags & MINUS)
		while (--numbers[3] > 0)
		{
			ft_putchar(' ');
			count++;
		}
	return (count);
}
