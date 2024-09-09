/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_address_handle.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:40:57 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/09/08 19:43:36 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include "ft_printf.h"

int	ft_put_address_handle(void *ptr, enum e_flags flags, int number)
{
	int				count;
	unsigned long	addr;

	count = 0;
	addr = (unsigned long)ptr;
	if (!ptr)
		return (write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	count += ft_putbase_fd(addr, HEX_BASE, 1);
	while (number > count)
		count += ft_putchar(' ');
	
	return (count);
}
