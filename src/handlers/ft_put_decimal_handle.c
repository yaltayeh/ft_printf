/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_decimal_handle.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:41:14 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/09/08 19:42:43 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_decimal_handle(int n, enum e_flags flags)
{
	int	ret;

	ret = 0;
	if (flags & PLUS)
	{
		if (n >= 0)
		{
			ret += write(1, "+", 1);
		}
	}
	else if (flags & SPACE)
	{
		if (n >= 0)
			ret += write(1, " ", 1);
	}
	ret += ft_putnbr_fd(n, 1);
	return (ret);
}
