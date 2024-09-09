/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 20:02:23 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/09/08 20:03:27 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft.h"
# include <stdio.h>

# define CONVENTIONS_CHARACTERS "cspdiuxX%"
# define FLAGS_CHARACTERS "# +-.0"
# define HEX_BASE "0123456789abcdef"
# define HEX_UPPER_BASE "0123456789ABCDEF"
# define DECIMAL_BASE "0123456789"

enum	e_flags
{
	NONE = 0,
	HASH = 1 << 0,
	SPACE = 1 << 1,
	PLUS = 1 << 2,
	MINUS = 1 << 3,
	DOT = 1 << 4,
	ZERO = 1 << 5
};

/* %c Prints a single character. */

/* %s Prints a string (as defined by the common C convention). */
int	ft_put_str_handle(char *str, enum e_flags flags, int space_count);

/* %p The void * pointer argument has to be printed in hexadecimal format. */
int	ft_put_address_handle(void *ptr, enum e_flags flags);

/*  %d Prints a decimal (base 10) number.
    %i Prints an integer in base 10.        */
int	ft_put_decimal_handle(int n, enum e_flags flags);

/* %u Prints an unsigned decimal (base 10) number. */
int	ft_put_unsigned_decimal_handle(unsigned int n, enum e_flags flags);

/* %x Prints a number in hexadecimal (base 16) lowercase format. */
/* %X Prints a number in hexadecimal (base 16) uppercase format. */
int	ft_put_hexadecimal_handle(unsigned long x, int is_lower, \
			enum e_flags flags);

enum e_flags	ft_flags_format(const char **fmt, int *number);

int	ft_printf_redirect(va_list *ap, char conversions, \
				enum e_flags flags, int number);

int	ft_printf(const char *fmt, ...);

#endif
