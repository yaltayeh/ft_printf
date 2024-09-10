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

int	ft_put_decimal_handle(t_input in, char **out)
{
	int	ret;
	int	num;

	ret = 0;
	num = in.i32;
	if (num < 0)
		ret = write(1, '-', 1);
	*out = ft_itoa(num, 0);
	
	return (ret);
}
