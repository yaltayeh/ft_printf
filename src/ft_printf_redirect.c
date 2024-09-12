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

static int	ft_printf_redirect2(va_list *ap, char conversions, \
								t_handler_data data)
{
	if (conversions == 'p')
		return (ft_pointer_handle(va_arg(*ap, void *), \
								data.flags, data.numbers));
	else if (conversions == 'd' || conversions == 'i')
		return (ft_decimal_handle(va_arg(*ap, int), \
								data.flags, data.numbers));
	else if (conversions == 'x')
		return (ft_hex_handle(va_arg(*ap, unsigned int), \
								data.flags, data.numbers, 0));
	else if (conversions == 'X')
		return (ft_hex_handle(va_arg(*ap, unsigned int), \
								data.flags, data.numbers, 1));
	else if (conversions == 'u')
		return (ft_u_decimal_handle(va_arg(*ap, unsigned int), \
								data.flags, data.numbers));
	else if (conversions == '%')
		return (ft_percent_handle(data.flags, data.numbers));
	return (ft_main(data));
}

int	ft_printf_redirect(va_list *ap, char conversions, \
						t_flags flags, int *numbers)
{
	t_handler_data	data;

	ft_bzero(&data, sizeof(data));
	ft_memmove(data.numbers, numbers, sizeof(data.numbers));
	data.flags = flags;
	if (conversions == 'c')
		return (ft_char_handle((char)va_arg(*ap, int), data.flags, numbers));
	else if (conversions == 's')
		return (ft_str_handle(va_arg(*ap, char *), data.flags, numbers));
	else if (conversions == 'p')
		return (ft_pointer_handle(va_arg(*ap, void *), \
								data.flags, numbers));
	else if (conversions == 'd' || conversions == 'i')
		return (ft_decimal_handle(va_arg(*ap, int), \
								data.flags, numbers));
	else if (conversions == 'x')
		return (ft_hex_handle(va_arg(*ap, unsigned int), \
								data.flags, numbers, 0));
	else if (conversions == 'X')
		return (ft_hex_handle(va_arg(*ap, unsigned int), \
								data.flags, numbers, 1));
	else if (conversions == 'u')
		return (ft_u_decimal_handle(va_arg(*ap, unsigned int), \
								data.flags, numbers));
	else if (conversions == '%')
		return (ft_percent_handle(data.flags, numbers));
	return (ft_main(data));
}
