/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yaltayeh <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/09/08 19:50:37 by yaltayeh		  #+#	#+#			 */
/*   Updated: 2024/09/08 19:52:35 by yaltayeh         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	enum e_flags	flags;
	va_list			ap;
	int				count;
	int				number;

	va_start(ap, fmt);
	flags = NONE;
	count = 0;
	number = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			flags = ft_flags_parser(&fmt, &number);
			if (ft_strchr(CONVENTIONS_CHARACTERS, *fmt))
				count += ft_printf_redirect(&ap, *fmt, flags, number);
			else
				count += ft_putchar(*fmt);
		}
		else
			count += ft_putchar(*fmt);
		fmt++;
	}
	return (count);
}
