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
# define FLAGS_CHARACTERS "# +-.0123456789"
# define HEX_BASE "0123456789abcdef"
# define HEX_UPPER_BASE "0123456789ABCDEF"
# define DECIMAL_BASE "0123456789"

typedef enum	e_flags
{
	NONE = 0,
	HASH = 1 << 0,
	SPACE = 1 << 1,
	PLUS = 1 << 2,
	MINUS = 1 << 3,
	DOT = 1 << 4,
	ZERO = 1 << 5
}	t_flags;

typedef union u_input
{
	char	c;
	char	*str;
	void	*ptr;
	int		i32;
	unsigned int u32;
	unsigned long u64;
}	t_input;

/* %c Prints a single character. */
int	ft_put_char_handle(t_input in, t_flags flags, int number);

/* %s Prints a string (as defined by the common C convention). */
int	ft_put_str_handle(t_input in, t_flags flags, int number);

/* %p The void * pointer argument has to be printed in hexadecimal format. */
int	ft_put_pointer_handle(t_input in, t_flags flags, int number);

/*  %d Prints a decimal (base 10) number.
    %i Prints an integer in base 10.        */
int	ft_put_decimal_handle(t_input in, t_flags flags, int number);

/* %u Prints an unsigned decimal (base 10) number. */
int	ft_put_u_decimal_handle(t_input in, t_flags flags, int number);

/* %x Prints a number in hexadecimal (base 16) lowercase format. */
int	ft_put_hex_lower_handle(t_input in, t_flags flags, int number);

/* %X Prints a number in hexadecimal (base 16) uppercase format. */
int	ft_put_hex_upper_handle(t_input in, t_flags flags, int number);

t_flags	ft_flags_parser(const char **fmt, int *number);

int	ft_printf_redirect(va_list *ap, char conversions, \
				t_flags flags, int number);

int	ft_printf(const char *fmt, ...);

#endif
