/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_decimal_handle.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:48:08 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/09/08 19:48:41 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_unsigned_decimal_handle(unsigned int n, enum e_flags flags)
{
	int	count;

	count = ft_putbase_fd((unsigned long)n, DECIMAL_BASE, 1);
	return (count);
}
