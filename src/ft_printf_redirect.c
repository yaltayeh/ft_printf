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
						t_flags flags, int number)
{
	int	ret;
	t_input input;
	int (*handle)(t_input, char **);
	int is_upper;

	ret = 0;
	is_upper = 0;
	if (conversions == 'c')
	{
		input.c = (char)va_arg(*ap, int);
		handle = ft_char_handle;
		flags &= MINUS;
	}
	else if (conversions == 's')
	{
		input.str = va_arg(*ap, char *);
		handle = ft_str_handle;
		flags &= MINUS;
	}
	else if (conversions == 'p')
	{
		input.ptr = va_arg(*ap, void *);
		handle = ft_pointer_handle;
		flags &= MINUS;
	}
	else if (conversions == 'd' || conversions == 'i')
	{
		input.i32 = va_arg(*ap, int);
		handle = ft_decimal_handle;
		flags &= PLUS | MINUS | ZERO | DOT | SPACE;
	}
	else if (conversions == 'u')
	{
		input.u32 = va_arg(*ap, unsigned int);
		handle = ft_u_decimal_handle;
		flags &= MINUS | ZERO | DOT;
	}
	else if (conversions == 'x' || conversions == 'X')
	{
		input.u32 = va_arg(*ap, unsigned int);
		handle = ft_hex_handle;
		flags &= SHARP | MINUS | ZERO | DOT;
		is_upper = conversions == 'X';
	}
	else if (conversions == '%')
		return (ft_putchar('%'));

	ret = ft_main(input, flags, number, is_upper, handle);
	return (ret);
}
