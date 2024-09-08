/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_redirect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:54:29 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/09/08 19:55:41 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_redirect(va_list *ap, char conversions, \
				enum e_flags flags, int number)
{
	int	ret;

	ret = 0;
	if (conversions == 'c')
		ret = ft_putchar((char)va_arg(*ap, int));
	else if (conversions == 's')
		ret = ft_put_str_handle(va_arg(*ap, char *), flags, number);
	else if (conversions == 'p')
		ret = ft_put_address_handle(va_arg(*ap, void *), flags);
	else if (conversions == 'd' || conversions == 'i')
		ret = ft_put_decimal_handle(va_arg(*ap, int), flags);
	else if (conversions == 'u')
		ret = ft_put_unsigned_decimal_handle(va_arg(*ap, unsigned int), flags);
	else if (conversions == 'x')
		ret = ft_put_hexadecimal_handle(va_arg(*ap, unsigned int), 1, flags);
	else if (conversions == 'X')
		ret = ft_put_hexadecimal_handle(va_arg(*ap, unsigned int), 0, flags);
	else if (conversions == '%')
		ret = ft_putchar('%');
	return (ret);
}
