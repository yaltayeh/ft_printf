#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>

#define CONVENTIONS_CHARACTERS "cspdiuxX%"
#define HEX_BASE "0123456789abcdef"
#define HEX_UPPER_BASE "0123456789ABCDEF"
#define DECIMAL_BASE "0123456789"

/* %c Prints a single character. */
/* %s Prints a string (as defined by the common C convention). */
int	ft_put_str(char *str, enum e_flags flags)
{
	int	ret;
	int	count;

	count = 0;
	ret = ft_putstr(str);
	if (ret < 0)
		return (ret);
	count += ret;
	return (count);
}

/* %p The void * pointer argument has to be printed in hexadecimal format. */
int ft_put_address(void *ptr, enum e_flags flags)
{
	int	ret;
	int	count;
	unsigned long addr;

	count = 0;
	addr = (unsigned long)ptr;
	ret = write(1, "0x", 2);
	if (ret < 0)
		return (ret);
	count += ret;
	ret = ft_putbase_fd(addr, HEX_BASE, 1);
	if (ret < 0)
		return (ret);
	count += ret;
	return (count);
}

/*  %d Prints a decimal (base 10) number.
    %i Prints an integer in base 10.        */
int ft_put_decimal(int n, enum e_flags flags) // %i %d
{
	int	ret;

	ret = 0;
	ret = ft_putnbr_fd(n, 1);
	return (ret);
}

/* %u Prints an unsigned decimal (base 10) number. */
int ft_put_unsigned_decimal(unsigned int n, enum e_flags flags)
{
	int	ret;
	ret = 0;
	ret = ft_putbase_fd((unsigned long)n, DECIMAL_BASE, 1);
	return (ret);
}

/* %x Prints a number in hexadecimal (base 16) lowercase format. */
/* %X Prints a number in hexadecimal (base 16) uppercase format. */
int ft_put_hexadecimal(unsigned int x, int is_lower, enum e_flags flags)
{
	int	ret;

	ret = 0;
	if (flags & HASH)
	{
		if (is_lower)
			ret += ft_putstr("0x");
		else
			ret += ft_putstr("0X");
	}
	if (is_lower)
		ret += ft_putbase_fd(x, HEX_BASE, 1);
	else 
		ret += ft_putbase_fd(x, HEX_UPPER_BASE, 1);
	return (ret);
}

int ft_printf_redirect(va_list *ap, char conversions, enum e_flags flags)
{
    int	ret;

	ret = 0;
    if (conversions == 'c')
        ret = ft_putchar((char)va_arg(*ap, int));
    else if (conversions == 's')
        ret = ft_putstr(va_arg(*ap, char *));
    else if (conversions == 'p')
        ret = ft_put_address(va_arg(*ap, void *), flags);
    else if (conversions == 'd' || conversions == 'i')
        ret = ft_put_decimal(va_arg(*ap, int), flags);
	else if (conversions == 'u')
		ret = ft_put_unsigned_decimal(va_arg(*ap, unsigned int), flags);
	else if (conversions == 'x')
		ret = ft_put_hexadecimal(va_arg(*ap, unsigned long), 1, flags);
	else if (conversions == 'X')
		ret = ft_put_hexadecimal(va_arg(*ap, unsigned long), 0, flags);
	else if (conversions == '%')
		ret = ft_putchar('%');
	return (ret);
}

enum e_flags ft_flags_format(const char **fmt, int *number)
{
	char flags_character[7];
	char	*flag;
	enum e_flags flags;

	flags = NONE;
	ft_strlcpy(flags_character, "# +-0.", -1);
	flag = ft_strchr(flags_character, **fmt);
	while (flag)
	{
		*fmt = *fmt + 1;
		if (*flag == '0' || *flag == '.')
			*number = ft_atoi_track(fmt);
		flags |= (1 << (flag - flags_character));
		flag = ft_strchr(flags_character, **fmt);
	}
	return (flags);
}

int ft_printf(const char *fmt, ...)
{
    enum e_flags flags;
	int number;
	va_list ap;
	int	count;

	va_start(ap, fmt);
    flags = NONE;
	count = 0;
    while (*fmt)
    {
        if (*fmt == '%')
        {
            fmt++;
			printf("before flags %s\n", fmt);
			flags = ft_flags_format(&fmt, &number);
			printf("after flags %s\n", fmt);
			printf("data: %d\n", number);
			if (ft_strchr(CONVENTIONS_CHARACTERS, *fmt))
				count += ft_printf_redirect(&ap, *fmt, flags);
			else
				write(1, "E", 1); // error
        }
		else
			count += ft_putchar(*fmt);
        fmt++;
    }
	return (count);
}
