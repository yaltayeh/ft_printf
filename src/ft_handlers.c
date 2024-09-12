#include "ft_printf.h"

size_t	ft_char_handle(char c, t_flags flags, int *numbers)
{
	size_t	count;

	count = 0;
	MINUS | NUMBER;
	if (flags & NUMBER)
		count += ft_blank_apply(numbers[5], 1);
	write(1, &c, 1);
	if (flags & MINUS && !(flags & NUMBER))
		count += ft_blank_apply(numbers[3], 1);
	return (count + 1);
}

size_t	ft_str_handle(char *s, t_flags flags, int *numbers)
{
	size_t	count;
	size_t	len;

	count = 0;
	if (!s)
	{
		s = "(null)";

		if (flags & DOT && flags & NUMBER)
			if (numbers[4] > numbers[5])
				numbers[5] = 0;
			else if (numbers[4] < numbers[5])
				numbers[4] = 0;
		if (flags & DOT && flags & MINUS)
			if (numbers[3] > numbers[5])
				numbers[5] = 0;
			else if (numbers[3] < numbers[5])
				numbers[3] = 0;
		//numbers[4] = 0;
	}
	len = ft_strlen(s);
	if (flags & DOT && len > numbers[4])
		len = numbers[4];
	count += len;
	if (flags & (NUMBER | ZERO))
		count += ft_blank_apply(numbers[5], count);
	write(1, s, len);
	if (flags & MINUS)
		count += ft_blank_apply(numbers[3], count);
	return (count);
} 

size_t	ft_pointer_handle(void *ptr, t_flags flags, int *numbers)
{
	unsigned long	addr;
	char			*hex;
	char			*str;
	size_t			len;

	addr = (unsigned long)ptr;
	if (!addr)
	{
		str = "(nil)";
		hex = NULL;
	}
	else 
	{
		hex = ft_itoa_base(addr, HEX_BASE);
		str = ft_strjoin("0x", hex);
		free(hex);
	}
	len = ft_strlen(str);

	ft_putstr(str);
	if (flags & MINUS)
		len += ft_blank_apply(numbers[3], len);
	if (addr)
		free(str);
	return (len);
}
