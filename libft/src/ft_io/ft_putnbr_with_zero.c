#include "libft.h"


int	ft_putnbr_with_zero(int n, int zero_count)
{
	char	digits[10];
	int		i;
	int		count;
	long	num;

	ft_bzero(digits, sizeof(digits));
	num = n;
	count = 0;
	i = 0;
	if (num < 0)
	{
		count += ft_putchar('-');
		num *= -1;
	}
	if (num == 0)
		count += ft_putchar('0');
	while (num)
	{
		digits[i++] = '0' + (num % 10);
		num /= 10;
	}
	zero_count -= (i + count);
	while (zero_count-- > 0)
		count += ft_putchar('0');
	while (i--)
		count += ft_putchar(digits[i]);
	return (count);
}


int	ft_putnbr_with_zero2(int n, int zero_count)
{
    long	num;
	size_t	count;

	num = n;
	count = 0;
	if (num < 0)
	{
		count += ft_putchar('-');
		num *= -1;
		zero_count--;
	}
	if (num <= 9)
	{
		count += ft_putchar(num + '0');
	}
	else
	{
		if (num / 10 < 10)
		{
			zero_count--;
			while (--zero_count > 0)
				count += ft_putchar('0');
		}
		count += ft_putnbr_with_zero(num / 10, zero_count - 1);
		count += ft_putnbr_with_zero(num % 10, 0);
	}
	return (count);
}
