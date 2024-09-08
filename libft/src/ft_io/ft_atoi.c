/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yaltayeh <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/08/26 20:54:35 by yaltayeh		  #+#	#+#			 */
/*   Updated: 2024/08/27 08:45:23 by yaltayeh         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\r' \
		|| c == '\n' || c == '\v' || c == '\f');
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	ret;

	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
	{
		sign = 1;
		nptr++;
	}
	else
		sign = 1;
	ret = 0;
	while (ft_isdigit(*nptr))
	{
		ret = ret * 10 + *nptr - '0';
		nptr++;
	}
	return (ret * sign);
}

int	ft_atoi_track(const char **p_nptr)
{
	const char *nptr;
	int	sign;
	int	ret;

	nptr = *p_nptr;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
	{
		sign = 1;
		nptr++;
	}
	else
		sign = 1;
	ret = 0;
	while (ft_isdigit(*nptr))
	{
		ret = ret * 10 + *nptr - '0';
		nptr++;
	}
	*p_nptr = nptr;
	return (ret * sign);
}
