#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"

int test(char *str, ...)
{
	va_list ap;


	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'd' || *str == 'i')
				ft_putnbr_fd(va_arg(ap, int), 1);
			else if (*str == 's')
				ft_putstr(va_arg(ap, char *));
			else if (*str == 'c')
				ft_putchar((char)va_arg(ap, int));

		}
		else
			write(1, str, 1);
		str++;
	}
}

int main()
{
	printf("%x\n", 0xff4);
}