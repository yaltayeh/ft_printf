/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 00:25:28 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/09/14 00:26:18 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_decimal_helper1(int i32, size_t *count, int *numbers)
{
	size_t	blank_count;

	blank_count = ft_blank_apply(numbers[0], numbers[1] + (i32 < 0));
	if (i32 < 0)
		write(1, "-", 1);
	*count += ft_zero_apply(numbers[1], *count);
	*count += i32 < 0;
	*count += blank_count;
}

static void	ft_decimal_helper2(int i32, size_t *count, \
								int *numbers, t_flags flags)
{
	size_t	is_blank;

	is_blank = 0;
	if (i32 < 0 || (flags & (SPACE | PLUS)))
		is_blank = 1;
	if (flags & NUMBER)
		*count += ft_blank_apply(numbers[0], *count);
	if (i32 < 0)
		write(1, "-", 1);
	else if (flags & PLUS)
		write(1, "+", 1);
	else if (flags & SPACE)
		write(1, " ", 1);
	if (flags & ZERO)
		*count += ft_zero_apply(numbers[0], *count + is_blank);
	else if (flags & DOT)
		*count += ft_zero_apply(numbers[1], *count);
	*count += is_blank;
}

size_t	ft_decimal_handle(int i32, t_flags flags, int *numbers)
{
	char	*decimal;
	size_t	count;
	size_t	len;
	int		blank_count;

	count = 0;
	decimal = ft_itoa(i32, 0);
	len = ft_strlen(decimal);
	count += len;
	if ((flags & (ZERO | NUMBER)) && (flags & DOT))
	{
		ft_decimal_helper1(i32, &count, numbers);
		flags = NONE;
	}
	else
		ft_decimal_helper2(i32, &count, numbers, flags);
	ft_putstr(decimal);
	if (flags & MINUS)
		count += ft_blank_apply(numbers[0], count);
	free(decimal);
	return (count);
}
