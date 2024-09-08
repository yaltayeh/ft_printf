/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yaltayeh <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/08/26 20:46:41 by yaltayeh		  #+#	#+#			 */
/*   Updated: 2024/08/29 11:59:20 by yaltayeh         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

static int	get_digit_count(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	ft_putnbr_str(int n, char *str, int index)
{
	if (n == 1 << 31)
	{
		str[0] = '-';
		str[1] = '2';
		n = 147483648;
	}
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	if (n <= 9)
	{
		str[index] = n + '0';
	}
	else
	{
		ft_putnbr_str(n / 10, str, index - 1);
		ft_putnbr_str(n % 10, str, index);
	}
}

char	*ft_itoa(int n)
{
	int		dcount;
	char	*ret;

	dcount = get_digit_count(n);
	if (n < 0)
		dcount++;
	ret = malloc(dcount + 1);
	if (ret == NULL)
		return (NULL);
	ft_putnbr_str(n, ret, dcount - 1);
	ret[dcount] = '\0';
	return (ret);
}
