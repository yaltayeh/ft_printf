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

int	ft_put_str_handle(t_input in, char **out)
{
	if (!in.str)
	{
		*out = ft_strdup("(null)");
		return (-1);
	}
	*out = ft_strdup(in.str);
	// number -= ft_strlen(str);
	// if (flags & SPACE)
	// 	while (number-- > 0)
	// 		count += ft_putchar(' ');
	// count += ft_putstr(str);
	// if (flags & MINUS)
	// 	while (number-- > 0)
	// 		count += ft_putchar(' ');
	return (0);
}
