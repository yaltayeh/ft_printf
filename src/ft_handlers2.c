#include "ft_printf.h"

int	ft_decimal_handle(t_input in, char **out)
{
	int	num;

	num = in.i32;
	if (num < 0)
		out[1] = ft_strdup("-");
	out[0] = ft_itoa(num, 0);
	
	return (1);
}

int	ft_u_decimal_handle(t_input in, char **out)
{
	*out = ft_itoa_base((unsigned long)in.u32, DECIMAL_BASE);
	return (0);
}

int	ft_hex_handle(t_input in, char **out)
{
	*out = ft_itoa_base(in.u32, HEX_BASE);
	return (1);
}