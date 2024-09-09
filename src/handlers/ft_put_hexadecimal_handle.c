/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexadecimal_handle.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:48:53 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/09/08 19:49:59 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hexadecimal_handle(unsigned long x, int is_lower, \
								enum e_flags flags, int number)
{
	int	count;

	count = 0;
	if (flags & HASH && x)
	{
		if (is_lower)
			count += ft_putstr("0x");
		else
			count += ft_putstr("0X");
	}
	if (is_lower)
		count += ft_putbase_fd(x, HEX_BASE, 1);
	else
		count += ft_putbase_fd(x, HEX_UPPER_BASE, 1);
	if (flags & MINUS)
		while (number > count)
			count += ft_putchar(' ');
	return (count);
}
