#include "ft_printf.h"

static void	ft_decimal_helper1(int i32, size_t *count, int *numbers)
{
	size_t	blank_count;

	blank_count = ft_blank_apply(numbers[0], numbers[1] + (i32 < 0));
	if (i32 < 0)
		write(1, "-", 1);
	*count += ft_zero_apply(numbers[1], *count);
	*count += i32 < 0;
	*count += blank_count;
}

static size_t	ft_decimal_helper2(int i32, size_t *count, int *numbers, t_flags flags)
{
	size_t	is_blank;

	is_blank = i32 < 0 || (flags & (SPACE | PLUS));
	if (flags & NUMBER)
		*count += ft_blank_apply(numbers[0], *count);
	if (i32 < 0)
		write(1, "-", 1);
	else if (flags & PLUS)
		write(1, "+", 1);
	else if (flags & SPACE)
		write(1, " ", 1);
	if (flags & ZERO)
		*count += ft_zero_apply(numbers[0], *count + is_blank);
	else if (flags & DOT)
		*count += ft_zero_apply(numbers[1], *count);
	*count += is_blank;
}

size_t	ft_decimal_handle(int i32, t_flags flags, int *numbers)
{
	char	*decimal;
	size_t	count;
	size_t	len;
	int		blank_count;

	count = 0;
	decimal = ft_itoa(i32, 0);
	len = ft_strlen(decimal);
	count += len;

	if ((flags & (ZERO | NUMBER)) && (flags & DOT))
	{
		ft_decimal_helper1(i32, &count, numbers);
		flags = NONE;
	}
	else
		ft_decimal_helper2(i32, &count, numbers, flags);
	ft_putstr(decimal);
	if (flags & MINUS)
		count += ft_blank_apply(numbers[3], count);
	free(decimal);
	return (count);
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
	if ((flags & (ZERO | NUMBER)) && (flags & DOT))
	{
		ft_blank_apply(numbers[5], numbers[4]);
		count += ft_zero_apply(numbers[4], count);
	}
	else if (flags & ZERO)
		count += ft_zero_apply(numbers[5], count);
	else if (flags & DOT)
		count += ft_zero_apply(numbers[4], count);
	else if (flags & NUMBER)
		count += ft_blank_apply(numbers[5], count);
	ft_putstr(decimal);
	if (flags & MINUS)
		count += ft_blank_apply(numbers[3], count);
	free(decimal);
	return (count);
}

static void	ft_hex_helper(unsigned int u32, size_t *count, \
							int *numbers, t_flags flags)
{
	if (flags & ZERO)
		*count += ft_zero_apply(numbers[0], *count);
	if (flags & DOT)
		*count += ft_zero_apply(numbers[1], *count);
	if (flags & SHARP && u32)
		*count += 2;
	if (flags & NUMBER && !(flags & (DOT | ZERO)))
		*count += ft_blank_apply(numbers[0], *count);
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
	ft_hex_helper(u32, &count, numbers, flags);
	if (flags & SHARP && u32)
		ft_sharp_apply(upper);
	ft_putstr(hex);
	if (flags & MINUS)
		count += ft_blank_apply(numbers[0], count);
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
	// if (flags & MINUS)
	// 	while (--numbers[3] > 0)
	// 	{
	// 		ft_putchar(' ');
	// 		count++;
	// 	}
	return (count);
}
