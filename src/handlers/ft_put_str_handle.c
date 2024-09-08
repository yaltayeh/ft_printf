/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str_handle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:43:49 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/09/08 19:47:53 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_str_handle(char *str, enum e_flags flags, int space_count)
{
	int	count;

	count = 0;
	if (!str)
	{
		str = "(null)";
		space_count = 0;
	}
	space_count -= ft_strlen(str);
	while (space_count-- > 0)
		count += ft_putchar(' ');
	count += ft_putstr(str);
	return (count);
}
