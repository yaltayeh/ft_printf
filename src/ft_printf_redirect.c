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

static int	ft_printf_redirect3(va_list *ap, char conversions, \
								t_handler_data data)
{
	if (conversions == 'x')
		return (ft_hex_handle(va_arg(*ap, unsigned int), data.flags, data.numbers, 0));
	else if (conversions == 'X')
		return (ft_hex_handle(va_arg(*ap, unsigned int), data.flags, data.numbers, 1));
	else if (conversions == 'u')
	{
		return (ft_u_decimal_handle(va_arg(*ap, unsigned int), data.flags, data.numbers));
		// data.input.u32 = va_arg(*ap, unsigned int);
		// data.handle = ft_u_decimal_handle;
		// data.is_digit = 1;
		// data.flags &= MINUS | ZERO | DOT;
	}
	else if (conversions == '%')
		return (ft_percent_handle(data.flags, data.numbers));
	else
		return (-1);
	return (ft_main(data));
}

static int	ft_printf_redirect2(va_list *ap, char conversions, \
								t_handler_data data)
{
	if (conversions == 'p')
	{
		data.input.ptr = va_arg(*ap, void *);
		data.handle = ft_pointer_handle;
		data.flags &= MINUS;
	}
	else if (conversions == 'd' || conversions == 'i')
	{
		data.input.i32 = va_arg(*ap, int);
		data.handle = ft_decimal_handle;
		data.is_digit = 1;
		data.flags &= PLUS | MINUS | ZERO | DOT | SPACE | NUMBER;
	}
	else
		return (ft_printf_redirect3(ap, conversions, data));
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
	{
		data.input.c = (char)va_arg(*ap, int);
		data.handle = ft_char_handle;
		data.flags &= MINUS | NUMBER;
		data.is_char = 1;
	}
	else if (conversions == 's')
	{
		data.input.str = va_arg(*ap, char *);
		data.handle = ft_str_handle;
		data.flags &= MINUS | DOT | NUMBER;
	}
	else
		return (ft_printf_redirect2(ap, conversions, data));
	return (ft_main(data));
}
