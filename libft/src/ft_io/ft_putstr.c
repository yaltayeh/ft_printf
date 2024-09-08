#include "libft.h"

int ft_putstr(const char *s)
{
    size_t  len;

    len = ft_strlen(s);
    return (write(1, s, len));
}