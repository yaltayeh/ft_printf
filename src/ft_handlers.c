#include "ft_printf.h"

int	ft_char_handle(t_input in, char **out)
{
	char *str;
	if (in.c == '\0')
		return (write(1, "\0", 1));
	str = malloc(1);
	if (str)
		*str = in.c;
	*out = str;
	return (0);
}

int	ft_str_handle(t_input in, char **out)
{
	if (!in.str)
	{
		*out = ft_strdup("(null)");
		return (-1);
	}
	*out = ft_strdup(in.str);
	return (0);
}

int	ft_pointer_handle(t_input in, char **out)
{
	unsigned long	addr;
	char			*hex;

	addr = (unsigned long)in.ptr;
	if (!addr)
	{
		*out = ft_strdup("(nil)");
		return (0);
	}
	hex = ft_itoa_base(addr, HEX_BASE);
	if (!hex)
		return (-1);
	*out = ft_strjoin("0x", hex);
	free(hex);
	return (1);
}
