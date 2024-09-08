#include "libft.h"

int	ft_putbase_fd(unsigned long n, char	*base_symbol, int fd)
{
	int		len;
	int		ret;
	size_t	base_len;

	base_len = ft_strlen(base_symbol);
	len = 0;
	if (n < base_len)
	{
		ret = ft_putchar_fd(base_symbol[n], fd);
		if (ret < 0)
			return (ret);
	}
	else
	{
		ret = ft_putbase_fd(n / base_len, base_symbol, fd);
		if (ret < 0)
			return (ret);
		ret += ft_putbase_fd(n % base_len, base_symbol, fd);
	}
	len += ret;
	return (len);
}
