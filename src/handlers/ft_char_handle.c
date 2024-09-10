#include "ft_printf.h"

int	ft_put_char_handle(t_input in, char **out)
{
	char *str;
	str = malloc(1);
	if (str)
		*str = in.c;
	*out = str;
	return (0);

}