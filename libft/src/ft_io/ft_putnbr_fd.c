/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 06:53:34 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/08/27 06:54:14 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	long	num;
	int		len;
	int		ret;

	num = n;
	len = 0;
	if (num < 0)
	{
		ret = ft_putchar_fd('-', fd);
		if (ret < 0)
			return (ret);
		len += ret;
		num *= -1;
	}
	if (num <= 9)
	{
		ret = +ft_putchar_fd(num + '0', fd);
		if (ret < 0)
			return (ret);
	}
	else
	{
		ret = ft_putnbr_fd(num / 10, fd);
		if (ret < 0)
			return (ret);
		ret += ft_putnbr_fd(num % 10, fd);
	}
	len += ret;
	return (len);
}
